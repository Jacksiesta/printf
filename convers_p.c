/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convers_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 20:14:16 by jherrald          #+#    #+#             */
/*   Updated: 2020/02/18 15:34:10 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*convers_ptr_null(t_flag *flag)
{
	if (flag->precision > 0)
		return (ft_strjoin("0x", pad_maker('0', flag->precision)));
	if (flag->precision  == 0)
		return ("0x");
	if (flag->minus && flag->width > 3)
		return (ft_strjoin("0x0", pad_maker(' ', flag->width - 3)));
	if (flag->zero && flag->width > 3)
		return (ft_strjoin(ft_strdup("0x"), pad_maker('0', flag->width - 2)));
	if (flag->width > 3)
		return (ft_strjoin(pad_maker(' ', flag->width - 3), ft_strdup("0x0")));
	return ("0x0");
}

char	*convers_ptr(va_list ap, t_flag *flag)
{
	char	*final;
	void	*num;
	int		size;

	num = va_arg(ap, void *);
	final = ft_x((long long unsigned int)num);
	size = ft_strlen(final);
	if (num == NULL || num == 0)
		return (convers_ptr_null(flag));
	if (flag->precision > flag->width)
	{
		if (flag->precision > size)
			return (ft_strjoin("0x", ft_strjoin(pad_maker('0', flag->precision - size), final)));
		return (ft_strjoin(ft_strdup("0x"), final));
	}
	final = ft_strjoin(ft_strdup("0x"), final);
	size = size + 2;
	if (flag->minus && flag->width > size)
		return (ft_strjoin(final, pad_maker(' ', flag->width - size)));
	if (flag->width > size)
		final = ft_strjoin(pad_maker(' ', flag->width - size), final);
	return (final);
}
