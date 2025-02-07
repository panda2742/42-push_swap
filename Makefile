# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/15 18:04:28 by ehosta            #+#    #+#              #
#    Updated: 2025/02/07 13:27:10 by ehosta           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

MAKE_DIR	:=	.make/
override	BUILD_DIR	:=	$(MAKE_DIR)$(shell git branch --show-current)/
override	SRC_DIR		:=	src/
override	SRC_ENV		:=	env_manager stack_getter stack_manager
override	SRC_MOVES	:=	moves_flow moves_manager push reverse_rotate rotate swap
override	SRC_MT		:=	big_bang big_rip
override	SRC_SORTING	:=	bucket_manager bucket_sort_utils bucket_sort \
							utils/is_sorted utils/selection_sort \
							utils/sort_n_elements
override	SRC_WALL	:=	check_argv
override	SRCS		:=	$(addprefix env/,$(SRC_ENV)) \
							$(addprefix moves/,$(SRC_MOVES)) \
							$(addprefix multiverse_theory/,$(SRC_MT)) \
							$(addprefix sorting/,$(SRC_SORTING)) \
							$(addprefix wall/,$(SRC_WALL)) \
							debug main
override	SRC			:=	$(addprefix $(SRC_DIR),$(addsuffix .c,$(SRCS)))
override	OBJ			:=	$(patsubst $(SRC_DIR)%.c,$(BUILD_DIR)%.o,$(SRC))
override	DEPS		:=	$(patsubst %.o,%.d,$(OBJ))
override	DIRS		:=	$(sort $(dir $(NAME) $(OBJ) $(DEPS)))

override	LIBFT		:=	libft/

OFLAGS		:=	-O3
CFLAGS		:=	-Wall -Wextra -Werror -g3 -MMD -MP
MAKEFLAGS	:=	--no-print-directory
RMFLAGS		:=	-rf
override	GCC		:=	cc
override	RM		:=	rm

override	_END		:=	\033[0;0m
override	_RED		:=	\033[0;31m

.PHONY: all
all: $(NAME)

$(NAME): $(LIBFT)libft.a $(OBJ) include/push_swap.h Makefile
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT)libft.a -o $(NAME)

$(LIBFT)libft.a:
	make -C $(LIBFT) all

$(BUILD_DIR)%.o: $(SRC_DIR)%.c | $(DIRS)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	make -C $(LIBFT) clean
	$(RM) $(RMFLAGS) $(BUILD_DIR)
	@echo "$(_RED)× Removed the build files.$(_END)"

.PHONY: fclean
fclean:
	make -C $(LIBFT) fclean
	$(RM) $(RMFLAGS) $(NAME) $(MAKE_DIR)
	@echo "$(_RED)× Removed the project.$(_END)"

.PHONY : re
re: fclean
	$(MAKE)

$(DIRS):
	@mkdir -p $@

.PHONY : norm
norm:
	norminette $(SRC_DIR) include/

-include $(DEPS)