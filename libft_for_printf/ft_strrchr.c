/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <jherrald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:10:03 by jherrald          #+#    #+#             */
/*   Updated: 2019/11/04 18:32:21 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int x;

	x = ft_strlen((char*)s);
	while (x != 0 && s[x] != (char)c)
		x--;
	if (s[x] == (char)c)
		return ((char*)&s[x]);
	return (NULL);
}
