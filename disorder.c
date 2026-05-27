/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstarkov <lstarkov@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 15:48:53 by lstarkov          #+#    #+#             */
/*   Updated: 2026/05/27 15:55:43 by lstarkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	get_inverstions(t_node *a)
{
	long	inv;
	t_node	*i;
	t_node	*j;

	inv = 0;
	i = a;
	while(i)
	{
		j = i->next;
		while(j)
		{
			if (i->value > j->value)
				inv++;
			j = j->next;
		}
		i = i->next;
	}
	return (inv);
}