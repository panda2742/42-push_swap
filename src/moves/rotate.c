/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:23:32 by ehosta            #+#    #+#             */
/*   Updated: 2025/01/22 15:18:27 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	rotate(t_env *env, char c, int to_print)
{
	size_t	*head;
	size_t	size;

	if (c == 'r')
	{
		ft_printf("rr\n");
		rotate(env, 'a', 0);
		rotate(env, 'b', 0);
		return ;
	}
	if (to_print)
		ft_printf("r%c\n", c);
	head = &env->a_head;
	size = env->a_size;
	if (size < 2)
		return ;
	if (c == 'b')
	{
		head = &env->b_head;
		size = env->b_size;
	}
	if (*head == size - 1)
		*head = 0;
	else
		*head += 1;
}
