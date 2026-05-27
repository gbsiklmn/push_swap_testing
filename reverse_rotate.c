/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstarkov <lstarkov@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 15:53:03 by lstarkov          #+#    #+#             */
/*   Updated: 2026/05/27 17:15:15 by lstarkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void rev_rotate(t_node **stack)
{
	t_node	*last;

	if (!stack || !*stack || (*stack)->next)
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