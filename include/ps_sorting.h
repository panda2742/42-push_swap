/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:38:08 by ehosta            #+#    #+#             */
/*   Updated: 2025/01/27 11:34:05 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_SORTING_H
# define PS_SORTING_H

void	selection_sort(int *list, int length);
void	sort(t_env *env);
int		is_sorted(t_env *env);
void 	cheapest_moves(t_env *env);

int		sort_2(t_env *env, int emulation);
int		sort_3(t_env *env, int emulation);
int		move_reverse_all(t_env *env, int emulation);
int		everything_ascending(t_env *env, int emulation);

#endif