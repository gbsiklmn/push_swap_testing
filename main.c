/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstarkov <lstarkov@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 17:24:58 by lstarkov          #+#    #+#             */
/*   Updated: 2026/06/04 16:49:24 by lstarkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	init_stats(t_stats *stats)
{
	unsigned char	*p;
	size_t			i;

	p = (unsigned char *)stats;
	i = 0;
	while (i < sizeof(t_stats))
		p[i++] = 0;
	stats->strat = STRAT_ADAPTIVE;
}

void	print_disorder_and_strat(t_stats *s, long inv, int size)
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
	else if (s->strat == STRAT_SIMPLE)
		ft_putstr_fd("Simple / 0(n^2)\n", 2);
	else if (s->strat == STRAT_MEDIUM)
		ft_putstr_fd("Medium / 0(n\\sqrt(n))\n", 2);
	else
		ft_putstr_fd("Complex /0(n log n)\n", 2);
	ft_putstr_fd("total_ops: ", 2);
	ft_putnbr_fd(s->total, 2);
}
static	void print_ops_counts(t_stats *s)
{
	ft_putstr_fd("\nsa: ", 2);
	ft_putnbr_fd(s->sa, 2);
	ft_putstr_fd("\tsb: ", 2);
	ft_putnbr_fd(s->sb, 2);
	ft_putstr_fd("\tss: ", 2);
	ft_putnbr_fd(s->ss, 2);
	ft_putstr_fd("\tpa: ", 2);
	ft_putnbr_fd(s->pa, 2);
	ft_putstr_fd("\tpb: ", 2);
	ft_putnbr_fd(s->pb, 2);
	ft_putstr_fd("\nra: ", 2);
	ft_putnbr_fd(s->ra, 2);
	ft_putstr_fd("\trb: ", 2);
	ft_putnbr_fd(s->rb, 2);
	ft_putstr_fd("\trr: ", 2);
	ft_putnbr_fd(s->rr, 2);
	ft_putstr_fd("\trra: ", 2);
	ft_putnbr_fd(s->rra, 2);
	ft_putstr_fd("\trrb: ", 2);
	ft_putnbr_fd(s->rrb, 2);
	ft_putstr_fd("\trrr: ", 2);
	ft_putnbr_fd(s->rrr, 2);
	ft_putstr_fd("\n", 2);
}

static	void print_bench(t_stats *s, long inv, int size)
{
	print_disorder_and_strat(s, inv, size);
	print_ops_counts(s);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	t_stats stats;
	long	initial_inv;
	int		initial_size;

	if (argc < 2)
		return (0);
	init_stats(&stats);
	a = parse_input(argc, argv, &stats);
	if (!a)
		return (0);
	initial_inv = get_inversions(a);
	initial_size = stack_size(a);
	b = NULL;
	apply_sorting(&a, &b, &stats);
	if (stats.bench)
		print_bench(&stats, initial_inv, initial_size);
	free_stack(&a);
	free_stack(&b);
	return (0);
}