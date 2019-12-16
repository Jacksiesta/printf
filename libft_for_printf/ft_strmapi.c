/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <jherrald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 18:07:19 by jherrald          #+#    #+#             */
/*   Updated: 2019/10/29 16:14:58 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	int		x;

	if (s == NULL || f == NULL)
		return (NULL);
	if (!(new = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	x = 0;
	while (s[x])
	{
		new[x] = f((unsigned int)x, s[x]);
		x++;
	}
	new[x] = '\0';
	return (new);
}
