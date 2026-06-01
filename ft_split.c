/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstarkov <lstarkov@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 15:52:40 by lstarkov          #+#    #+#             */
/*   Updated: 2026/06/01 14:31:22 by lstarkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(const char *s, char c)
{
	int count;
	int in;

	count = 0;
	in = 0;
	while(*s)
	{
		if (*s != c && !in)
		{
			in = 1;
			count++;
		}
		else if (*s == c)
			in = 0;
		s++;
	}
	return (count);
}

static char *ft_strndup(const char *s, int n)
{
	char	*str;
	int	i;

	str = malloc(n + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < n)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		len;

	if (!s)
		return (NULL);
	res = malloc(sizeof(char *) * (count_words(s, c) +1));
	if (!res)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			len = 0;
			while (s[len] && s[len] != c)
				len++;
			res[i++] = ft_strndup(s, len);
			s += len;
		}
	}
	res[i] = NULL;
	return (res);
}

void	free_split(char **split)
{
	int i;

	i = 0;
	if (!split)
		return ;
	while (split[i])	
		free(split[i++]);
	free(split);
	
}