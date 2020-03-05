/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstock.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 16:01:55 by jherrald          #+#    #+#             */
/*   Updated: 2020/03/05 16:01:57 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**Concatene from a mallocated string[*1] and a simple string to a new
**mallocated string, before return the adress of the new mallocated string it
**frees the inputed mallocated string[*1].
*/

char	*ft_strstock(char *ptr, char *str, int fp)
{
	char	*new_ptr;
	int		*i;

	i = (int[3]){ft_strlen(ptr), ft_strlen(str), 0};
	if (!(new_ptr = ft_calloc(sizeof(char), (i[0] + i[1]) + 1)))
		return (NULL);
	i[0] = 0;
	while ((!(i[1] = 0)) && ptr && ptr[i[0]])
	{
		new_ptr[i[0]] = ptr[i[0]];
		i[0]++;
	}
	while (str && str[i[1]])
	{
		new_ptr[i[0] + i[1]] = str[i[1]];
		i[1]++;
	}
	new_ptr[i[0] + i[1]] = 0;
	if (ptr && (fp == 1 || fp == 3))
		free(ptr);
	if (ptr && (fp == 2 || fp == 3))
		free(str);
	return (new_ptr);
}
