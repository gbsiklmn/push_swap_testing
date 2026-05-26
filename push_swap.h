/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstarkov <lstarkov@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 17:27:21 by lstarkov          #+#    #+#             */
/*   Updated: 2026/05/26 18:25:15 by lstarkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef	enum e_strategy
{
	STRAT_ADAPTIVE,
	STRAT_SIMPLE,
	STRAT_MEDIUM,
	STRAT_COMPLEX
}	t_strategy;

typedef	struct s_stats
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	total;
	int	bench;
	t_strategy	strat;
}	t_stats;

typedef	struct s_node
{
	int	value;
	int	index;
	struct s_node *next;
	struct s_node *prev;
} t_node;

/*CORE*/
t_node	*parse_input(int argc, char **argv, t_stats *stats);
void	apply_sorting(t_node **a, t_node **b, t_stats *stats);

/*STACK UTILS*/

t_node	*new_node(int value);
void	add_back(t_node **stack, t_node *new);
int		stack_size(t_node *stack);
void	free_stack(t_node **stack);
void	assign_index(t_node *a);

/*OPERATIONS*/
void	sa(t_node **a, t_stats *s);
void	sb(t_node**b, t_stats *s);
void	ss(t_node **a, t_node **b, t_stats *s);
void	pa(t_node **a, t_node **b, t_stats *s);
void	pb(t_node **a, t_node **b, t_stats *s);
void	ra(t_node **a, t_stats *s);
void	rb(t_node **b, t_stats *s);
void	rr(t_node **a, t_node **b, t_stats *s);
void	rra(t_node **a, t_stats *s);
void	rrb(t_node **b, t_stats *s);
void	rrr(t_node **a, t_node **b, t_stats *s);

/*ALGORITHMS*/
void	simple_sort(t_node **a, t_node **b, t_stats *s);
void	chunk_sort(t_node **a, t_node **b, t_stats *s);
void	radix_sort(t_node **a, t_node **b, t_stats *s);
void	sort_3(t_node **a, t_stats *s);

/*OUTPUT UTILS*/
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);

/*UTILS*/
long	get_inversions(t_node *a);
void	error_exit(void);
char	**ft_split(char const *s, char c);
void	free_split(char	**split);
int		ft_strcmp(const char *s1, const char *s2);
long	ft_atol(const char *str, int *error);
int		is_sorted(t_node *stack);

#endif
