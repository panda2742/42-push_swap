/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_clist.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:51:51 by ehosta            #+#    #+#             */
/*   Updated: 2025/01/21 17:59:51 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_CLIST_H
# define PS_CLIST_H

# include <stdlib.h>
# include "ps_wall.h"

typedef enum	e_node_type
{
	NODE_HEAD,
	NODE_ELEMENT,
	NODE_EMPTY
}	t_node_type;

typedef struct	s_clist_node
{
	t_node_type			type;
	int					value;
	struct s_clist_node	*previous;
	struct s_clist_node	*next;
}	t_clist_node;

typedef struct s_env
{
	int 			argc;
	char			**argv;
	char			**stack_str;
	size_t			stack_size;
	t_wall_status	wall_status;
	t_clist_node	**stack_a;
	t_clist_node	**stack_b;
}	t_env;

t_clist_node	*create_clist(t_env *env, int is_empty);
t_clist_node	*create_head(void);
t_clist_node	*create_node(t_node_type type, int val, t_clist_node *previous);

#endif