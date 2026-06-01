/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstarkov <lstarkov@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 15:53:21 by lstarkov          #+#    #+#             */
/*   Updated: 2026/05/29 15:15:21 by lstarkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	add_back(t_node **stack, t_node *new)
{
	t_node	*curr;
	
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	curr = *stack;
	while (curr->next)
		curr = curr->next;
	curr->next = new;
	new->prev = curr;
}

int	stack_size(t_node *stack)
{
	int i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

void	free_stack(t_node **stack)
{
	t_node	*tmp;

	while(*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

void	assign_index(t_node *a)
{
	t_node	*curr;
	t_node	*min_n;
	int		size;
	int		i;

	size = stack_size(a);
	i = 0;
	while (i < size)
	{
		curr = a;
		min_n = NULL;
		while (curr)
		{
			if (curr->index == -1 && (!min_n || curr->value < min_n->value))
				min_n = curr;
			curr = curr->next;
		}
		if (min_n)
			min_n->index = i++;
	}
}

/*#include <stdio.h>

int	main(void)
{
	t_node *stack_a = NULL;

	add_back(&stack_a, new_node(100));
	add_back(&stack_a, new_node(-50));
	add_back(&stack_a, new_node(42));

	printf("--- Initial Stack ---\n");
	printf("Stack size: %d\n", stack_size(stack_a));

	t_node *tmp = stack_a;
	while (tmp)
	{
		printf("Value: %4d | Index: %d\n", tmp->value, tmp->index);
		tmp = tmp->next;
	}
	assign_index(stack_a);
	
	printf("\n ---- After assing_index ---\n");
	tmp = stack_a;
	while (tmp)
	{
		printf("Value: %4d | Index: %d\n", tmp->value, tmp->index);
		tmp = tmp->next;
	}
	
	free_stack(&stack_a);
	
	printf("\n -- After free_stack --\n");
	if (stack_a == NULL)
		printf("Stack succefully freed and pointer is NULL\n");
	else
		printf("Memory leak aler. Stack pointer is not NULL\n");

	return (0);
}*/