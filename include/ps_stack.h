/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:51:51 by ehosta            #+#    #+#             */
/*   Updated: 2025/01/24 16:44:37 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_STACK_H
# define PS_STACK_H

# include <stdlib.h>
# include "ps_defines.h"
# include "ps_wall.h"

int		*init_stack(t_env *env, int is_empty);
int		*dup_stack(int *stack, size_t stack_size);
void	free_stack_str(char **stack_str, size_t size);
size_t	get_stack_min(int *stack, size_t size);
size_t	get_stack_max(int *stack, size_t size);
ssize_t	distance_to_pos(size_t size, size_t cur_pos, size_t pos);
size_t	getpos(int *stack, size_t pos, size_t size, ssize_t offset);

#endif