/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:51:51 by ehosta            #+#    #+#             */
/*   Updated: 2025/01/22 15:19:53 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_STACK_H
# define PS_STACK_H

# include <stdlib.h>
# include "ps_defines.h"
# include "ps_wall.h"

int		*init_stack(t_env *env, int is_empty);
void	free_stack_str(char **stack_str, size_t size);

#endif