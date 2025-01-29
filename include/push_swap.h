/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:59:49 by ehosta            #+#    #+#             */
/*   Updated: 2025/01/29 17:24:55 by ehosta           ###   ########.fr       */
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
	int				size;
	int				head;
	int				*tab;
	char			identifier;
	struct s_stack	*next;
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

	t_bool			is_in_stackmem;
	t_wall_status	wall_status;

	t_env			*env;
}	t_push_swap;

typedef int (*t_algos_list[ALGOS_NUMBER][ALGOS_PART])(t_env *, int);

//	WALL	////////////////////////////////////////////////////////////////////

t_wall_status	check_argv(t_push_swap *p);

//	MOVES	////////////////////////////////////////////////////////////////////

int		extract_from_stack(int *tab, int *head, int *size);
void	push_to_stack(int *tab, int head, int *size, int elt);
void	push(t_env *env, char c, int to_print);
void	reverse_rotate(t_env *env, char c, int to_print);
void	rotate(t_env *env, char c, int to_print);
void	swap(t_env *env, char c, int to_print);

//	INIT	////////////////////////////////////////////////////////////////////

t_env	*create_env(void);
t_push_swap	*create_push_swap(int argc, char **argv);

#endif