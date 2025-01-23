/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:50:27 by ehosta            #+#    #+#             */
/*   Updated: 2025/01/23 15:29:25 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	*init_stack(t_env *env, int is_empty)
{
	size_t			i;
	int				*tab;

	tab = malloc(env->stack_size * sizeof(int));
	if (is_empty)
		return (tab);
	i = -1;
	while (++i < env->stack_size)
		tab[i] = ft_atoi(env->stack_str[i]);
	return (tab);
}

int	*dup_stack(int *stack, size_t stack_size)
{
	int		*tab;
	size_t	i;

	tab = malloc(stack_size * sizeof(int));
	if (!tab)
		return (NULL);
	i = -1;
	while (++i < stack_size)
		tab[i] = stack[i];
	return (tab);
}

void	free_stack_str(char **stack_str, size_t size)
{
	size_t	i;

	i = -1;
	while (++i < size)
		free(stack_str[i]);
	free(stack_str);
}
