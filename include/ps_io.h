/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_io.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 01:12:35 by ehosta            #+#    #+#             */
/*   Updated: 2025/01/22 10:20:11 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_IO_H
# define PS_IO_H

# include "ps_clist.h"

void	display_clist(t_clist_node *head);
void	display_clist_node(t_clist_node *element);
void	display_env(t_env *env);
void	display_error(void);

#endif