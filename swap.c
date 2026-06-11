/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduque-n <jduque-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 15:53:24 by lstarkov          #+#    #+#             */
/*   Updated: 2026/06/11 19:12:56 by jduque-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	swap(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->next = first;
	second->prev = NULL;
	first->prev = second;
	*stack = second;
}

void	sa(t_node **a, t_stats *s)
{
	swap(a);
	s->sa++;
	s->total++;
	write(1, "sa\n", 3);
}

void	sb(t_node **b, t_stats *s)
{
	swap(b);
	s->sb++;
	s->total++;
	write(1, "sb\n", 3);
}

void	ss(t_node **a, t_node **b, t_stats *s)
{
	swap(a);
	swap(b);
	s->ss++;
	s->total++;
	write(1, "ss\n", 3);
}
/*#include <stdio.h>

int	main(void)
{
	t_node *node1 = malloc(sizeof(t_node));
	t_node *node2 = malloc(sizeof(t_node));
	t_node *node3 = malloc(sizeof(t_node));

	t_stats stats = {0};

	node1->value = 10;
	node1->prev = NULL;
	node1->next = node2;

	node2->value = 20;
	node2->prev = node1;
	node2->next = node3;

	node3->value = 30;
	node3->prev = node2;
	node3->next = NULL;

	t_node	*stack_a = node1;
	
	printf("---Before sa --- \n");
	printf("Stack A: %d -> %d -> %d\n", stack_a->value, 
		stack_a->next->value, stack_a->next->next->value );
	
	sa(&stack_a, &stats);

	printf("\n ---- After sa ---\n");
	printf("Stack A: %d -> %d -> %d\n", stack_a->value, 
		stack_a->next->value, stack_a->next->next->value);
	printf("\nTotal operations tracked: %d\n", stats.total);

	free(node1);
	free(node2);
	free(node3);

	return(0);
}*/