/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstarkov <lstarkov@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 15:53:06 by lstarkov          #+#    #+#             */
/*   Updated: 2026/05/27 17:22:22 by lstarkov         ###   ########.fr       */
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
	write(1 "ra\n", 3);
}

void	rb(t_node **b, t_stats *s)
{
	rotate(b);
	s->rb++;
	s->total++;
	write(1, "rb\n", 3);
}

voide	rr(t_node **a, t_node **b, t_stats *s)
{
	rotate(a);
	rotate(b);
	s->rr++;
	s->total++;
	write(1, "rr\n", 3);
}