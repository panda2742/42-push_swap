/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_manager.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:54:39 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/10 16:40:56 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_instruction	*create_instr_flow(t_push_swap *p, t_move_id move_id)
{
	t_instruction	*instr;

	instr = malloc(sizeof(t_instruction));
	if (!instr)
		return (NULL);
	p->instructions = malloc(sizeof(t_instruction *));
	if (!p->instructions)
		return (free(instr), NULL);
	instr->move_id = move_id;
	instr->next = NULL;
	p->instructions[0] = instr;
	return (instr);
}

t_instruction	*create_instr(t_push_swap *p, t_move_id move_id)
{
	t_instruction	*instr;
	t_instruction	*prev;

	if (!p->instructions)
		return (create_instr_flow(p, move_id));
	instr = malloc(sizeof(t_instruction));
	if (!instr)
		return (NULL);
	instr->move_id = move_id;
	instr->next = NULL;
	prev = p->instructions[0];
	while (prev->next)
		prev = prev->next;
	prev->next = instr;
	return (instr);
}