/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:58:24 by jherrald          #+#    #+#             */
/*   Updated: 2020/03/05 15:58:26 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			x;
	unsigned char	*unsig_s1;
	unsigned char	*unsig_s2;

	x = 0;
	unsig_s1 = (unsigned char*)s1;
	unsig_s2 = (unsigned char*)s2;
	if (n == 0)
		return (0);
	while (x < n && unsig_s1[x] == unsig_s2[x])
		x++;
	if (x == n)
		x--;
	return (unsig_s1[x] - unsig_s2[x]);
}
