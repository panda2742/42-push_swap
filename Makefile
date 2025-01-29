# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/15 18:04:28 by ehosta            #+#    #+#              #
#    Updated: 2025/01/29 16:41:16 by ehosta           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

MAKE_DIR	:=	.make/
override	BUILD_DIR	:=	$(MAKE_DIR)$(shell git branch --show-current)/
override	SRC_DIR		:=	src/
override	SRC_MOVES	:=	extract_from_stack push_to_stack push \
							reverse_rotate rotate swap
override	SRC_SORTING	:=	algos/bucket_sorting_utils algos/bucket_sorting \
							algos/sort_n_elements cheapest_moves is_sorted \
							selection_sort sort
override	SRC_STACK	:=	copy_stack stack_getter stack_manager
override	SRC_WALL	:=	check_argv
override	SRCS		:=	$(addprefix moves/,$(SRC_MOVES)) \
							$(addprefix sorting/,$(SRC_SORTING)) \
							$(addprefix stack/,$(SRC_STACK)) \
							$(addprefix wall/,$(SRC_WALL)) \
							main
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

-include $(DEPS)