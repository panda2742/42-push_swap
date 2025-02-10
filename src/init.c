/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:05:29 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/10 14:32:35 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_push_swap	*init(int argc, char **argv)
{
	t_push_swap	*push_swap;

	push_swap = malloc(sizeof(t_push_swap));
	if (!push_swap)
		return (NULL);
	push_swap->argc = argc;
	push_swap->argv = argv;
	push_swap->is_in_stackmem = true;
	push_swap->wall_status = WALL_OK;
	return (push_swap);
}

