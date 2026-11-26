/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marriche <marriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 16:12:14 by marriche          #+#    #+#             */
/*   Updated: 2026/11/26 12:24:38 by marriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static unsigned int	ft_count_words(char const *s, char c)
{
	size_t			i;
	unsigned int	nb_words;

	i = 0;
	nb_words = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			nb_words++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (nb_words);
}

static unsigned int	ft_len_word(char const *s, size_t i, char c)
{
	unsigned int	len_word;

	len_word = 0;
	while (s[i] && s[i] != c)
	{
		len_word++;
		i++;
	}
	return (len_word);
}

static char	*ft_fill_strs(const char *s, size_t *i, char c)
{
	size_t	j;
	char	*str;

	j = 0;
	str = malloc((ft_len_word(s, *i, c) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s[*i] && s[*i] != c)
	{
		str[j] = s[*i];
		j++;
		(*i)++;
	}
	str[j] = '\0';
	return (str);
}

static char	**ft_free_strs(char **strs, size_t len_filled)
{
	size_t	i;

	i = 0;
	while (i <= len_filled)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char			**strs;
	size_t			i;
	size_t			j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	strs = malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (strs == NULL)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			strs[j] = ft_fill_strs(s, &i, c);
			if (!strs[j])
				return (ft_free_strs(strs, j));
			j++;
		}
		else
			i++;
	}
	strs[j] = NULL;
	return (strs);
}
