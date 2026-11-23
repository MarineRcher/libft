/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marriche <marriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 16:12:14 by marriche          #+#    #+#             */
/*   Updated: 2026/11/18 15:20:53 by marriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

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

static char	*ft_fill_strs(const char *s, size_t *i, char c, char *str)
{
	size_t	j;

	j = 0;
	while (s[*i] && s[*i] != c)
	{
		str[j] = s[*i];
		j++;
		(*i)++;
	}
	str[j] = '\0';
	return (str);
}

static void	ft_free_strs(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

char	**ft_split(char const *s, char c)
{
	char			**strs;
	size_t			i;
	size_t			j;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	strs = malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (strs == NULL)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			strs[j] = malloc((ft_len_word(s, i, c) + 1) * sizeof(char));
			if (!strs[j])
			{
				ft_free_strs(strs);
				return (NULL);
			}
			strs[j] = ft_fill_strs(s, &i, c, strs[j]);
			j++;
		}
		else
			i++;
	}
	strs[j] = NULL;
	return (strs);
}
// #include <stdio.h>
// int	main(void)
// {
// 	char	**str;
// 	int		i = 0;
// 	str = ft_split(NULL, ' ');
// 	if (str == NULL)
// 		return (0);
// 	while (i <= 4)
// 	{
// 		printf("%s\n", str[i]);
// 		i++;
// 	}
// 	i = 0;
// 	while (i <= 4)
// 	{
// 		free(str[i]);
// 		i++;
// 	}
// 	free(str);
// }
