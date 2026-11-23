/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marriche <marriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 13:44:03 by marriche          #+#    #+#             */
/*   Updated: 2026/11/18 17:41:37 by marriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	size_t			k;
	size_t			len;
	char			*str;

	i = 0;
	len = ft_strlen((char *)s) + 1;
	k = 0;
	str = malloc(len * sizeof(char));
	while (s[i])
	{
		str[k] = f(i, s[i]);
		k++;
		i++;
	}
	str[k] = '\0';
	return (str);
}
