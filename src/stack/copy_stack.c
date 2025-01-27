/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 09:04:02 by ehosta            #+#    #+#             */
/*   Updated: 2025/01/27 14:43:35 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	*copy_stack_a(t_env *env, t_env *em_env)
{
	int	i;

	em_env->a_head = env->a_head;
	em_env->a_size = env->a_size;
	em_env->stack_a = malloc(env->stack_size * sizeof(int));
	if (!em_env->stack_a)
		return (NULL);
	i = -1;
	while ((int)++i < em_env->a_size)
		em_env->stack_a[i] = env->stack_a[i];
	return (em_env->stack_a);
}

int	*copy_stack_b(t_env *env, t_env *em_env)
{
	int	i;

	em_env->b_head = env->b_head;
	em_env->b_size = env->b_size;
	em_env->stack_b = malloc(env->stack_size * sizeof(int));
	if (!em_env->stack_b)
		return (NULL);
	i = -1;
	while ((int)++i < em_env->b_size)
		em_env->stack_b[i] = env->stack_b[i];
	return (em_env->stack_b);
}

int	*copy_stack_s(t_env *env, t_env *em_env)
{
	em_env->stack_size = env->stack_size;
	em_env->sorted_stack = env->sorted_stack;
	return (em_env->sorted_stack);
}

void	free_copied_env(t_env *em_env)
{
	free(em_env->stack_a);
	free(em_env->stack_b);
	free(em_env);
}

t_env	*reset_em_env(t_env *env, t_env *em_env)
{
	free_copied_env(em_env);
	em_env = create_emulation(env);
	return (em_env);
}
