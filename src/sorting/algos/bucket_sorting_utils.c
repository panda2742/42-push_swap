/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sorting_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:44:43 by ehosta            #+#    #+#             */
/*   Updated: 2025/01/29 13:38:24 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"

static int	*_pos_in_stack(t_env *env, int *bucket_elements, int bucket_size);

int	*get_bucket_composition(t_env *env, int offset, int elt_per_bucket, int *pushed)
{
	int	*elements;
	int	i;

	elements = malloc((elt_per_bucket + 1) * sizeof(int));
	if (!elements)
		return (NULL);
	*pushed = 0;
	i = -1;
	while (++i < elt_per_bucket && (elt_per_bucket * offset + i) < env->a_size)
	{
		elements[i] = env->a_size - (elt_per_bucket * offset + i + 1);
		*pushed += 1;
	}
	elements[i] = -1;
	elements = _pos_in_stack(env, elements, *pushed);
	(void)_pos_in_stack;
	free(elements);
	return (elements);
}

static int	*_pos_in_stack(t_env *env, int *bucket_elements, int bucket_size)
{
	int	*positions;
	int	*distances;
	int	i;
	int head;
	int	size;

	positions = malloc((bucket_size + 1) * sizeof(int));
	if (!positions)
		return (NULL);
	distances = malloc((bucket_size + 1) * sizeof(int));
	if (!distances)
		return (free(positions), NULL);
	positions[bucket_size] = -1;
	i = -1;
	while (++i < bucket_size)
		positions[i] = getpos(env->stack_a, bucket_elements[i], env->a_size);
	i = -1;
	head = env->a_head;
	size = env->a_size;
	display_inttab(positions, bucket_size, 0);
	while (++i < bucket_size)
	{
		ft_printf("next elt: %d\tsize: %d\thead: %d\n", positions[i], size, head);
		distances[i] = distance_to_pos(size, head, positions[i]);
		head = positions[i];
		size--;
		if (head >= size)
			head = 0;
	}
	free(bucket_elements);
	free(positions);
	return (distances);
}

int	execute_bucket_distances(t_env *env, int *distances, int bucket_size, int emulation)
{
	int		i;
	int		sign;
	void	(*move)(t_env *, char, int);
	int		moves;

	i = -1;
	moves = 0;
	while (++i < bucket_size)
	{
		sign = ft_sign(distances[i]);
		move = reverse_rotate;
		if (sign == 1)
			move = rotate;
		while (ft_abs(distances[i]))
		{
			move(env, 'a', !emulation);
			moves++;
			distances[i] -= sign;
		}
		push(env, 'a', !emulation);
		moves++;
	}
	return (moves);
}