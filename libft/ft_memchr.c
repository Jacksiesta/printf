/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:58:15 by jherrald          #+#    #+#             */
/*   Updated: 2020/03/05 15:58:16 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			x;
	unsigned char	*unsig_s;

	x = 0;
	unsig_s = (unsigned char *)s;
	while (x < n)
	{
		if (unsig_s[x] == (unsigned char)c)
			return (unsig_s + x);
		x++;
	}
	return (0);
}
