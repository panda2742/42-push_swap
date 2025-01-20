/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parsing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:38:52 by ehosta            #+#    #+#             */
/*   Updated: 2025/01/20 16:21:57 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_PARSING_H
# define PS_PARSING_H

enum e_node_type
{
	STACK_HEAD,
	STACK_ELEMENT,
	STACK_EMPTY_CELL,
};

typedef struct	s_stack_node
{
	enum e_node_type	type;
	int					value;
	struct s_stack_node	*previous;
	struct s_stack_node	*next;
}	t_stack_node;

t_stack_node	*init_stack(t_stack_node *stack_a, t_stack_node *stack_b);
t_stack_node	*append_to_stack(
	const char *stack_elt,
	t_stack_node *stack_a,
	t_stack_node *stack_b
);
t_stack_node	*parse_stack_str(
	const char **stack_str,
	size_t len,
	t_stack_node *stack_b
);

#endif