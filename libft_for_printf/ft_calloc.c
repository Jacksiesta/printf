/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <jherrald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 20:44:12 by jherrald          #+#    #+#             */
/*   Updated: 2020/01/07 15:09:37 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;

	if (!count || !size)
		return (NULL);
	if (!(str = (char *)malloc(count * size)))
		return (NULL);
	ft_bzero(str, (count * size));
	return ((void*)str);
}
