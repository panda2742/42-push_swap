/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_io.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 01:12:35 by ehosta            #+#    #+#             */
/*   Updated: 2025/01/23 09:44:11 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_IO_H
# define PS_IO_H

# include "ps_defines.h"

void	display_env(t_env *env);
void	display_stack(t_env *env, char c);
void	display_error(void);

#endif