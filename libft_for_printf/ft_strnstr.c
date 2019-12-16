/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <jherrald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 07:43:11 by jherrald          #+#    #+#             */
/*   Updated: 2019/11/04 18:31:56 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	len_needle;
	size_t	len_haystack;

	len_needle = ft_strlen(needle);
	len_haystack = ft_strlen(haystack);
	if (!*needle)
		return ((char *)haystack);
	while (*haystack && len-- >= len_needle)
	{
		if (*haystack == *needle && !ft_memcmp(haystack, needle, len_needle))
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
