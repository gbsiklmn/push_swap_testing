/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstarkov <lstarkov@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 15:53:26 by lstarkov          #+#    #+#             */
/*   Updated: 2026/06/01 14:51:44 by lstarkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
static long	parse_digits(const char *str, int s, int *error)
{
	long	res;
	int		dig;

	res = 0;
	dig = 0;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str++ - '0');
		dig = 1;
		if ((s * res) > 2147483647 || (s * res) < -2147483648)
		{
			*error = 1;
			return (0);
		}
	}
	if (!dig || *str != '\0' || (res == 0 && s == -1))
	{
		*error = 1;
		return (0);
	}
	return (res * s);
}

long	ft_atol(const char *str, int *error)
{
	int s;
	s = 1;
	*error = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
	{
		s = -1;
		str++;
	}
	else if (*str == '+')
	{
		*error = 1;
		return (0);
	}
	if (*str == '0' && str[1] != '\0' && str[1] != ' ')
	{
		*error = 1;
		return (0);
	}
	return (parse_digits(str, s, error));
}

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

#include <stdio.h>

void	test_atol(const char *str, long expected_val, int expected_err)
{
	int	error;
	long res;
	
	res = ft_atol(str, &error);
	printf("Input: '%s' | Got: %ld, Error: %d | Expected: %ld, Error: %d -> %s\n",
			str, res, error, expected_val, expected_err, (res == expected_val && error = expected_err) ? "SUCCESS": "FAIL");
}