/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_io.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 01:12:35 by ehosta            #+#    #+#             */
/*   Updated: 2025/01/21 16:58:15 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_IO_H
# define PS_IO_H

# include "ps_clist.h"

void	display_clist(t_clist_node *head);
void	display_clist_node(t_clist_node *element);
void	display_error(void);

#endif