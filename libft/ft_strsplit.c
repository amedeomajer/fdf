/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amajer <amajer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:44:59 by amajer            #+#    #+#             */
/*   Updated: 2021/12/13 20:33:08 by amajer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free(char **str, int a)
{
	while (a >= 0)
		free(str[a--]);
	free(str);
	return (NULL);
}

static int	ft_wordlen(const char *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] != 0 && s[i] != c)
	{
		i++;
		len++;
	}
	return (len);
}

static char	**ft_populate(const char *s, char **str, char c)
{
	int	i;
	int	a;
	int	j;

	i = 0;
	a = 0;
	while (s[i] != 0)
	{
		j = 0;
		while (s[i] == c)
			i++;
		if (s[i] != 0)
		{
			str[a] = (char *)malloc(sizeof(char) * (ft_wordlen(s, c, i) + 1));
			if (!str[a])
				ft_free(str, a);
			while (s[i] != c && s[i] != 0)
				str[a][j++] = ((char *)s)[i++];
			str[a++][j] = 0;
		}
	}
	str[a] = NULL;
	return (str);
}

static int	ft_measure(const char *s, char c)
{
	int	count;
	int	i;
	int	word;

	count = 0;
	i = 0;
	word = 0;
	while (s[i] != 0)
	{
		if (s[i] != c)
		{
			word++;
			if (word == 1)
				count++;
		}
		else
			word = 0;
		i++;
	}
	return (count);
}

char	**ft_strsplit(char const *s, char c)
{
	int		i;
	char	**str;

	if (!s)
		return (NULL);
	i = 0;
	str = (char **)malloc(sizeof(char *) * (ft_measure(s, c) + 1));
	if (!str)
		return (NULL);
	return (ft_populate(s, str, c));
}
