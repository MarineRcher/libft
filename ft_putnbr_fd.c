/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marriche <marriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 15:21:40 by marriche          #+#    #+#             */
/*   Updated: 2026/11/18 15:03:23 by marriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;
	char	c;

	nb = n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb *= -1;
	}
	c = (nb % 10) + '0';
	if (nb <= 9)
	{
		write(fd, &c, 1);
		return ;
	}
	ft_putnbr_fd(nb / 10, fd);
	write(fd, &c, 1);
}
