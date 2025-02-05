/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 21:27:02 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/05 17:23:58 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	display_stack(t_stack *s, int indents, t_bool is_first)
{
	int	i;

	printf("%.*s", indents, SPACES);
	if (indents && is_first)
		printf("└—");
	else
		printf("  ");
	printf(BLUE "[Stack %p {%c}]\n" RESET, s, s->identifier);
	printf("%.*s│ Head:\t%d\n", indents + 2, SPACES, s->head);
	printf("%.*s│ Size:\t%d\n", indents + 2, SPACES, s->size);
	printf("%.*s│ Content:\t", indents + 2, SPACES);
	i = -1;
	while (++i < s->size)
		printf("%d ", getval(s, s->head, i));
	printf("\n");
	printf("%.*s└ Next:\t%p\n", indents + 2, SPACES, s->next);
}

void	display_env(t_env *e, int indents, t_bool is_first)
{
	int		i;
	t_stack	*s;
	t_move	*flow;

	if (indents || is_first)
		printf("%.*s└—", indents, SPACES);
	else
		printf("%.*s", indents + 2, SPACES);
	printf(GREEN "[Environment %p]\n" RESET, e);
	printf("%.*s│ Is a copy: ", indents + 2, SPACES);
	if (e->is_copy)
		printf(GREEN "true\n" RESET);
	else
		printf(RED "false\n" RESET);
	printf("%.*s│ Stack size:\t%d\n", indents + 2, SPACES, e->stack_size);
	printf("%.*s│ Content:\t", indents + 2, SPACES);
	i = -1;
	while (++i < e->stack_size)
		printf("%s ", e->stack_str[i]);
	printf("\n%.*s│ Resolutions:\n%.*s│ ", indents + 2, SPACES, indents + 2, SPACES);
	flow = e->moves[0];
	while (flow)
	{
		printf("%s ", move_str(flow->move));
		flow = flow->next;
	}
	printf("\n%.*s│ Stacks:\n", indents + 2, SPACES);
	s = e->stacks[0];
	while (s)
	{
		display_stack(s, indents + 2, (int)(s == e->stacks[0]));
		s = s->next;
	}
}

void	display_push_swap(t_push_swap *p)
{
	printf(MAGENTA "[Push Swap %p]\n" RESET, p);
	printf("%.*s│ Stack in heap memory: ", 0, SPACES);
	if (!p->is_in_stackmem)
		printf(GREEN "true\n" RESET);
	else
		printf(RED "false\n" RESET);
	printf("%.*s│ Wall status:\t%d\n", 0, SPACES, p->wall_status);
	display_env(p->env, 0, true);
}

void	display_stack_buckets(t_stack_buckets *sb)
{
	t_bucket	*b;
	int			i;
	int			j;

	printf(YELLOW "[STACK'S BUCKETS]\n" RESET);
	printf("│ Moves:\t%d\n", sb->total_moves);
	i = 0;
	if (sb->buckets)
	{
		b = sb->buckets[0];
		while (b)
		{
			printf("│     %d:\t", i);
			j = -1;
			while (++j < b->size)
				printf("%*.s%d ", b->composition[j] < 10, SPACES, b->composition[j]);
			printf("\n");
			b = b->next;
			i++;
		}
	}
	if (!sb->buckets)
		printf("└ ");
	if (!sb->buckets)
		printf(RED "[No buckets]\n" RESET);
}
