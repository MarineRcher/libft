/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marriche <marriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 17:23:04 by marriche          #+#    #+#             */
/*   Updated: 2026/11/18 14:36:37 by marriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"
#include <stdlib.h>

static int	ft_is_set(char const *s1, char const *set, size_t position_s1)
{
	size_t	i;

	i = 0;
	while (s1[position_s1] == set[i] && s1[position_s1])
	{
		if (set[i + 1] == '\0')
			return (1);
		i++;
		position_s1++;
	}
	return (0);
}

static unsigned int	ft_strtrim_len(char const *s1, char const *set)
{
	size_t	i;
	size_t	len_str;

	i = 0;
	len_str = 0;
	while (s1[i])
	{
		if (ft_is_set(s1, set, i))
			i += ft_strlen((char *)set);
		else
		{
			len_str++;
			i++;
		}
	}
	return (len_str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	s = malloc((ft_strtrim_len(s1, set) + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);
	while (s1[i])
	{
		if (!ft_is_set(s1, set, i))
		{
			s[j] = s1[i];
			j++;
			i++;
		}
		else
			i += ft_strlen((char *)set);
	}
	s[i] = '\0';
	return (s);
}
