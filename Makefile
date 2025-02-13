# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/15 18:04:28 by ehosta            #+#    #+#              #
#    Updated: 2025/02/13 20:36:08 by ehosta           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

MAKE_DIR	:=	.make/
override	BUILD_DIR	:=	$(MAKE_DIR)$(shell git branch --show-current)/
override	SRC_DIR		:=	src/
override	SRCS		:=	main output instructions terminate wall sort_big \
							sort_n_elements sort_functions
override	SRC			:=	$(addprefix $(SRC_DIR),$(addsuffix .c,$(SRCS)))
override	OBJ			:=	$(patsubst $(SRC_DIR)%.c,$(BUILD_DIR)%.o,$(SRC))
override	DEPS		:=	$(patsubst %.o,%.d,$(OBJ))
override	DIRS		:=	$(sort $(dir $(NAME) $(OBJ) $(DEPS)))

override	LIBFT		:=	libft/

OFLAGS		:=	-O3
CFLAGS		:=	-Wall -Wextra -Werror -Ofast -MMD -MP
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

.PHONY: fclean
fclean:
	make -C $(LIBFT) fclean
	$(RM) $(RMFLAGS) $(NAME) $(MAKE_DIR)

.PHONY : re
re: fclean
	$(MAKE)

$(DIRS):
	@mkdir -p $@

.PHONY : norm
norm:
	norminette $(SRC_DIR) include/ libft/

.PHONY : compile
compile:
	$(MAKE) all
	@$(MAKE) clean

-include $(DEPS)