/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_front.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:54:28 by jherrald          #+#    #+#             */
/*   Updated: 2020/03/05 15:54:30 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*add_front(char c, char *str, int i)
{
	char	*ret;

	if (!(ret = (char *)malloc(sizeof(char) * (ft_strlen(str) + 2))))
		return (NULL);
	if (!str)
		return (NULL);
	if (i == 0)
	{
		ret[0] = c;
		i = 1;
	}
	while (*str)
	{
		ret[i] = *str;
		i++;
		str++;
	}
	if (i == 1)
		ret[i] = c;
	return (ret);
}
