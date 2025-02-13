/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:04:13 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/13 15:45:39 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_instruction	*create_instr(t_push_swap *p, t_move_id move_id)
{
	t_instruction	*instr;
	t_instruction	*prev;

	instr = malloc(sizeof(t_instruction));
	if (!instr)
		return (NULL);
	instr->move_id = move_id;
	instr->next = NULL;
	if (!p->instructions)
	{
		p->instructions = malloc(sizeof(t_instruction *));
		if (!p->instructions)
			return (free(instr), NULL);
		p->instructions[0] = instr;
		return (instr);
	}
	prev = p->instructions[0];
	while (prev->next)
		prev = prev->next;
	prev->next = instr;
	return (instr);
}

void	swap(t_push_swap *p, t_array *arr1, t_array *arr2, t_bool addinstr)
{
	int	i_to_swap;
	int	tmp;

	if (arr2)
	{
		create_instr(p, SS);
		swap(p, arr1, NULL, false);
		swap(p, arr2, NULL, false);
		return ;
	}
	if (addinstr)
		printf("s%c\n", arr1->id);
	if (arr1->size < 2)
		return ;
	i_to_swap = arr1->head + 1;
	if (i_to_swap == arr1->size)
		i_to_swap = 0;
	tmp = ((int *)arr1->data)[arr1->head];
	((int *)arr1->data)[arr1->head] = ((int *)arr1->data)[i_to_swap];
	((int *)arr1->data)[i_to_swap] = tmp;
}

void	rotate(t_push_swap *p, t_array *arr1, t_array *arr2, t_bool addinstr)
{
	if (arr2)
	{
		create_instr(p, RR);
		rotate(p, arr1, NULL, false);
		rotate(p, arr2, NULL, false);
		return ;
	}
	if (addinstr)
		printf("r%c\n", arr1->id);
	if (arr1->size < 2)
		return ;
	if (arr1->head == arr1->size - 1)
		arr1->head = 0;
	else
		arr1->head += 1;
}

void	reverse_rotate(
	t_push_swap *p, t_array *arr1, t_array *arr2, t_bool addinstr)
{
	if (arr2)
	{
		create_instr(p, RRR);
		reverse_rotate(p, arr1, NULL, false);
		reverse_rotate(p, arr2, NULL, false);
		return ;
	}
	if (addinstr)
		printf("rr%c\n", arr1->id);
	if (arr1->size < 2)
		return ;
	if (arr1->head == 0)
		arr1->head = arr1->size - 1;
	else
		arr1->head -= 1;
}

void	push(t_push_swap *p, t_array *arr1, t_array *arr2)
{
	int	elt;

	(void)p;
	printf("p%c\n", arr2->id);
	elt = ft_array_popint(arr1, arr1->head);
	ft_array_pushint(arr2, elt);
}
