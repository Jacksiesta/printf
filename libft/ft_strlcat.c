/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 16:00:52 by jherrald          #+#    #+#             */
/*   Updated: 2020/03/05 16:01:01 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Line 37 --> because n stops at '/0'
*/

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*ptrdst;
	const char	*ptrsrc;
	size_t		n;
	size_t		len_diff;

	ptrdst = dst;
	ptrsrc = src;
	n = size;
	while (n-- != 0 && *ptrdst)
		ptrdst++;
	len_diff = ptrdst - dst;
	n = size - len_diff;
	if (n == 0)
		return (len_diff + ft_strlen(ptrsrc));
	while (*ptrsrc)
	{
		if (n != 1)
		{
			*ptrdst++ = *ptrsrc;
			n--;
		}
		ptrsrc++;
	}
	*ptrdst = '\0';
	return (len_diff + (ptrsrc - src));
}
