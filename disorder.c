/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstarkov <lstarkov@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 15:48:53 by lstarkov          #+#    #+#             */
/*   Updated: 2026/06/09 15:24:02 by lstarkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	get_disorder(t_node *a)
{
	long	inv;
	t_node	*i;
	t_node	*j;

	inv = 0;
	i = a;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->value > j->value)
				inv++;
			j = j->next;
		}
		i = i->next;
	}
	return (inv);
}

/*#include <stdio.h>

int	main(void)
{
	t_node	*node1;
	t_node	*node2;
	t_node	*node3;
	long	mistakes;

	node1 = malloc(sizeof(t_node));
	node2 = malloc(sizeof(t_node));
	node3 = malloc(sizeof(t_node));

	node1->value = 3;
	node1->next = node2;
	
	node2->value = 1;
	node2->next = node3;

	node3->value = 2;
	node3->next = NULL;

	mistakes = get_inversions(node1);
	printf("testing stack: 3, 1, 2\n");
	printf("total inversions found: %ld\n", mistakes);
	printf("expected inversions: 2 (3>1 and 3>2)\n");

	free(node1);
	free(node2);
	free(node3);

	return(0);
}*/