/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_moves.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:45:37 by ehosta            #+#    #+#             */
/*   Updated: 2025/01/22 15:20:46 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_MOVES_H
# define PS_MOVES_H

# include "ps_defines.h"

void	push(t_env *env, char c, int to_print);
void	reverse_rotate(t_env *env, char c, int to_print);
void	rotate(t_env *env, char c, int to_print);
void	swap(t_env *env, char c, int to_print);

#endif