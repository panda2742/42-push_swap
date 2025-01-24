/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:38:08 by ehosta            #+#    #+#             */
/*   Updated: 2025/01/24 17:28:04 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_SORTING_H
# define PS_SORTING_H

void	sort_2(t_env *env);
void	sort_3(t_env *env);
void	selection_sort(int *list, size_t length);
void	sort(t_env *env);
int		is_sorted(t_env *env);

#endif