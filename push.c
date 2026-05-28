/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstarkov <lstarkov@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 15:52:59 by lstarkov          #+#    #+#             */
/*   Updated: 2026/05/28 16:40:23 by lstarkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_node **src, t_node **dst)
{
	t_node	*tmp;

	if (!src || !*src)
		return ;
	tmp = *src;
	*src = tmp->next;
	if (*src)
		(*src)->prev = NULL;
	tmp->next = *dst;
	if(*dst)
		(*dst)->prev = tmp;
	*dst = tmp;
}

void	pa(t_node **a, t_node **b, t_stats *s)
{
	push(b, a);
	s->pa++;
	s->total++;
	write(1, "pa\n", 3);
}

void	pb(t_node **a, t_node **b, t_stats *s)
{
	push(a, b);
	s->pb++;
	s->total++;
	write(1, "pb\n", 3);
}

/*#include <stdio.h>

int	main(void)
{
	t_node *stack_a = malloc(sizeof(t_node));
	t_node *a_node2 = malloc(sizeof(t_node));
	t_node *stack_b = malloc(sizeof(t_node));

	t_stats stats = {0};
	
	stack_a->value = 1;
	stack_a->prev = NULL;
	stack_a->next = a_node2;

	a_node2->value = 2;
	a_node2->prev = stack_a;
	a_node2->next = NULL;

	stack_b->value = 3;
	stack_b->prev = NULL;
	stack_b->next = NULL;

	printf("Bfore pb\n");
	printf("Stack A: %d -> %d\n", stack_a->value, stack_a->next->value);
	printf("Stack B: %d\n\n", stack_b->value);

	// Verify stats updated
	pb(&stack_a, &stack_b, &stats);

	printf(" After pb\n");
	printf("Stack A top: %d\n", stack_a ? stack_a->value : -1);
	printf("Stack B top: %d, next: %d\n", stack_b->value, stack_b->next->value);
	
	printf("\nTotal operations tracked: %d\n", stats.total);

	free(stack_a);
	free(stack_b->next);
	free(stack_b);
	return (0);
}*/