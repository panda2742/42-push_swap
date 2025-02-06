/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_n_elements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 00:00:19 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/06 14:12:52 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int	_execute_3s_comb(t_env *env, t_move_id m1, t_move_id m2);

int	sort_2(t_env *env)
{
	if (get_stack_by_id(env, 'a')->tab[0])
	{
		env->moves[0] = create_move(NULL, SA);
		return (1);
	}
	return (0);
}

int	sort_3(t_env *env)
{
	t_stack	*a;
	int		first;
	int		second;
	int		third;

	a = get_stack_by_id(env, 'a');
	first = a->tab[0];
	second = a->tab[1];
	third = a->tab[2];
	if (first == 2 && second == 1)
		return (_execute_3s_comb(env, RA, SA));
	if (first == 2 && second == 0)
		return (_execute_3s_comb(env, RA, -1));
	if (first == 1 && second == 2)
		return (_execute_3s_comb(env, RRA, -1));
	if (first == 1 && second == 0)
		return (_execute_3s_comb(env, SA, -1));
	if (first == 0 && second == 2)
		return (_execute_3s_comb(env, RRA, SA));
	return (2);
}

static int	_execute_3s_comb(t_env *env, t_move_id m1, t_move_id m2)
{
	t_move	*m;

	m = create_move(NULL, m1);
	if ((int)m2 != -1)
		create_move(m, m2);
	env->moves[0] = m;
	return (1 + ((int)m2 != -1));
}