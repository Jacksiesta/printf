/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 16:02:05 by jherrald          #+#    #+#             */
/*   Updated: 2020/03/05 16:02:06 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	verify(char const c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*string;
	size_t	x;
	size_t	len;

	if ((s1 == NULL) || (set == NULL))
		return (NULL);
	len = ft_strlen(s1);
	x = 0;
	while (verify(s1[x], set))
		x++;
	len = ft_strlen(s1);
	while (verify(s1[len - 1], set))
		len--;
	len = len - x;
	string = ft_substr(s1, x, len);
	if (string == 0)
		return (NULL);
	string[len] = '\0';
	return (string);
}
