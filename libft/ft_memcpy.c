/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:58:42 by jherrald          #+#    #+#             */
/*   Updated: 2020/03/05 15:58:43 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		x;
	char		*ptr1;
	const char	*ptr2;

	ptr1 = dst;
	ptr2 = src;
	x = -1;
	if (dst == 0 && src == 0)
		return (0);
	while (++x < n)
		*(ptr1 + x) = *(ptr2 + x);
	return (dst);
}
