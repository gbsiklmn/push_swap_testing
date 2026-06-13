/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstarkov <lstarkov@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 15:52:53 by lstarkov          #+#    #+#             */
/*   Updated: 2026/06/13 17:27:59 by lstarkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	handle_flags(char *arg, t_stats *stats)
{
	if (ft_strcmp(arg, "--simple") == 0)
		stats->strat = STRAT_SIMPLE;
	else if (ft_strcmp(arg, "--medium") == 0)
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

static	void	check_duplicates(t_node **stack)
{
	t_node	*i;
	t_node	*j;

	i = *stack;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->value == j->value)
				error_exit(stack);
			j = j->next;
		}
		i = i->next;
	}
}

static	int	process_arg(char *arg, t_node **a)
{
	char	**nums;
	int		err;
	int		j;
	long	val;
	t_node	*node;

	nums = ft_split(arg, ' ');
	if (!nums || !nums[0])
		return (error_exit(a), -1);
	j = 0;
	while (nums[j])
	{
		val = ft_atol(nums[j], &err);
		if (err)
			return (free_split(nums), error_exit(a), -1);
		node = new_node((int)val);
		if (!node)
			return (free_split(nums), error_exit(a), -1);
		add_back(a, node);
		j++;
	}
	free_split(nums);
	return (0);
}

t_node	*parse_input(int argc, char **argv, t_stats *stats)
{
	t_node	*a;
	int		i;

	a = NULL;
	i = 0;
	while (++i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
		{
			if (!handle_flags(argv[i], stats))
				error_exit(&a);
			continue ;
		}
		process_arg(argv[i], &a);
	}
	if (a)
		check_duplicates(&a);
	return (a);
}

/*#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stats	stats = {0};
	t_node *stack_a = NULL;
	t_node *tmp;

	if (argc < 2)
	{
		printf("Please provide numbers to test\n");
		return (0);
	}

	stack_a = parse_input(argc, argv, &stats);
	
	printf("---Passed Stack A---\n");
	tmp = stack_a;
	while (tmp)
	{
		printf("Value: %d\n", tmp->value);
		tmp = tmp->next;
	}

	printf("\n ---- Passed Flags ---\n");
	printf("Strategy Set to: %d\n", stats.strat);
	printf("Benchmark Mode: %d\n", stats.bench);

	free_stack(&stack_a);
	return (0);
}*/