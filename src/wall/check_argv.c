/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:09:39 by ehosta            #+#    #+#             */
/*   Updated: 2025/01/21 15:59:18 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static t_wall_status	_check_stack(
								const char **stack,
								size_t stack_size,
								t_wall_status status
								);
static int				_check_stack_element(const char *stack_elt);
static int				_check_value(int value, int sign, char c);
static int				_check_doubles(const char **stack, size_t stack_size);

t_wall_status	check_argv(int ac, char **av, char **stack, size_t *stack_size)
{
	t_wall_status	status;

	ac--;
	if (ac == 0)
		return (WALL_AVOID);
	av++;
	if (ac == 1)
	{
		stack = ft_split(av[0], ' ');
		if (!stack)
			return (WALL_ERROR);
		while (stack[*stack_size])
			*stack_size += 1;
		status = WALL_HEAPED;
	}
	else
	{
		stack = av;
		*stack_size = ac;
		status = WALL_STACKED;
	}
	return (_check_stack((const char **)stack, *stack_size, status));
}

static t_wall_status	_check_stack(
	const char **stack, size_t stack_size, t_wall_status status)
{
	size_t	i;

	i = -1;
	while (++i < stack_size)
	{
		if (!_check_stack_element(stack[i]))
		{
			if (status == WALL_HEAPED)
				return (WALL_ERROR_HEAPED);
			return (WALL_ERROR);
		}
	}
	if (!_check_doubles(stack, stack_size))
	{
		if (status == WALL_HEAPED)
			return (WALL_ERROR_HEAPED);
		return (WALL_ERROR);
	}
	return (status);
}

static int	_check_stack_element(const char *stack_elt)
{
	size_t	i;
	size_t	elt_len;
	long	value;
	int		sign;
	char	c;

	i = -1;
	sign = 1;
	if (stack_elt[0] && stack_elt[0] == '-')
	{
		sign = -1;
		i++;
	}
	elt_len = ft_strlen(stack_elt);
	value = 0;
	while (++i < elt_len)
	{
		c = stack_elt[i];
		if (!ft_isdigit(c))
			return (0);
		if (!_check_value(value, sign, c))
			return (0);
		value = value * 10 + c - '0';
	}
	return (1);
}

static int	_check_value(int value, int sign, char c)
{
	if (sign == 1)
		return ((value * 10 + c - '0') / 10 == value);
	return ((-value * 10 - (c - '0')) / 10 == -value);
}

static int	_check_doubles(const char **stack, size_t stack_size)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (++i < stack_size)
	{
		j = i;
		while (++j < stack_size)
		{
			if (ft_atoi(stack[i]) == ft_atoi(stack[j]))
				return (0);
		}
	}
	return (1);
}
