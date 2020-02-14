/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <jherrald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 10:36:15 by jherrald          #+#    #+#             */
/*   Updated: 2020/02/14 18:48:04 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int		s1len;
	int		x;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	s1len = ft_strlen(s1);
	x = ft_strlen(s2);
	if (!(new = (char *)malloc(sizeof(char) * (s1len + x) + 1)))
		return (NULL);
	x = -1;
	while (s1[++x] != '\0')
		new[x] = s1[x];
	x = -1;
	while (s2[++x] != '\0')
		new[s1len + x] = s2[x];
	new[s1len + x] = '\0';
	return (new);
}
