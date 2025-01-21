/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:59:49 by ehosta            #+#    #+#             */
/*   Updated: 2025/01/21 15:31:51 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "../libft/include/libft.h"
# include "ps_io.h"
# include "ps_wall.h"

# ifndef DEBUG
#  define DEBUG 0
# endif

typedef struct s_env
{
	int argc;
	char	**argv;
	char	**stack_str;
	size_t	len;
	t_wall_status	wall_status;
}	t_env;

#endif