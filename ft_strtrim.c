/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marriche <marriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 17:23:04 by marriche          #+#    #+#             */
/*   Updated: 2026/11/25 17:29:45 by marriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"
#include <stdlib.h>

static int	ft_is_set(char const c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s;
	size_t	start;
	size_t	end;
	size_t	i;

	i = 0;
	start = 0;
	end = ft_strlen(s1);
	while (ft_is_set(s1[start], set) && s1[start])
		start++;
	while (ft_is_set(s1[end - 1], set) && end > start)
		end--;
	s = malloc((end - start + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);
	while (start < end)
	{
		s[i] = s1[start];
		start++;
		i++;
	}
	s[i] = '\0';
	return (s);
}
