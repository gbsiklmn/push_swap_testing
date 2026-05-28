/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstarkov <lstarkov@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 15:53:06 by lstarkov          #+#    #+#             */
/*   Updated: 2026/05/28 16:58:10 by lstarkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return;
	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = first->next;
	(*stack)->prev = NULL;
	first->next = NULL;
	first->prev = last;
	last->next = first;
}

void	ra(t_node **a, t_stats *s)
{
	rotate(a);
	s->ra++;
	s->total++;
	write(1, "ra\n", 3);
}

void	rb(t_node **b, t_stats *s)
{
	rotate(b);
	s->rb++;
	s->total++;
	write(1, "rb\n", 3);
}

void	rr(t_node **a, t_node **b, t_stats *s)
{
	rotate(a);
	rotate(b);
	s->rr++;
	s->total++;
	write(1, "rr\n", 3);
}

#include <stdio.h>

int	main(void)
{
	t_node	*node1 = malloc(sizeof(t_node));
	t_node	*node2 = malloc(sizeof(t_node));
	t_node	*node3 = malloc(sizeof(t_node));

	t_stats	stats = {0};

	node1->value = 1;
	node1->prev = NULL;
	node1->next = node2;
	
	node2->value = 2;
	node2->prev = node1;
	node2->next = node3;
	
	node3->value = 3;
	node3->prev = node2;
	node3->next = NULL;

	t_node	*stack_a = node1;
	
	printf("Before ra");
	printf("Stack A; %d -> %d -> %d\n", stack_a->value, stack_a->next->value, stack_a->next->next->value);
	
	ra(&stack_a, &stats);
	
	printf("\n Total operations tracked: %d\n", stats.total);

	free(node1);
	free(node2);
	free(node3);

	return(0);
}