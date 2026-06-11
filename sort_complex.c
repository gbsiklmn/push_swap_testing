/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduque-n <jduque-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 15:53:13 by lstarkov          #+#    #+#             */
/*   Updated: 2026/06/11 19:12:31 by jduque-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_node **a, t_node **b, t_stats *s)
{
	int	size;
	int	max_bits;
	int	i;
	int	j;

	assign_index(*a);
	size = stack_size(*a);
	max_bits = 0;
	while (((size - 1) >> max_bits) != 0)
		max_bits++;
	i = -1;
	while (++i < max_bits)
	{
		j = -1;
		while (++j < size)
		{
			if ((((*a)->index >> i) & 1) == 1)
				ra(a, s);
			else
				pb(a, b, s);
		}
		while (*b)
			pa(a, b, s);
	}
}

/*#include <stdio.h>

void	print_stack(t_node *stack, const char *name)
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

int	main(void)
{
	t_node *a = NULL;
	t_node *b = NULL;
	t_stats stats = {0};

	int	nums[] = {42, -5, 12, 88, 1, 99, -10, 3, 15, 77, 2, 8, 
		23, 64, -30, 50, 4, 9, 11, -1, 100, 200, -50, 0, 7};
	int i = 0;

	while (i < 25)
	{
		add_back(&a, new_node(nums[i]));
		i++;
	}
	
	printf("---- Before radix_sort ---\n");
	print_stack(a, "A");

	stats.bench = 1;

	radix_sort(&a, &b, &stats);
	
	printf("\n --- After radix_sort---\n");
	print_stack(a, "A");
	
	printf("\n----- Algorithn Stats ---\n");
	printf("Total Operations: %d\n", stats.total);
	if (is_sorted(a))
		printf("Result: Success! Stack A is perfectly sorted\n");
	else
		printf("Result: Fail! Stack A is not sorted\n");
	
	free_stack(&a);
	free_stack(&b);

	return (0);
	
}*/
