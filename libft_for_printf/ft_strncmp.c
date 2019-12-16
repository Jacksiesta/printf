/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <jherrald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:28:08 by jherrald          #+#    #+#             */
/*   Updated: 2019/10/29 12:45:25 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	x;
	int		resultat;

	resultat = 0;
	x = 0;
	if (n == 0)
		return (0);
	while ((s1[x] != '\0') && (s2[x] != '\0')
			&& (s1[x] == s2[x]) && (n - 1 > x))
		x++;
	return ((unsigned char)s1[x] - (unsigned char)s2[x]);
}
