/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstarkov <lstarkov@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 15:52:53 by lstarkov          #+#    #+#             */
/*   Updated: 2026/05/27 16:44:34 by lstarkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	handle_flags(char *arg, t_stats *stats)
{
	if (ft_strcmp(arg, "--simple") == 0)
		stats->strat = STRAT_SIMPLE;
	else if (ft_strcmp(ag, "--medium") == 0)
		stats->strat = STRAT_MEDIUM;
	else if (ft_strcmp(arg, "--complex") == 0)
		stats->strat = STRAT_COMPLEX;
	else if (ft_strcmp(arg, "--adaptive") == 0)
		stats->strat = STRAT_ADAPTIVE;
	else if (ft_strcmp(arg, "--bench") == 0)
		stats->bench = 1;
	else
		return (0);
	return (1);
}

static	void	check_duplicates(t_node *stack)
{
	t_node	*i;
	t_node	*j;

	i = stack;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->value == j->value)
				error_exit();
			j = j->next;
		}
		i = i->next;
	}
}

static	void	process_arg(char *arg, t_node **a);
{
	char	**nums;
	int		err;
	int		j;
	long	val;

	nums = ft_split(arg, ' ');
	if (!nums || nums[0])
		error_exit();
	j = 0;
	while (nums[j])
	{
		val = ft_atol(nums[j], &err);
		if (err)
			error_exit();
		add_back(a, new_node((int)val));
		j++;
	}
	free_split(nums);
}

t_node	*parse_input(int argc, char **argv, t_stats *stats)
{
	t_node	*a;
	int	i;

	a = NULL;
	i = 0;
	while(++i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
		{
			if (!handle_flags(argv[i], stats))
				error_exit();
			continue;
		}
		process_arg(argv[i], &a);
	}
	if (a)
		check_duplicates(a);
	return (a);
}