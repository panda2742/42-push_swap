/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:05:29 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/05 12:48:03 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_push_swap	*create_push_swap(int argc, char **argv)
{
	t_push_swap	*push_swap;

	push_swap = malloc(sizeof(t_push_swap));
	if (!push_swap)
		return (NULL);
	push_swap->argc = argc;
	push_swap->argv = argv;
	push_swap->is_in_stackmem = true;
	push_swap->wall_status = WALL_OK;
	push_swap->env = NULL;
	return (push_swap);
}
