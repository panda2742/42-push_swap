/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:12:38 by ehosta            #+#    #+#             */
/*   Updated: 2025/01/28 12:06:33 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int	_get_most_efficient(
				t_env *env,
				t_env *em_env,
				int (*f[ALGOS_NUMBER][ALGOS_PART])(t_env *, int)
				);
static int	_get_moves_for_algo(t_env *env, int (*f[ALGOS_PART])(t_env *, int));
static int	_do_nothing(t_env *env, int emulation);

void	cheapest_moves(t_env *env)
{
	static t_algos_list	f = {
	{bucket_sorting, _do_nothing, _do_nothing, _do_nothing, _do_nothing}
	};
	t_env				*em_env;
	int					most_efficient;
	int					i;

	em_env = create_emulation(env);
	if (!em_env)
		return ;
	most_efficient = _get_most_efficient(env, em_env, f);
	most_efficient = 0;
	i = -1;
	while (++i < ALGOS_NUMBER)
		f[most_efficient][i](env, 0);
}

static int	_get_most_efficient(
	t_env *env,
	t_env *em_env,
	int (*f[ALGOS_NUMBER][ALGOS_PART])(t_env *, int)
)
{
	int	i;
	int	moves;
	int	max;
	int	max_moves;

	i = -1;
	max = 0;
	max_moves = 65000;
	while (++i < ALGOS_NUMBER)
	{
		moves = _get_moves_for_algo(em_env, f[i]);
		if (moves < max_moves)
		{
			max = i;
			max_moves = moves;
		}
		em_env = reset_em_env(env, em_env);
	}
	free_copied_env(em_env);
	return (max);
}

static int	_get_moves_for_algo(t_env *env, int (*f[ALGOS_PART])(t_env *, int))
{
	int	moves;
	int	i;

	moves = 0;
	i = -1;
	while (++i < ALGOS_PART)
		moves += f[i](env, 1);
	return (moves);
}

static int	_do_nothing(t_env *env, int emulation)
{
	(void)env;
	(void)emulation;
	return (0);
}
