/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marriche <marriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 10:28:02 by marriche          #+#    #+#             */
/*   Updated: 2026/11/25 09:50:36 by marriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	j;
	size_t	len_src;

	len_dst = 0;
	j = 0;
	len_src = ft_strlen(src);
	while (len_dst < size && dst[len_dst])
		len_dst++;
	if (size <= len_dst)
		return (size + len_src);
	while (src[j] && len_dst + j < size - 1)
	{
		dst[len_dst + j] = src[j];
		j++;
	}
	dst[len_dst + j] = '\0';
	return (len_dst + len_src);
}
