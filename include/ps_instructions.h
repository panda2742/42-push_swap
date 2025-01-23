/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_instructions.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:30:46 by ehosta            #+#    #+#             */
/*   Updated: 2025/01/23 13:26:02 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_INSTRUCTIONS_H
# define PS_INSTRUCTIONS_H

# include "ps_moves.h"

void	sa(t_env *env);
void	sb(t_env *env);
void	ss(t_env *env);

void	pa(t_env *env);
void	pb(t_env *env);

void	ra(t_env *env);
void	rb(t_env *env);
void	rr(t_env *env);

void	rra(t_env *env);
void	rrb(t_env *env);
void	rrr(t_env *env);

#endif