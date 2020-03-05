/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 16:01:45 by jherrald          #+#    #+#             */
/*   Updated: 2020/03/05 16:01:47 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	x;

	x = ft_strlen((char *)s);
	while (x != 0 && s[x] != (char)c)
		x--;
	if (s[x] == (char)c)
		return ((char *)&s[x]);
	return (NULL);
}
