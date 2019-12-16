/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <jherrald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:06:05 by jherrald          #+#    #+#             */
/*   Updated: 2019/11/04 18:28:13 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			x;
	unsigned char	*dest;
	unsigned char	*source;

	x = 0;
	if (!dst && !src)
		return (NULL);
	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	while (x < n)
	{
		dest[x] = source[x];
		if (source[x] == (unsigned char)c)
			return ((void *)(dst + x + 1));
		x++;
	}
	return (NULL);
}
