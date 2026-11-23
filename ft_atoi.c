/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marriche <marriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 15:45:58 by marriche          #+#    #+#             */
/*   Updated: 2026/11/18 14:51:46 by marriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int		n;
	int		sign;

	sign = 0;
	n = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign++;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		n = (n * 10) + (*nptr - '0');
		nptr++;
	}
	if (sign == 1)
		return (-n);
	else if (sign == 0)
		return (n);
	else
		return (0);
}
