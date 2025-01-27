/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:51:51 by ehosta            #+#    #+#             */
/*   Updated: 2025/01/27 15:03:37 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_STACK_H
# define PS_STACK_H

# include <stdlib.h>
# include "ps_defines.h"
# include "ps_wall.h"

int		*init_stack(t_env *env, int is_empty);
int		*dup_stack(int *stack, int stack_size);
void	free_stack_str(char **stack_str, int size);
int		distance_to_pos(int size, int cur_pos, int pos);
int		getval(int *stack, int pos, int size, int offset);
int		getpos(int *stack, int value, int size);
int		*copy_stack_a(t_env *env, t_env *em_env);
int		*copy_stack_b(t_env *env, t_env *em_env);
int		*copy_stack_s(t_env *env, t_env *em_env);
void	free_copied_env(t_env *em_env);
t_env	*create_emulation(t_env *env);
t_env	*reset_em_env(t_env *env, t_env *em_env);

#endif