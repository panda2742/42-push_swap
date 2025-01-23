/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:14:30 by ehosta            #+#    #+#             */
/*   Updated: 2025/01/23 00:48:00 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int	_extract_from_stack(int *tab, size_t head, size_t *size);
static void	_add_to_stack(int *tab, size_t head, size_t *size, int elt);
static void	_push_a(t_env *env);
static void	_push_b(t_env *env);

void	push(t_env *env, char c, int to_print)
{
	if (to_print)
		ft_printf("p%c\n", c);
	if (c == 'a')
		_push_a(env);
	else
		_push_b(env);
}

static void	_push_a(t_env *env)
{
	int	elt;

	if (!env->a_size)
		return ;
	elt = _extract_from_stack(env->stack_a, env->a_head, &env->a_size);
	_add_to_stack(env->stack_b, env->b_head, &env->b_size, elt);
}

static void	_push_b(t_env *env)
{
	int	elt;

	if (!env->b_size)
		return ;
	elt = _extract_from_stack(env->stack_b, env->b_head, &env->b_size);
	_add_to_stack(env->stack_a, env->a_head, &env->a_size, elt);
}

static int	_extract_from_stack(int *tab, size_t head, size_t *size)
{
	int		elt;
	size_t	limit;

	elt = tab[head];
	(void)size;
	limit = *size - head;
	head++;
	while (head < limit + 1)
	{
		tab[head - 1] = tab[head];
		head++;
	}
	*size -= 1;
	return (elt);
}

static void	_add_to_stack(int *tab, size_t head, size_t *size, int elt)
{
	(void)tab;
	(void)head;
	(void)size;
	(void)elt;
}
