/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_instruction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:42:19 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/20 11:47:18 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

t_bool	valid_swap(t_push_swap *p, const char *instr_name)
{
	const size_t	instr_len = ft_strlen(instr_name);

	if (instr_len != 3
		|| instr_name[2] != '\n'
		|| instr_name[0] != 's'
		|| !ft_isincharset(instr_name[1], "abs"))
		return (false);
	if (instr_name[1] == 'a')
		swap(p->a, NULL);
	else if (instr_name[1] == 'b')
		swap(p->b, NULL);
	else if (instr_name[1] == 's')
		swap(p->a, p->b);
	return (true);
}

t_bool	valid_rotate(t_push_swap *p, const char *instr_name)
{
	const size_t	instr_len = ft_strlen(instr_name);

	if (instr_len != 3
		|| instr_name[2] != '\n'
		|| instr_name[0] != 'r'
		|| !ft_isincharset(instr_name[1], "abr"))
		return (false);
	if (instr_name[1] == 'a')
		rotate(p->a, NULL);
	else if (instr_name[1] == 'b')
		rotate(p->b, NULL);
	else if (instr_name[1] == 't')
		rotate(p->a, p->b);
	return (true);
}

t_bool	valid_reverse_rotate(t_push_swap *p, const char *instr_name)
{
	const size_t	instr_len = ft_strlen(instr_name);

	if (instr_len != 4
		|| instr_name[3] != '\n'
		|| instr_name[0] != 'r'
		|| instr_name[1] != 'r'
		|| !ft_isincharset(instr_name[2], "abr"))
		return (false);
	if (instr_name[2] == 'a')
		reverse_rotate(p->a, NULL);
	else if (instr_name[2] == 'b')
		reverse_rotate(p->b, NULL);
	else if (instr_name[2] == 'r')
		reverse_rotate(p->a, p->b);
	return (true);
}

t_bool	valid_push(t_push_swap *p, const char *instr_name)
{
	const size_t	instr_len = ft_strlen(instr_name);

	if (instr_len != 3
		|| instr_name[2] != '\n'
		|| instr_name[0] != 'p'
		|| !ft_isincharset(instr_name[1], "ab"))
		return (false);
	if (instr_name[1] == 'b')
		push(p->a, p->b);
	else if (instr_name[1] == 'a')
		push(p->b, p->a);
	return (true);
}
