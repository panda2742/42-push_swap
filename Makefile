# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/15 18:04:28 by ehosta            #+#    #+#              #
#    Updated: 2025/02/20 11:40:14 by ehosta           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				:=	push_swap
NAME_BONUS			:=	checker
MAKE_DIR			:=	.make/
override	DEPS	:=	$(patsubst %.o,%.d,$(OBJ))
override	LIBFT	:=	libft/

override	BUILD_DIR	:=	$(MAKE_DIR)$(shell git branch --show-current)_push_swap/
override	SRC_DIR		:=	src/
override	SRCS		:=	main output instructions terminate wall sort_big \
							sort_n_elements sort_functions
override	SRC			:=	$(addprefix $(SRC_DIR),$(addsuffix .c,$(SRCS)))
override	OBJ			:=	$(patsubst $(SRC_DIR)%.c,$(BUILD_DIR)%.o,$(SRC))

override	BUILD_DIR_BONUS	:=	$(MAKE_DIR)$(shell git branch --show-current)_checker/
override	SRC_DIR_BONUS	:=	src_bonus/
override	SRCS_BONUS		:=	exec_instruction main instructions terminate wall
override	SRC_BONUS		:=	$(addprefix $(SRC_DIR_BONUS),$(addsuffix .c,$(SRCS_BONUS)))
override	OBJ_BONUS		:=	$(patsubst $(SRC_DIR_BONUS)%.c,$(BUILD_DIR_BONUS)%.o,$(SRC_BONUS))

override	DIRS	:=	$(sort $(dir $(NAME) $(NAME_BONUS) $(OBJ) $(OBJ_BONUS) $(DEPS)))

CFLAGS		:=	-Wall -Wextra -Werror -MMD -MP
MAKEFLAGS	:=	--no-print-directory
RMFLAGS		:=	-rf
override	GCC		:=	cc
override	RM		:=	rm

override	_END	:=	\033[0;0m
override	_RED	:=	\033[0;31m

.PHONY: all
all:	$(NAME)

$(NAME): $(LIBFT)libft.a $(OBJ) include/push_swap.h Makefile
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT)libft.a -o $(NAME)

$(BUILD_DIR)%.o: $(SRC_DIR)%.c | $(DIRS)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: bonus
bonus: $(LIBFT)libft.a $(OBJ_BONUS) include/push_swap_bonus.h Makefile
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT)libft.a -o $(NAME_BONUS)

$(BUILD_DIR_BONUS)%.o: $(SRC_DIR_BONUS)%.c | $(DIRS)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT)libft.a:
	make -C $(LIBFT) all

.PHONY: clean
clean:
	make -C $(LIBFT) clean
	$(RM) $(RMFLAGS) $(BUILD_DIR) $(BUILD_DIR_BONUS)

.PHONY: fclean
fclean:	clean
	make -C $(LIBFT) fclean
	$(RM) $(RMFLAGS) $(NAME) $(NAME_BONUS) $(MAKE_DIR)

.PHONY: re
re:		fclean
	$(MAKE)

$(DIRS):
	@mkdir -p $@

.PHONY: norm
norm:
	norminette $(SRC_DIR) $(SRC_DIR_BONUS) include/ libft/

.PHONY: compile
compile:
	$(MAKE) all
	@$(MAKE) clean

-include $(DEPS)