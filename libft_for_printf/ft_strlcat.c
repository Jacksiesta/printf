/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <jherrald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:12:08 by jherrald          #+#    #+#             */
/*   Updated: 2019/11/04 17:01:45 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	x;
	size_t	res;
	size_t	z;

	x = ft_strlen(dst);
	z = 0;
	res = 0;
	if (size <= x)
		res = ft_strlen(src) + size;
	else
		res = ft_strlen(src) + x;
	while (src[z] != '\0' && (x + 1 < size))
	{
		dst[x] = src[z];
		x++;
		z++;
	}
	dst[x] = '\0';
	return (res);
}
