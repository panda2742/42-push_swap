/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:09:10 by ehosta            #+#    #+#             */
/*   Updated: 2025/01/27 11:34:13 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	reverse_rotate(t_env *env, char c, int to_print)
{
	int	*head;
	int	size;

	if (c == 'r')
	{
		ft_printf("rrr\n");
		reverse_rotate(env, 'a', 0);
		reverse_rotate(env, 'b', 0);
		return ;
	}
	if (to_print)
		ft_printf("rr%c\n", c);
	head = &env->a_head;
	size = env->a_size;
	if (size < 2)
		return ;
	if (c == 'b')
	{
		head = &env->b_head;
		size = env->b_size;
	}
	if (*head == 0)
		*head = size - 1;
	else
		*head -= 1;
}
