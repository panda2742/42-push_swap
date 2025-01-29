/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:39:10 by ehosta            #+#    #+#             */
/*   Updated: 2025/01/29 16:40:48 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_env	*create_env(
	int stack_size, char **stack_str, t_bool is_copy, t_stack *stacks)
{
	t_env	*env;

	env = malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	env->stack_size;
	env->stack_str = stack_size;
	env->is_copy = is_copy;
	env->stacks = stacks;
}
