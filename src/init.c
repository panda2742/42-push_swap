/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:05:29 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/04 18:58:52 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_push_swap	*create_push_swap(int argc, char **argv)
{
	t_push_swap	*push_swap;

	push_swap = malloc(sizeof(t_push_swap));
	if (!push_swap)
		return (NULL);
	push_swap->argc = argc;
	push_swap->argv = argv;
	push_swap->is_in_stackmem = true;
	push_swap->wall_status = WALL_OK;
	push_swap->env = NULL;
	return (push_swap);
}

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

	printf("%.*s", indents, SPACES);
	if (indents || is_first)
		printf("└—");
	else
		printf("  ");
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
	printf("\n");
	printf("%.*s│ Stacks:\n", indents + 2, SPACES);
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

void	display_stack_bucket(t_stack_buckets *sb)
{
	t_bucket	*b;
	int			i;
	int			j;

	printf(YELLOW "[STACK'S BUCKETS]\n" RESET);
	i = 0;
	if (sb->buckets)
	{
		b = sb->buckets[0];
		while (b)
		{
			printf("│ %d:\t", i);
			j = -1;
			while (++j < b->size)
				printf("%d ", b->composition[j]);
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

void	end_everything(t_push_swap *p, t_bool exit_program, int exit_status)
{
	t_stack	*elt;
	t_stack	*next;

	if (p->env)
	{
		if (!p->is_in_stackmem)
			free(p->env->stack_str);
		if (p->env->stacks)
		{
			elt = p->env->stacks[0];
			while (elt)
			{
				if (elt->tab)
					free(elt->tab);
				next = elt->next;
				free(elt);
				elt = next;
			}
			free(p->env->stacks);
		}
		free(p->env);
	}
	free(p);
	if (exit_program)
		exit(exit_status);
}
