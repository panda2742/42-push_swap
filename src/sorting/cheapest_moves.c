/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:12:38 by ehosta            #+#    #+#             */
/*   Updated: 2025/01/27 13:57:22 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void cheapest_moves(t_env *env)
{
	t_env	*em_env;
	int		moves;
	
	em_env = create_emulation(env);
	if (!em_env)
		return ;
	moves = move_reverse_all(em_env, 1);
	printf("moves: %d\n", moves);
	em_env = reset_em_env(env, em_env);
	moves = everything_ascending(em_env, 1);
	printf("moves: %d\n", moves);
	free_copied_env(em_env);
}