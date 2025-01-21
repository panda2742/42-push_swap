/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_clist.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:51:51 by ehosta            #+#    #+#             */
/*   Updated: 2025/01/21 23:32:23 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_CLIST_H
# define PS_CLIST_H

# include <stdlib.h>
# include "ps_defines.h"
# include "ps_wall.h"

t_clist_node	*create_clist(t_env *env, int is_empty);
t_clist_node	*create_head(void);
t_clist_node	*create_node(t_node_type type, int val, t_clist_node *previous, t_clist_node *head);

#endif