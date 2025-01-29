/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:59:49 by ehosta            #+#    #+#             */
/*   Updated: 2025/01/29 16:41:09 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"

# define ALGOS_NUMBER 1
# define ALGOS_PART 5

typedef enum	e_bool
{
	false, true
}	t_bool;

typedef enum e_wall_status
{
	WALL_ERROR = 0,
	WALL_AVOID = 1,
	WALL_OK = 2,
}	t_wall_status;

typedef struct	s_stack
{
	int		size;
	int		head;
	int		*tab;
	char	identifier;
}	t_stack;

typedef struct	s_env
{
	int		stack_size;
	char	**stack_str;
	t_bool	is_copy;
	t_stack	*stacks;
}	t_env;

typedef struct s_push_swap
{
	int				argc;
	char			**argv;

	int				is_in_stackmem;
	t_wall_status	wall_status;

	char			**stack_str;
	int				stack_size;

	t_stack			*stacks;
}	t_push_swap;

typedef int (*t_algos_list[ALGOS_NUMBER][ALGOS_PART])(t_env *, int);

//	WALL	////////////////////////////////////////////////////////////////////

t_wall_status	check_argv(t_env *env);

//	MOVES	////////////////////////////////////////////////////////////////////

int		extract_from_stack(int *tab, int *head, int *size);
void	push_to_stack(int *tab, int head, int *size, int elt);
void	push(t_env *env, char c, int to_print);
void	reverse_rotate(t_env *env, char c, int to_print);
void	rotate(t_env *env, char c, int to_print);
void	swap(t_env *env, char c, int to_print);

//	STACK	////////////////////////////////////////////////////////////////////

int		*init_stack(t_env *env, int is_empty);
int		*dup_stack(int *stack, int stack_size);
void	free_stack_str(char **stack_str, int size);
int		distance_to_pos(int size, int cur_pos, int pos);
int		getval(int *stack, int pos, int size, int offset);
int		getpos(int *stack, int value, int size);
int		*copy_stack_a(t_env *env, t_env *em_env);
int		*copy_stack_b(t_env *env, t_env *em_env);
int		*copy_stack_s(t_env *env, t_env *em_env);
void	free_copied_env(t_env *em_env);
t_env	*create_emulation(t_env *env);
t_env	*reset_em_env(t_env *env, t_env *em_env);

//	SORTING	////////////////////////////////////////////////////////////////////

void	selection_sort(int *list, int length);
void	mirror_selection_sort(int *list, int length, int *pair);
void	sort(t_env *env);
int		is_sorted(t_env *env);
void	cheapest_moves(t_env *env);

//////	ALGOS	////////////////////////////////////////////////////////////////

int		sort_2(t_env *env, int emulation);
int		sort_3(t_env *env, int emulation);
int		bucket_sorting(t_env *env, int emulation);
int		*get_bucket_composition(t_env *env, int offset, int elt_per_bucket, int *pushed);
int		execute_bucket_distances(t_env *env, int *distances, int bucket_size, int emulation);

#endif