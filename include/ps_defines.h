/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_defines.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:04:46 by ehosta            #+#    #+#             */
/*   Updated: 2025/01/22 10:37:46 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_DEFINES_H
# define PS_DEFINES_H

# include <stdlib.h>

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
	struct s_clist_node	*next;
}	t_clist_node;

typedef enum	e_wall_status
{
	WALL_ERROR = 0,
	WALL_AVOID = 1,
	WALL_OK = 2,
}	t_wall_status;

typedef struct s_env
{
	int 			argc;
	char			**argv;
	char			**stack_str;
	int				is_in_stack;
	size_t			stack_size;
	t_wall_status	wall_status;
	t_clist_node	**stack_a;
	t_clist_node	**stack_b;
}	t_env;

#endif