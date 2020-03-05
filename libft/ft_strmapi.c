/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 16:01:23 by jherrald          #+#    #+#             */
/*   Updated: 2020/03/05 16:01:24 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	x;
	char	*mall;

	if (s == NULL || f == NULL)
		return (NULL);
	if ((mall = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))) == NULL)
		return (NULL);
	x = -1;
	while (++x < ft_strlen(s))
		mall[x] = (*f)((unsigned int)x, s[x]);
	mall[x] = '\0';
	return (mall);
}
