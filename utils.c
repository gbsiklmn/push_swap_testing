/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstarkov <lstarkov@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 15:53:26 by lstarkov          #+#    #+#             */
/*   Updated: 2026/06/04 17:02:54 by lstarkov         ###   ########.fr       */
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

/*#include <stdio.h>

void test_atol(const char *str, long expected_val, int expected_err)
{
    int  error;
    long res;

    res = ft_atol(str, &error);
    printf("Input: '%s' | Got: %ld, Error: %d | Expected: %ld, Error: %d -> %s\n",
           str, res, error, expected_val, expected_err,
           (res == expected_val && error == expected_err) ? "SUCCESS" : "FAIL");
}

int	main(void)
{
	printf("---Testing ft_strcmp\n");
	printf("Same strings('abc', 'abc'): %d (Expected: 0)\n", ft_strcmp("abc", "abc"));
	printf("S1 greater ('abd', 'abc'): %d (Expected: >0)\n", ft_strcmp("abd", "abc"));
	printf("S2 greater ('abc', 'abd'): %d (Expected: <0)\n\n", ft_strcmp("abc", "abd"));
	
	printf("===Testing is_sorted ---\n");
	t_node *n1 = malloc(sizeof(t_node));
	t_node *n2 = malloc(sizeof(t_node));
	t_node *n3 = malloc(sizeof(t_node));

	n1->value = 10; n1->next = n2;
	n2->value = 20; n2->next = n3;
	n3->value = 30; n3->next = NULL;
	printf("Testing sorted stack: %d (Expected: 1)\n", is_sorted(n1));

	n2->value = 35;
	printf("Testing unsorted stack: %d (Expected: 0)\n\n", is_sorted(n1));

	free(n1); free(n2); free(n3);

	printf("=== Testing ft_atol & Overflows ==\n");
	test_atol("42", 42, 0);
	test_atol("   -123", -123, 0);
	test_atol("0", 0, 0);

	test_atol("2147483647", 2147483647, 0);
	test_atol("2147483648", 0, 1);
	test_atol("-2147483648", -2147483648, 0);
	test_atol("-2147483649", 0, 1);
	test_atol("05", 0, 1);
	test_atol("+5", 0, 1);
	test_atol("42a", 0, 1);

	printf("\n====Testing error_exit----\n");
	printf("Executing error_exit now. The program should print 'Error' and exit immediately:\n ");
	
	error_exit();
	printf("If you see this line, error_exit failed to terminate the program\n");
	return (0);
}*/