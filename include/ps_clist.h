/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_clist.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:51:51 by ehosta            #+#    #+#             */
/*   Updated: 2025/01/22 09:49:10 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_CLIST_H
# define PS_CLIST_H

# include <stdlib.h>
# include "ps_defines.h"
# include "ps_wall.h"

void			free_clist(t_clist_node *stack);
void			free_stack_str(char **stack_str, size_t stack_size);
t_clist_node	*create_clist(t_env *env, int is_empty);
t_clist_node	*create_head(void);
t_clist_node	*create_node(t_node_type type, int val, t_clist_node *previous, t_clist_node *head);

#endif