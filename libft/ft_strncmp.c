/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 16:01:27 by jherrald          #+#    #+#             */
/*   Updated: 2020/03/05 16:01:28 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	x;
	int		res;

	x = 0;
	res = 0;
	if (n == 0)
		return (0);
	while ((s1[x] != '\0') && (s2[x] != '\0')
			&& (s1[x] == s2[x]) && (n - 1 - x))
		x++;
	return ((unsigned char)s1[x] - (unsigned char)s2[x]);
}
