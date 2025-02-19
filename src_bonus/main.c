/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:59:51 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/19 16:40:06 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

static void	_wall_handler(t_push_swap *p);
static void	_stack_handler(t_push_swap *p);
static void	_read_handler(t_push_swap *p);

int	main(int argc, char **argv)
{
	t_push_swap	p;

	p.argc = argc;
	p.argv = argv;
	p.is_in_stackmem = true;
	p.wall_status = WALL_OK;
	p.a = NULL;
	p.b = NULL;
	p.c = NULL;
	_wall_handler(&p);
	_stack_handler(&p);
	_read_handler(&p);
	terminate(&p, false, EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

static void	_wall_handler(t_push_swap *p)
{
	p->stack_size = 0;
	p->wall_status = wall(p);
	if (p->wall_status == WALL_AVOID)
		terminate(p, true, EXIT_FAILURE);
	if (p->wall_status == WALL_ERROR)
	{
		ft_printf("Error\n");
		terminate(p, true, EXIT_FAILURE);
	}
}

static void	_stack_handler(t_push_swap *p)
{
	p->a = ft_array_new('a', p->stack_size, ARRAY_INT);
	if (!p->a)
		terminate(p, true, EXIT_FAILURE);
	p->b = ft_array_new('b', p->stack_size, ARRAY_INT);
	if (!p->b)
		terminate(p, true, EXIT_FAILURE);
	p->b->size = 0;
	p->a = ft_array_fill(p->a, p->stack_str, ARRAY_STRING);
	p->c = ft_array_getsorted(p->a, 1);
	if (!p->c)
		terminate(p, true, EXIT_FAILURE);
}

static void	_read_handler(t_push_swap *p)
{
	char	*line;
	t_bool	instr_is_valid;

	line = get_next_line(0);
	while (line)
	{
		instr_is_valid = valid_push(p, line) | valid_rotate(p, line)
			| valid_reverse_rotate(p, line) | valid_swap(p, line);
		if (!instr_is_valid)
			break ;
		free(line);
		line = get_next_line(0);
	}
	free(line);
	if (!instr_is_valid)
		ft_printf("Error\n");
	if (ft_issorted(p->a->data, p->a->size) || p->a->size == p->stack_size)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
