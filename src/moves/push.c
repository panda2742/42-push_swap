/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:14:30 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/05 16:03:54 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int	_extract_from_stack(t_stack *s);
static void	_push_to_stack(t_stack *s, int elt);

void	push(t_stack *s1, t_stack *s2, t_bool print_move)
{
	int	elt;

	if (print_move)
		ft_printf("p%c\n", s1->identifier);
	elt = _extract_from_stack(s2);
	_push_to_stack(s1, elt);
}

static int	_extract_from_stack(t_stack *s)
{
	int	elt;
	int	i;

	elt = s->tab[s->head];
	if (s->head + 1 == s->size)
	{
		s->size -= 1;
		s->head = 0;
		return (elt);
	}
	i = s->head - 1;
	while (++i + 1 < s->size)
		s->tab[i] = s->tab[i + 1];
	s->size -= 1;
	return (elt);
}

static void	_push_to_stack(t_stack *s, int elt)
{
	int	i;

	i = s->size;
	s->size += 1;
	while (i > s->head)
	{
		s->tab[i] = s->tab[i - 1];
		i--;
	}
	s->tab[i] = elt;
}
