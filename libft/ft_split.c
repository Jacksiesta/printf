/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:59:52 by jherrald          #+#    #+#             */
/*   Updated: 2020/03/05 15:59:53 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		n_word(const char *s, char c)
{
	int	x;

	x = 1;
	while (*s)
	{
		if (*s == c)
		{
			s++;
			continue ;
		}
		x++;
		while (*s && *s != c)
			s++;
	}
	return (x);
}

static void		*ft_free(char **s)
{
	int	x;

	x = 0;
	while (s[x])
	{
		free(s[x]);
		s[x] = NULL;
		x++;
	}
	free(s);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	char	**new;
	int		x;
	int		y;

	y = 0;
	if (!s || (!(new = (char**)malloc(sizeof(char*) * n_word(s, c) + 1))))
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			x = 0;
			while (s[x] && s[x] != c)
				x++;
			if (!(new[y++] = ft_strndup(s, x)))
				return (ft_free(new));
			s += x;
		}
	}
	new[y] = 0;
	return (new);
}
