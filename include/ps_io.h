/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_io.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 01:12:35 by ehosta            #+#    #+#             */
/*   Updated: 2025/01/22 15:18:49 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_IO_H
# define PS_IO_H

# include "ps_defines.h"

void	display_env(t_env *env);
void	display_stack(int *stack, size_t stack_size, size_t head);
void	display_error(void);

#endif