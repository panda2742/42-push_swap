/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:59:49 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/07 15:27:28 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"

# define SPACES "                                                              "

# ifndef DEBUG
#  define DEBUG 1
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

typedef struct s_move
{
	t_move_id		move;
	struct s_move	*next;
}					t_move;

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef enum e_stack_food_type
{
	int_stack,
	string_stack
}	t_stack_food_type;

typedef enum e_wall_status
{
	WALL_ERROR = 0,
	WALL_AVOID = 1,
	WALL_OK = 2,
}	t_wall_status;

typedef struct s_stack
{
	int				size;
	int				head;
	int				*tab;
	char			identifier;
	struct s_stack	*next;
}	t_stack;

typedef struct s_env
{
	int		stack_size;
	char	**stack_str;
	t_bool	is_copy;
	t_stack	**stacks;
	t_move	**moves;
}	t_env;

typedef struct s_push_swap
{
	int				argc;
	char			**argv;

	t_bool			is_in_stackmem;
	t_wall_status	wall_status;

	t_env			*env;
}	t_push_swap;

typedef struct s_bucket
{
	int				*composition;
	int				size;
	t_move			**moves;
	struct s_bucket	*next;
}	t_bucket;

typedef struct s_stack_buckets
{
	int			total_moves;
	t_bucket	**buckets;
}				t_stack_buckets;

//	WALL	////////////////////////////////////////////////////////////////////

t_wall_status	check_argv(t_push_swap *p);

//	MOVES	////////////////////////////////////////////////////////////////////

void			push(t_stack *s1, t_stack *s2, t_bool print_move);
void			reverse_rotate(t_stack *s1, t_stack *s2, t_bool print_move);
void			rotate(t_stack *s1, t_stack *s2, t_bool print_move);
void			swap(t_stack *s1, t_stack *s2, t_bool print_move);

//	INIT	////////////////////////////////////////////////////////////////////

t_env			*create_env(void);
t_push_swap		*create_push_swap(int argc, char **argv);
t_stack			*create_stack(int size, char identifier);
t_stack			*copy_stack(t_stack *stack);
t_stack			*feed_stack(
					t_stack *stack,
					t_stack_food_type type,
					void *content,
					int size
					);
t_stack			*sort_and_replace_by_index(
					t_stack *dest, t_stack *src, int size);
void			selection_sort(int *list, int length);
int				getpos(t_stack *s, int value);
int				getval(t_stack *s, int pos, int offset);
int				is_sorted(t_env *env);
t_stack			*get_stack_by_id(t_env *env, char identifier);

int				sort_2(t_env *env);
int				sort_3(t_env *env);

t_env			*create_emulation(t_env *env);
void			bucket_sort(t_push_swap *p, int buckets);

void			display_stack(t_stack *s, int indents, t_bool is_first);
void			display_env(t_env *e, int indents, t_bool is_first);
void			display_push_swap(t_push_swap *p);
void			display_stack_buckets(t_stack_buckets *sb);
void			display_flow(t_move **flow);

int				*get_bucket_composition(
					int bucket_offset,
					int stack_size,
					int buckets,
					int *pushed
					);
void			end_everything(
					t_push_swap *p, t_bool exit_program, int exit_status);

t_stack_buckets	*create_stack_buckets(void);
t_bucket		*append_bucket(
					t_stack_buckets *parent, int *composition, int size);
void			empty_stack_buckets(t_stack_buckets *sb);
int				distance_to_pos(int size, int cur_pos, int pos);

t_move			*create_moves(t_move_id move_id, t_move *prev);
t_move			*create_move(t_move_id move_id);
char			*move_str(t_move_id move_id);
int				read_moves_flow(t_env *env, t_move *flow, t_bool print_move);

t_move			**create_flow();
t_move			*append_move(t_move **flow, t_move_id move_id, t_bool init);
t_move			**concat_flow(t_move **flow1, t_move **flow2, t_bool init);

#endif