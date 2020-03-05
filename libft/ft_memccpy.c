/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:58:08 by jherrald          #+#    #+#             */
/*   Updated: 2020/03/05 15:58:11 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*ptrdst;
	const unsigned char	*ptrsrc;

	if (n)
	{
		ptrdst = dst;
		ptrsrc = src;
		while (n-- != 0)
		{
			if ((*ptrdst++ = *ptrsrc++) == (unsigned char)c)
				return (ptrdst);
		}
	}
	return (0);
}
