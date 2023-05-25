/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 14:51:53 by gamoreir          #+#    #+#             */
/*   Updated: 2023/04/23 18:16:02 by gamoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	howmanywords(char const *str, char c)
{
	size_t	wrdcnt;
	size_t	i;

	wrdcnt = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			wrdcnt++;
			while (str[i] && str[i] != c)
				i++;
		}
		else
			i++;
	}
	return (wrdcnt);
}

static char	*addword(char const *str, char c)
{
	char	*word;
	size_t	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	word = (char *) malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != c)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *str, char c)
{
	size_t	w;
	char	**res;

	w = 0;
	res = (char **) malloc(sizeof(char *) * (howmanywords(str, c) + 1));
	if (!res || !str)
		return (NULL);
	while (*str)
	{
		if (*str != c)
		{
			res[w] = addword(str, c);
			while (*str && *str != c)
					str++;
			w++;
		}
		else
			str++;
	}
	res[w] = 0;
	return (res);
}
