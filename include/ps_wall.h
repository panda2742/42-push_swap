/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_wall.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:10:05 by ehosta            #+#    #+#             */
/*   Updated: 2025/01/17 14:36:55 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_WALL_H
# define PS_WALL_H

enum e_wall_status
{
	WALL_ERROR = 0,
	WALL_AVOID = 1,
	WALL_HEAPED = 2,
	WALL_STACKED = 3,
	WALL_ERROR_HEAPED = 4,
};

enum e_wall_status	check_argv(int ac, char **av, char **stack, size_t *len);

#endif