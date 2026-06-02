/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstarkov <lstarkov@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 15:53:15 by lstarkov          #+#    #+#             */
/*   Updated: 2026/06/02 18:46:26 by lstarkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_pos(t_node *b)
{
	t_node	*curr;
	int		max_pos;
	int		max_val;
	int		mi;

	max_pos = 0;
	mi = 0;
	max_val = -1;
	curr = b;
	while (curr)
	{
		if (curr->index > max_val)
		{
			max_val = curr->index;
			max_pos = mi;
		}
		curr = curr->next;
		mi++;
	}
	return (max_pos);
}
static void push_back(t_node **a, t_node **b, t_stats *s)
{
	int	max_pos;
	int size;
	
	while (stack_size(*b))
	{
		max_pos = get_max_pos(*b);
		size = stack_size(*b);
		if (max_pos <= size / 2)
		{
			while (max_pos--)
				rb(b, s);
		}
		else
		{
			max_pos = size - max_pos;
			while (max_pos--)
				rrb(b, s);	
		}
		pa(a, b, s);
	}
}

void	chunk_sort(t_node **a, t_node **b, t_stats *s)
{
	int	chunk;
	int i;
	
	i = 0;
	assign_index(*a);
	chunk = 35;
	if (stack_size(*a) <= 100)
		chunk = 15;
	while ( (*a))
	{
		if ((*a)->index <= i)
		{
			pb(a, b, s);
			rb(b, s);
			i++;
		}
		else if ((*a)->index <= i + chunk)
		{
			pb(a, b, s);
			i++;
		}
		else
			ra(a, s);
	}
	push_back(a, b, s);	
}

#include <stdio.h>

void print_stack(t_node *stack, const char *name)
{
	printf("Stack %s: ", name);
	if (!stack)
		printf("(empty)");
	while (stack)
	{
		printf("%d ", stack->value);
		stack = stack->next;
	}
	printf("\n");
}
/*
int	main(void)
{
	t_node	*a = NULL;
	t_node	*b = NULL;
	t_stats stats = {0};

	int	nums[] = {42, -5, 12, 88, 1, 99, -10, 3, 15, 77, 2, 8, 23, 64, -30, 50, 4, 9, 11, -1};
	int	i = 0;

	while (i < 20)
	{
		add_back(&a, new_node(nums[i]));
		i++;
	}
	printf("----Before chunk_sort---\n");
	print_stack(a, "A");
	print_stack(b, "B");

	stats.bench = 1;
	chunk_sort(&a, &b, &stats);
	
	printf("\n---- After chunk_sort---\n");
	print_stack(a, "A");
	print_stack(b, "B");
	
	printf("\n---- Algorithm Stats ---\n");
	printf("Total Operations: %d\n", stats.total);
	if (is_sorted(a))
		printf("Result: Success! Stack A is perfectly sorted.\n");
	else
		printf("Result: FAIL! Stack A is not sorted\n");
	
	free_stack(&a);
	free_stack(&b);
	return (0);
}	*/