/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_flow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:19:18 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/07 15:30:33 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_move	**create_flow()
{
	t_move	**flow;

	flow = malloc(sizeof(t_move *));
	if (!flow)
		return (NULL);
	flow[0] = NULL;
	return (flow);
}

t_move	*append_move(t_move **flow, t_move_id move_id, t_bool init)
{
	t_move	*m;
	t_move	*last;
	
	m = create_move(move_id);
	if (!m)
		return (NULL);
	if (init)
	{
		flow[0] = m;
		return (m);
	}
	last = flow[0];
	if (!last)
	{
		flow[0] = m;
		return (m);
	}
	while (last->next)
		last = last->next;
	last->next = m;
	return (m);
}

t_move	**concat_flow(t_move **flow1, t_move **flow2, t_bool init)
{
	t_move	*last;

	if (init)
		return (free(flow1), flow2);
	last = flow1[0];
	while (last->next)
		last = last->next;
	last->next = flow2[0];
	free(flow2);
	return (flow1);
}