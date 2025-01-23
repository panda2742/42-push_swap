/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:44:29 by ehosta            #+#    #+#             */
/*   Updated: 2025/01/23 13:21:14 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	rra(t_env *env)
{
	reverse_rotate(env, 'a', 1);
}

void	rrb(t_env *env)
{
	reverse_rotate(env, 'b', 1);
}

void	rrr(t_env *env)
{
	reverse_rotate(env, 'r', 1);
}
