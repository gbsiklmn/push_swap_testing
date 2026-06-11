/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduque-n <jduque-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 15:53:10 by lstarkov          #+#    #+#             */
/*   Updated: 2026/06/11 16:21:24 by jduque-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	run_adaptive(t_node **a, t_node **b, t_stats *s, int size)
{
	long	inv;
	long	max_inv;

	inv = get_disorder(*a);
	max_inv = (long)size * (size - 1) / 2;
	if (size <= 10 || (max_inv > 0 && inv < max_inv / 5))
	{
		s->strat = STRAT_SIMPLE;
		simple_sort(a, b, s);
	}
	else if (max_inv > 0 && inv < max_inv / 2)
	{
		s->strat = STRAT_MEDIUM;
		chunk_sort(a, b, s);
	}
	else
	{
		s->strat = STRAT_COMPLEX;
		radix_sort(a, b, s);
	}
}

void	apply_sorting(t_node **a, t_node **b, t_stats *s)
{
	int	size;

	if (is_sorted(*a))
		return ;
	size = stack_size(*a);
	if (size < 2)
		return ;
	if (s->strat == STRAT_SIMPLE)
		simple_sort(a, b, s);
	else if (s->strat == STRAT_MEDIUM)
		chunk_sort(a, b, s);
	else if (s->strat == STRAT_COMPLEX)
		radix_sort(a, b, s);
	else
		run_adaptive(a, b, s, size);
}

/*#include <stdio.h>

t_node *build_stack(int	*arr, int size)
{
	t_node *stack = NULL;
	int i = 0;
	while (i < size)
	{
		add_back(&stack, new_node(arr[i]));
		i++;
	}
	return stack;
}

void print_strategy(int strat)
{
	if (strat == STRAT_SIMPLE)
		printf(" -> Manager Chose: Simple sort\n");
	else if (strat == STRAT_MEDIUM)
		printf(" -> Manager Chose: Chunk Sort\n");
	else if (strat == STRAT_COMPLEX)
		printf(" -> Manager Chose: Radix Sort\n");
	else
		printf("-> Manager Chose: Unknown\n");
}

int	main(void)
{
	t_node *a;
	t_node *b = NULL;
	t_stats stats;
	
	printf("=== Testing Adaptive Dispatcher == \n\n");
	
	int	arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 11};
	a = build_stack(arr1, 12);

	stats = (t_stats){0};
	stats.bench = 1;

	printf("Test 1: Nearly Sorted Array...\n");
	apply_sorting(&a, &b, &stats);
	print_strategy(stats.strat);
	free_stack(&a);

	int	arr2[] = {5, 6, 7, 8, 1, 2, 3, 4, 12, 11, 10, 9};
	a = build_stack(arr2, 12);
	
	stats = (t_stats){0};
	stats.bench = 1;

	printf("\nTest 2: Moderately Scrambled Array..\n");
	apply_sorting(&a, &b, &stats);
	print_strategy(stats.strat);
	free_stack(&a);

	int	arr3[] = {12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	a = build_stack(arr3, 12);

	stats = (t_stats){0};
	stats.bench = 1;

	printf("\nTest 3: Completely Reversed Array...\n");
	apply_sorting(&a, &b, &stats);
	print_strategy(stats.strat);
	free_stack(&a);
	return (0);
}*/
