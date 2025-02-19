/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:46:22 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/19 16:35:09 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

void	terminate(t_push_swap *p, t_bool exit_program, int exit_status)
{
	if (!p->is_in_stackmem)
		ft_free_strtab(p->stack_str);
	if (p->a)
		ft_array_clear(p->a);
	if (p->b)
		ft_array_clear(p->b);
	if (p->c)
		ft_array_clear(p->c);
	if (exit_program)
		exit(exit_status);
}
