/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <jherrald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 18:28:07 by jherrald          #+#    #+#             */
/*   Updated: 2019/11/04 21:10:20 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int			x;
	unsigned const char		*str;

	str = s;
	x = 0;
	while (x < n)
	{
		if (str[x] == (unsigned char)c)
			return ((void *)str + x);
		x++;
	}
	return (NULL);
}
