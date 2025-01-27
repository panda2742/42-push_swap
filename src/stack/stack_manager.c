/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:50:27 by ehosta            #+#    #+#             */
/*   Updated: 2025/01/27 11:34:18 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	*init_stack(t_env *env, int is_empty)
{
	int			i;
	int				*tab;

	tab = malloc(env->stack_size * sizeof(int));
	if (is_empty)
		return (tab);
	i = -1;
	while (++i < env->stack_size)
		tab[i] = ft_atoi(env->stack_str[i]);
	return (tab);
}

int	*dup_stack(int *stack, int stack_size)
{
	int		*tab;
	int	i;

	tab = malloc(stack_size * sizeof(int));
	if (!tab)
		return (NULL);
	i = -1;
	while (++i < stack_size)
		tab[i] = stack[i];
	selection_sort(tab, stack_size);
	i = -1;
	while (++i < stack_size)
	{
		stack[getpos(stack, tab[i], stack_size)] = i;
		tab[i] = i;
	}
	return (tab);
}

void	free_stack_str(char **stack_str, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		free(stack_str[i]);
	free(stack_str);
}

t_env	*create_emulation(t_env *env)
{
	t_env	*em_env;

	em_env = malloc(sizeof(t_env));
	if (!em_env)
		return (NULL);
	copy_stack_a(env, em_env);
	copy_stack_b(env, em_env);
	copy_stack_s(env, em_env);
	return (em_env);
}