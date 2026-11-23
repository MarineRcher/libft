/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marriche <marriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 11:58:16 by marriche          #+#    #+#             */
/*   Updated: 2026/11/18 15:02:16 by marriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

static size_t	ft_nb_len(long n)
{
	size_t	len;

	len = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	len++;
	return (len);
}

char	*ft_itoa(int n)
{
	char	*nb;
	long	nbr;
	size_t	i;

	nbr = n;
	i = ft_nb_len(nbr) + 1;
	nb = malloc(i * sizeof(char));
	if (nb == NULL)
		return (NULL);
	i--;
	if (nbr < 0)
	{
		nbr *= -1;
		nb[0] = '-';
	}
	nb[i] = '\0';
	i--;
	while (nbr > 9)
	{
		nb[i] = (nbr % 10) + '0';
		nbr /= 10;
		i--;
	}
	nb[i] = nbr + '0';
	return (nb);
}
