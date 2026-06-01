/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstarkov <lstarkov@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 15:53:03 by lstarkov          #+#    #+#             */
/*   Updated: 2026/06/01 15:50:58 by lstarkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void rev_rotate(t_node **stack)
{
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = *stack;
	while (last->next)
		last = last->next;
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	(*stack)->prev = last;
	*stack = last;
}

void	rra(t_node **a, t_stats *s)
{
	rev_rotate(a);
	s->rra++;
	s->total++;
	write(1, "rra\n", 4);
}

void	rrb(t_node **b, t_stats *s)
{
	rev_rotate(b);
	s->rrb++;
	s->total++;
	write(1, "rrb\n", 4);
}

void	rrr(t_node **a, t_node **b, t_stats *s)
{
	rev_rotate(a);
	rev_rotate(b);
	s->rrr++;
	s->total++;
	write(1, "rrr\n", 4);
}

/*#include <stdio.h>

int	main(void)
{
	t_node *node1 = malloc(sizeof(t_node));
	t_node *node2 = malloc(sizeof(t_node));
	t_node *node3 = malloc(sizeof(t_node));

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

	t_node *stack_a = node1;

	printf("---Before rra ---\n");
	printf("Stack A: %d -> %d - > %d\n", stack_a->value, stack_a->next->value, stack_a->next->next->value);
	rra(&stack_a, &stats);

	printf("\n --- After rra --\n");
	if (stack_a && stack_a->next && stack_a->next->next)
	{
		printf("Stack A: %d -> %d -> %d\n", stack_a->value, stack_a->next->value, stack_a->next->next->value);
	}
	else
	{
		printf("Oops, your stack pointers are broken or empty\n");	
	}
	
	printf("\nTotal operations tracked: %d\n", stats.total);

	free(node1);
	free(node2);
	free(node3);

	return(0);
}*/