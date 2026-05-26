/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstarkov <lstarkov@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 17:24:58 by lstarkov          #+#    #+#             */
/*   Updated: 2026/05/26 18:42:44 by lstarkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	init_stats(t_stats *stats)
{
	unsigned char	*p;
	size_t	i;

	p = (unsigned char *)stats;
	i = 0;
	while (i < sizeof(t_stats))
		p[i++] = 0;
	stats->strat = STRAT_ADAPTIVE;
}

static	void print_disorder_and_strat(t_stats *s, long inv, int size);
{
	long	max_inv;
	long	disorder;

	max_inv = (long)size * (size - 1) / 2;
	disorder = 0;
	if (max_inv > 0)
		disorder = (inv * 10000) / max_inv;
	ft_putstr_fd("disorder: ", 2);
	ft_putnbr_fd((int)(disorder / 100), 2);
	ft_putstr_fd(".", 2);
	if (disorder % 100 < 10)
		ft_putstr_fd("0", 2);
	ft_putnbr_fd((int)(disorder % 100), 2);
	ft_putstr_fd("%\nstrategy: ", 2);
	if (s->strat == STRAT_ADAPTIVE)
		ft_putstr_fd("Adaptive / 0(n\\sqrt(n))\n", 2);
	else if (s->strat == STRAT_ADAPTIVE)
		ft_putchar_fd("Simple / 0(n^2)\n", 2);
	else if (s->strat == STRAT_MEDIUM)
		ft_putstr_fd("Medium / 0(n\\sqrt(n))\n", 2);
	else
		ft_putstr_fd("Complex /0(n log n)\n", 2);
	ft_putnbr_fd("total_ops: ", 2);
	ft_putnbr_fd(s->total, 2);
}