/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:59:51 by ehosta            #+#    #+#             */
/*   Updated: 2025/01/20 10:49:31 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	enum e_wall_status	checked;
	char				**stack;
	size_t				len;

	stack = NULL;
	len = 0;
	checked = check_argv(argc, argv, stack, &len);
	if (checked == WALL_AVOID)
		return (0);
	if (checked == WALL_ERROR_HEAPED)
		free(stack);
	if (checked == WALL_ERROR || checked == WALL_ERROR_HEAPED)
		return (display_error(), 0);
	ft_printf("good output");
	(void)len;
	if (checked == WALL_HEAPED)
		free(stack);
	return (0);
}
