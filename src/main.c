/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:59:51 by ehosta            #+#    #+#             */
/*   Updated: 2025/01/20 15:51:43 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	enum e_wall_status	checked;
	char				**stack_str;
	size_t				len;

	stack_str = NULL;
	len = 0;
	checked = check_argv(argc, argv, stack_str, &len);
	if (checked == WALL_AVOID)
		return (0);
	if (checked == WALL_ERROR_HEAPED)
		free(stack_str);
	if (checked == WALL_ERROR || checked == WALL_ERROR_HEAPED)
		return (display_error(), 0);
	ft_printf("good output");
	(void)len;
	if (checked == WALL_HEAPED)
		free(stack_str);
	return (0);
}
