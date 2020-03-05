/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 16:01:32 by jherrald          #+#    #+#             */
/*   Updated: 2020/03/05 16:01:33 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, int y)
{
	int		x;
	char	*target;

	x = 0;
	if (!(target = malloc(sizeof(char) * (y + 1))))
		return (NULL);
	while (x < y)
	{
		target[x] = s1[x];
		x++;
	}
	target[x] = '\0';
	return (target);
}
