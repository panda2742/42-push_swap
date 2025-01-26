/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_defines.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:04:46 by ehosta            #+#    #+#             */
/*   Updated: 2025/01/26 14:00:34 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_DEFINES_H
# define PS_DEFINES_H

# include <stdlib.h>

typedef enum e_wall_status
{
	WALL_ERROR = 0,
	WALL_AVOID = 1,
	WALL_OK = 2,
}	t_wall_status;

typedef struct s_env
{
	int				argc;
	char			**argv;

	int				is_in_stackmem;
	t_wall_status	wall_status;

	char			**stack_str;
	size_t			stack_size;
	int				*sorted_stack;

	int				*stack_a;
	int				*a_pos;
	size_t			a_size;
	size_t			a_head;

	int				*stack_b;
	int				*b_pos;
	size_t			b_size;
	size_t			b_head;
}	t_env;

#endif