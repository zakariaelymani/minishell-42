/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:24:45 by zel-yama          #+#    #+#             */
/*   Updated: 2024/11/12 12:39:02 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**freplaces(unsigned long seats, char **s)
{
	while (seats > 0)
	{
		free(s[seats - 1]);
		seats--;
	}
	free(s);
	return (0);
}

static unsigned long	counterwords(const char *str, char c)
{
	unsigned long	i;
	unsigned long	counter;

	i = 0;
	counter = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
		{
			counter++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (counter);
}

static char	*copyin(const char *s, char *strs, \
unsigned long c, unsigned long len)
{
	unsigned long	j;
	unsigned long	h;

	j = 0;
	h = c - len;
	while (j < len)
	{
		strs[j] = s[h + j];
		j++;
	}
	strs[j] = '\0';
	return (strs);
}

static char	**allcoteplecs(const char *s, char c, \
char **strs, unsigned long words)
{
	unsigned long	i;
	unsigned long	len;
	unsigned long	co;

	i = 0;
	len = 0;
	co = 0;
	while (i < words)
	{
		while (s[co] == c)
			co++;
		while (s[co] != c && s[co] != '\0')
		{
			len++;
			co++;
		}
		strs[i] = (char *)malloc(sizeof (char) * (len + 1));
		if (!strs[i])
			return (freplaces(i, strs));
		copyin(s, strs[i], co, len);
		len = 0;
		i++;
	}
	strs[i] = 0;
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	char			**strs;
	unsigned long	num;

	if (!s)
		return (0);
	num = counterwords(s, c);
	strs = (char **)malloc(sizeof (char *) * (num + 1));
	if (!strs)
		return (NULL);
	strs = allcoteplecs(s, c, strs, num);
	return (strs);
}
