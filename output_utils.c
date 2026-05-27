/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstarkov <lstarkov@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 15:52:50 by lstarkov          #+#    #+#             */
/*   Updated: 2026/05/27 16:28:33 by lstarkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
void	ft_putstr_fd(char *s, int fd)
{
	int i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;
	
	nb = n;
	if (nb < 0)
	{
		ft_putchar_fd('-'. fd);
		nb = -nb;
	}
	if (nb >= 10)
		ft_putchar_fd((int)(nb / 10), fd);
	ft_putchar_fd((char)((nb % 10) + '0'), fd);
}