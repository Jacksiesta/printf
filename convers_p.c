/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convers_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 20:14:16 by jherrald          #+#    #+#             */
/*   Updated: 2020/02/14 20:14:17 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*convers_ptr(va_list ap, t_flag *flag)
{
    char	*final;
    char	*init;
    void	*num;
    int		size;

    num = va_arg(ap, void *);
    final = ft_x((long long unsigned int)num);
    size = ft_strlen(final);
//	if (!num)
//		return (ft_strdup("0x3"));
    if (num == NULL || num == 0)
    {
        final = ft_strdup("0x0");
        if (flag->width > 3)
            return (ft_strjoin(pad_maker(' ', flag->width - 3), final));
        else
            return (final);
    }
    final= ft_strjoin(ft_strdup("0x"), final);
    if (flag->minus)
        if (flag->width > 11)
            return (ft_strjoin(final, pad_maker(' ', flag->width - 11)));
    if (flag->width > 11)
        final = ft_strjoin(pad_maker(' ', flag->width - 11), final);
    return (final);
}