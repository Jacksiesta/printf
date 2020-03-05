/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 16:01:40 by jherrald          #+#    #+#             */
/*   Updated: 2020/03/05 16:01:40 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	len_haystack;
	size_t	len_needle;

	len_haystack = ft_strlen(haystack);
	len_needle = ft_strlen(needle);
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
