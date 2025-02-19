/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 10:40:02 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/19 16:03:15 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

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
}	t_push_swap;

void			swap(t_array *arr1, t_array *arr2);
void			rotate(t_array *arr1, t_array *arr2);
void			reverse_rotate(t_array *arr1, t_array *arr2);
void			push(t_array *arr1, t_array *arr2);

t_bool			valid_swap(t_push_swap *p, const char *instr_name);
t_bool			valid_rotate(t_push_swap *p, const char *instr_name);
t_bool			valid_reverse_rotate(t_push_swap *p, const char *instr_name);
t_bool			valid_push(t_push_swap *p, const char *instr_name);

void			terminate(t_push_swap *p, t_bool exit_program, int exit_status);
t_wall_status	wall(t_push_swap *p);

#endif