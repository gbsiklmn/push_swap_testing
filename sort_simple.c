/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstarkov <lstarkov@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 15:53:18 by lstarkov          #+#    #+#             */
/*   Updated: 2026/06/02 16:56:05 by lstarkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_node **a, t_stats *s)
{
	int	f;
	int	m;
	int	l;

	f = (*a)->value;
	m = (*a)->next->value;
	l = (*a)->next->next->value;
	if (f > m && m < l && f < l)
		sa(a, s);
	else if (f > m && m > l)
	{
		sa(a, s);
		rra(a, s);
	}
	else if (f > m && m < l && f > l)
		ra(a, s);
	else if (f < m && m > l && f < l)
	{
		sa(a, s);
		ra(a, s);
	}
	else if (f < m && m > l && f > l)
		rra(a, s);
}

static	int	get_min_pos(t_node *a)
{
	t_node	*tmp;
	int		min;
	int		pos;
	int		i;

	tmp = a;
	min = tmp->value;
	pos = 0;
	i = 0;
	while (tmp)
	{
		if (tmp->value < min)
		{
			min = tmp->value;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (pos);
}

static	void	push_min(t_node **a, t_node **b, t_stats *s)
{
	int	pos;
	int	size;

	pos = get_min_pos(*a);
	size = stack_size(*a);
	if (pos <= size / 2)
	{
		while (pos --)
			ra(a, s);
	}
	else
	{
		pos = size - pos;
		while (pos --)
			rra(a, s);
	}
	pb(a, b, s);
}

void	simple_sort(t_node **a, t_node **b, t_stats *s)
{
	int	size;

	size = stack_size(*a);
	if (size == 2)
		sa(a, s);
	else if (size == 3)
		sort_3(a, s);
	else
	{
		while (stack_size(*a) > 3)
			push_min(a, b, s);
		sort_3(a, s);
		while (*b)
			pa(a, b, s);
	}
}

/*#include <stdio.h>

int	main(void)
{
	t_node *n1 = malloc(sizeof(t_node));
	t_node *n2 = malloc(sizeof(t_node));
	t_node *n3 = malloc(sizeof(t_node));
	t_node *n4 = malloc(sizeof(t_node));
	t_node *n5 = malloc(sizeof(t_node));

	t_stats	stats = {0};
	
	n1->value = 4; n1->prev = NULL; n1->next = n2;
	n2->value = 2; n2->prev = n1; n2->next = n3;
	n3->value = 5; n3->prev = n2; n3->next = n4;
	n4->value = 1; n4->prev = n3; n4->next = n5;
	n5->value = 3; n5->prev = n4; n5->next = NULL;

	t_node *stack_a = n1;
	t_node *stack_b = NULL;

	printf("--Before simple_sort \n");
	t_node *tmp = stack_a;
	printf("Stack A: ");
	while (tmp)
	{
		printf("%d ", tmp->value);
		tmp = tmp->next;
	}
	printf("\n\n");

	simple_sort(&stack_a, &stack_b, &stats);

	printf("--- After simple_sort --\n");
	tmp = stack_a;
	printf("Stack A: ");
	while (tmp)
	{
		printf("%d ", tmp->value);
		tmp = tmp->next;
	}
	printf("\n\n Total operations tracked: %d\n", stats.total);
	tmp = stack_a;
	while (tmp)
	{
		t_node *next = tmp->next;
		free(tmp);
		tmp  = next;
	}
}*/
