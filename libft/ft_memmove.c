/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:59:01 by jherrald          #+#    #+#             */
/*   Updated: 2020/03/05 15:59:02 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			x;
	unsigned char	*ptrdst;
	unsigned char	*ptrsrc;

	if (dst == 0 && src == 0)
		return (0);
	ptrdst = (unsigned char*)dst;
	ptrsrc = (unsigned char*)src;
	x = -1;
	if (ptrdst < ptrsrc)
		while (++x < len)
			ptrdst[x] = ptrsrc[x];
	else
		while (len-- > 0)
			ptrdst[len] = ptrsrc[len];
	return (dst);
}
