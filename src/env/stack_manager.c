/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:36:03 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/06 14:51:17 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_stack	*create_stack(int size, char identifier)
{
	t_stack	*stack;
	int		i;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->size = size;
	stack->head = 0;
	stack->identifier = identifier;
	stack->next = NULL;
	stack->tab = malloc(size * sizeof(int));
	if (!stack->tab)
		return (stack);
	i = -1;
	while (++i < stack->size)
		stack->tab[i] = 0;
	return (stack);
}

t_stack	*feed_stack(
	t_stack *stack, t_stack_food_type type, void *content, int size)
{
	int	i;

	i = -1;
	while (++i < size && i < stack->size)
	{
		if (type == string_stack)
			stack->tab[i] = ft_atoi(((char **)content)[i]);
		else if (type == int_stack)
			stack->tab[i] = ((int *)content)[i];
	}
	return (stack);
}

t_stack	*sort_and_replace_by_index(t_stack *dest, t_stack *src, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		dest->tab[i] = src->tab[i];
	selection_sort(dest->tab, size);
	i = -1;
	while (++i < size)
	{
		src->tab[getpos(src, dest->tab[i])] = i;
		dest->tab[i] = i;
	}
	return (dest);
}

t_stack	*get_stack_by_id(t_env *env, char identifier)
{
	t_stack	*s;

	s = env->stacks[0];
	while (s)
	{
		if (s->identifier == identifier)
			return (s);
		s = s->next;
	}
	return (NULL);
}

t_stack	*copy_stack(t_stack *stack)
{
	t_stack	*copy;
	int		i;

	copy = create_stack(stack->size, stack->identifier);
	copy->head = stack->head;
	copy->next = NULL;
	copy->tab = malloc(stack->size * sizeof(int));
	if (!copy->tab)
		return (copy);
	i = -1;
	while (++i < copy->size)
		copy->tab[i] = stack->tab[i];
	return (copy);
}
