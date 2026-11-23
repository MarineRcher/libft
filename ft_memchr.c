/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marriche <marriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 14:12:13 by marriche          #+#    #+#             */
/*   Updated: 2026/11/23 14:19:59 by marriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (((unsigned char *)s)[i] && i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char) c)
			return ((void *)s);
		i++;
	}
	if (((unsigned char *)s)[i] == (unsigned char) c && i < n)
		return ((void *)s);
	return (NULL);
}
