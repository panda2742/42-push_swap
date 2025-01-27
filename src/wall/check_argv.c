/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:09:39 by ehosta            #+#    #+#             */
/*   Updated: 2025/01/27 11:34:19 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static t_wall_status	_check_stack(t_env *env);
static int				_check_stack_element(const char *stack_elt);
static int				_check_value(int value, int sign, char c);
static int				_check_doubles(t_env *env);

t_wall_status	check_argv(t_env *env)
{
	env->argc -= 1;
	if (env->argc == 0)
		return (WALL_AVOID);
	env->argv += 1;
	if (env->argc == 1 && ft_strchr(env->argv[0], ' '))
	{
		env->stack_str = ft_split(env->argv[0], ' ');
		if (!env->stack_str)
			return (WALL_ERROR);
		while (env->stack_str[env->stack_size])
			env->stack_size += 1;
		env->wall_status = WALL_OK;
		env->is_in_stackmem = 0;
	}
	else
	{
		env->stack_str = env->argv;
		env->stack_size = env->argc;
		env->wall_status = WALL_OK;
		env->is_in_stackmem = 1;
	}
	return (_check_stack(env));
}

static t_wall_status	_check_stack(t_env *env)
{
	int	i;

	i = -1;
	while (++i < env->stack_size)
	{
		if (!_check_stack_element(env->stack_str[i]))
			return (WALL_ERROR);
	}
	if (!_check_doubles(env))
		return (WALL_ERROR);
	return (env->wall_status);
}

static int	_check_stack_element(const char *stack_elt)
{
	int	i;
	int	elt_len;
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

static int	_check_doubles(t_env *env)
{
	int	i;
	int	j;

	i = -1;
	while (++i < env->stack_size)
	{
		j = i;
		while (++j < env->stack_size)
		{
			if (ft_atoi(env->stack_str[i]) == ft_atoi(env->stack_str[j]))
				return (0);
		}
	}
	return (1);
}
