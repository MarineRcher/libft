/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marriche <marriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 10:05:04 by marriche          #+#    #+#             */
/*   Updated: 2026/11/23 18:24:44 by marriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!src && !dest)
		return (NULL);
	if (dest < src)
	{
		ft_memcpy(dest, src, n);
	}
	else
	{
		i = n - 2;
		while (i >= 0 && ((unsigned char *)src)[i])
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i--;
		}
	}
	return (dest);
}

// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
// 	char	dest[8] = {0};
// 		char	dest2[8] = {0};

// 	char	*r = ft_memmove(dest, "abcdef", 7);
// 	char	*r2 = memmove(dest2, "abcdef", 7);

// 	printf("%s\n", r);
// 	printf("%s\n", r2);
// 	printf("r->%lu\nr2->%lu", sizeof(r), sizeof(r2));
// }
