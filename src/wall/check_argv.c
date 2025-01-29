/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:09:39 by ehosta            #+#    #+#             */
/*   Updated: 2025/01/29 17:44:39 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static t_wall_status	_check_stack(t_push_swap *p);
static int				_check_stack_element(const char *stack_elt);
static int				_check_value(int value, int sign, char c);
static int				_check_doubles(t_push_swap *p);

t_wall_status	check_argv(t_push_swap *p)
{
	p->argc -= 1;
	if (p->argc == 0)
		return (WALL_AVOID);
	p->argv += 1;
	p->env->stack_size = 0;
	if (p->argc == 1 && ft_strchr(p->argv[0], ' '))
	{
		p->env->stack_str = ft_split(p->argv[0], ' ');
		if (!p->env->stack_str)
			return (WALL_ERROR);
		while (p->env->stack_str[p->env->stack_size])
			p->env->stack_size += 1;
		p->wall_status = WALL_OK;
		p->is_in_stackmem = false;
	}
	else
	{
		p->env->stack_str = p->argv;
		p->env->stack_size = p->argc;
		p->wall_status = WALL_OK;
	}
	return (_check_stack(p));
}

static t_wall_status	_check_stack(t_push_swap *p)
{
	int	i;

	i = -1;
	while (++i < p->env->stack_size)
	{
		if (!_check_stack_element(p->env->stack_str[i]))
			return (WALL_ERROR);
	}
	if (!_check_doubles(p))
		return (WALL_ERROR);
	return (p->wall_status);
}

static int	_check_stack_element(const char *stack_elt)
{
	int		i;
	int		elt_len;
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

static int	_check_doubles(t_push_swap *p)
{
	int	i;
	int	j;

	i = -1;
	while (++i < p->env->stack_size)
	{
		j = i;
		while (++j < p->env->stack_size)
		{
			if (ft_atoi(p->env->stack_str[i]) == ft_atoi(p->env->stack_str[j]))
				return (0);
		}
	}
	return (1);
}
