/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:59:49 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/13 21:07:38 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"

# ifndef DEBUG
#  define DEBUG false
# endif

typedef enum e_move_id
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
}			t_move_id;

typedef struct s_instruction
{
	t_move_id				move_id;
	struct s_instruction	*next;
}					t_instruction;

typedef enum e_wall_status
{
	WALL_ERROR = 0,
	WALL_AVOID = 1,
	WALL_OK = 2,
}	t_wall_status;

typedef struct s_push_swap
{
	int				argc;
	char			**argv;

	t_bool			is_in_stackmem;
	t_wall_status	wall_status;

	int				stack_size;
	char			**stack_str;
	t_array			*a;
	t_array			*b;
	t_array			*c;
	t_instruction	**instructions;
}	t_push_swap;

typedef struct s_instropt
{
	int	ma;
	int	mb;
}		t_instropt;

void			read_moves_flow(t_push_swap *p);
char			*move_str(t_move_id move_id);

void			swap(
					t_push_swap *p,
					t_array *arr1,
					t_array *arr2,
					t_bool addinstr);
void			rotate(
					t_push_swap *p,
					t_array *arr1,
					t_array *arr2,
					t_bool addinstr);
void			reverse_rotate(
					t_push_swap *p,
					t_array *arr1,
					t_array *arr2,
					t_bool addinstr);
void			push(t_push_swap *p, t_array *arr1, t_array *arr2);

void			sort_2(t_push_swap *p, t_array *src);
void			sort_3(t_push_swap *p, t_array *src);
void			sort_5(t_push_swap *p, t_array *src, t_array *dest);
void			sort_big(t_push_swap *p);

void			terminate(t_push_swap *p, t_bool exit_program, int exit_status);
t_wall_status	wall(t_push_swap *p);
t_instruction	*create_instr(t_push_swap *p, t_move_id move_id);

int				cost_to_move(t_array *src, t_array *dest, int val);
int				cost_bring_to_top(t_array *arr, int val);
int				correct_head(t_array *arr, int val);
int				cost_to_correct_pos(t_array *arr, int val);
void			jump_to_val(t_push_swap *p, t_array *arr, int val);

#endif