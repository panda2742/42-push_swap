/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_n_elements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 00:00:19 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/05 17:25:25 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	sort_2(t_env *env)
{
	if (get_stack_by_id(env, 'a')->tab[0])
		return (add_move(env->moves[0], SA), 1);
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
		return (add_move(add_move(env->moves[0], RA), SA), 2);
	if (first == 2 && second == 0)
		return (add_move(env->moves[0], RA), 1);
	if (first == 1 && second == 2)
		return (add_move(env->moves[0], RRA), 1);
	if (first == 1 && second == 0)
		return (add_move(env->moves[0], SA), 1);
	if (first == 0 && second == 2)
		return (add_move(add_move(env->moves[0], RRA), SA), 2);
	return (2);
}
