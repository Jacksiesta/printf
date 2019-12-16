/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <jherrald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:43:54 by jherrald          #+#    #+#             */
/*   Updated: 2019/11/04 18:33:49 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(char const c, char const *set)
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
	char	*new;
	size_t	len;
	size_t	x;

	if (!s1 || !set)
		return (0);
	len = ft_strlen(s1);
	x = 0;
	while (ft_check(s1[x], set))
		x++;
	while (ft_check(s1[len - 1], set))
		len--;
	len = len - x;
	new = ft_substr(s1, x, len);
	if (new == 0)
		return (NULL);
	new[len] = '\0';
	return (new);
}
