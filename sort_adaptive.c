/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstarkov <lstarkov@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 15:53:10 by lstarkov          #+#    #+#             */
/*   Updated: 2026/06/02 14:53:26 by lstarkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void run_adaptive(t_node **a, t_node **b, t_stats *s, int size)
{
	long	inv;
	long	max_inv;

	inv = get_inversions(*a);
	max_inv = (long)size * (size - 1) / 2;
	if (size <= 10 || (max_inv >0 && inv < max_inv / 5))
	{
		s->strat = STRAT_SIMPLE;
		simple_sort(a, b, s);
	}
	else if (max_inv >0 && inv < max_inv / 2)
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
		return;
	size = stack_size(*a);
	if (size < 2)
		return;
	if (s->strat == STRAT_SIMPLE)
		simple_sort(a, b, s);
	else if (s->strat == STRAT_MEDIUM)
		chunk_sort(a, b, s);
	else if (s->strat == STRAT_COMPLEX)
		radix_sort(a, b, s);
	else
		run_adaptive(a, b, s, size);
}