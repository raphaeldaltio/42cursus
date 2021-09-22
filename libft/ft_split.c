/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdaltio- <rdaltio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 19:45:20 by rdaltio-          #+#    #+#             */
/*   Updated: 2021/08/19 17:18:52 by rdaltio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcount(char const *s, char c)
{
	size_t	word;

	word = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			word++;
		while (*s && (*s != c))
			s++;
	}
	return (word);
}

static char	*ft_wordcopy(char const *s, size_t n)
{
	char	*str;
	size_t	dstsize;

	dstsize = n + 1;
	str = (char *)malloc(sizeof(char) * dstsize);
	if (!str)
		return (0);
	ft_strlcpy(str, s, dstsize);
	return (str);
}

static char	**ft_splitting(char const *s, char **split, char c)
{
	size_t		count;
	size_t		begin_w;
	size_t		next_w;

	count = 0;
	begin_w = 0;
	next_w = 0;
	while (s[count])
	{
		while (s[count] == c)
			count++;
		begin_w = count;
		while (s[count] && s[count] != c)
			count++;
		if (count > begin_w)
		{
			split[next_w] = ft_wordcopy(&s[begin_w], count - begin_w);
			next_w++;
		}
	}
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char		**split;

	if (!s)
		return (0);
	split = (char **)ft_calloc((ft_wordcount(s, c)) + 1, sizeof(char *));
	if (!split)
		return (0);
	return (ft_splitting(s, split, c));
}
