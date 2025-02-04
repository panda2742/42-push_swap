/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:59:49 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/04 17:26:11 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"

# define SPACES "                                                              "

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef enum e_stack_food_type
{
	int_stack, string_stack
}	t_stack_food_type;

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
	t_stack	**stacks;
}	t_env;

typedef struct s_push_swap
{
	int				argc;
	char			**argv;

	t_bool			is_in_stackmem;
	t_wall_status	wall_status;

	t_env			*env;
}	t_push_swap;

typedef struct	s_bucket
{
	int				*composition;
	int				size;
	int				moves;
	struct s_bucket	*next;
}	t_bucket;

typedef struct	s_stack_buckets
{
	t_bucket	**buckets;
	int			total_moves;
}	t_stack_buckets;

//	WALL	////////////////////////////////////////////////////////////////////

t_wall_status	check_argv(t_push_swap *p);

//	MOVES	////////////////////////////////////////////////////////////////////

void	push(t_stack *s1, t_stack *s2, t_bool print_move);
void	reverse_rotate(t_stack *s1, t_stack *s2, t_bool print_move);
void	rotate(t_stack *s1, t_stack *s2, t_bool print_move);
void	swap(t_stack *s1, t_stack *s2, t_bool print_move);

//	INIT	////////////////////////////////////////////////////////////////////

t_env		*create_env(void);
t_push_swap	*create_push_swap(int argc, char **argv);
t_stack		*create_stack(int size, char identifier);
t_stack		*feed_stack(t_stack *stack, t_stack_food_type type, void *content, int size);
t_stack		*sort_and_replace_by_index(t_stack *dest, t_stack *src, int size);
void		selection_sort(int *list, int length);
int			getpos(t_stack *s, int value);
int			getval(t_stack *s, int pos, int offset);
int			is_sorted(t_env *env);
t_stack		*get_stack_by_id(t_env *env, char identifier);

int			sort_2(t_stack *s1, t_bool emulation);
int			sort_3(t_stack *s1, t_bool emulation);

t_env		*create_emulation(t_env *env);
int			bucket_sort(t_push_swap *p);

void		display_stack(t_stack *s, int indents, t_bool is_first);
void		display_env(t_env *e, int indents, t_bool is_first);
void		display_push_swap(t_push_swap *p);
void		display_stack_bucket(t_stack_buckets *sb);

int			*get_bucket_composition(t_stack *s, int bucket_offset, int bucket_size, int *pushed);
void		end_everything(t_push_swap *p, t_bool exit_program, int exit_status);

t_stack_buckets	*create_stack_buckets(void);
t_stack_buckets	*calc_bucket_sort(t_stack_buckets *sb, t_push_swap *p, int buckets);
t_bucket		*append_bucket(t_stack_buckets *parent, int *composition, int size);
void			empty_stack_buckets(t_stack_buckets *sb);

#endif