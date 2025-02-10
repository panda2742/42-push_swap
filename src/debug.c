/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 21:27:02 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/10 15:02:28 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	display_push_swap(t_push_swap *p)
{
	int				i;
	t_instruction	*instr;

	if (!DEBUG)
		return ;
	printf(MAGENTA "[Push Swap %p]\n" RESET, p);
	printf(" │ Stack in heap memory: ");
	if (!p->is_in_stackmem)
		printf(GREEN "true\n" RESET);
	else
		printf(RED "false\n" RESET);
	printf(" │ Wall status:\t%d\n", p->wall_status);
	if (!DEBUG)
		return ;
	printf(" │ Initial size:\t%d\n", p->stack_size);
	printf(" │ Content:\t");
	i = -1;
	while (++i < p->stack_size)
		printf("%s ", p->stack_str[i]);
	printf("\n │ Resolutions:\n │ ");
	instr = p->instructions[0];
	while (instr)
	{
		printf("%s ", move_str(instr->move_id));
		instr = instr->next;
	}
	printf("\n │ Stacks:\n");
	ft_array_print(p->a);
	ft_array_print(p->b);
}
