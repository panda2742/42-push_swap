/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:27:35 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/06 14:46:44 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"

int	is_sorted(t_env *env)
{
	t_stack	*a;
	t_stack	*c;
	int		i;
	int		j;

	a = env->stacks[0];
	c = a->next->next;
	if (a->size != env->stack_size)
		return (0);
	i = -1;
	j = a->head - 1;
	while (++i < env->stack_size)
	{
		++j;
		if (j == a->head)
			j = 0;
		if (a->tab[j] != c->tab[i])
			return (0);
	}
	return (1);
}
