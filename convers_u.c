/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convers_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 03:23:15 by jherrald          #+#    #+#             */
/*   Updated: 2020/02/16 01:25:30 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*convers_u_param_zero(t_flag *flag)
{
//	if (!flag->width && !flag->zero && !flag->minus && flag->precision == -1)
//		return ("0");
	if (flag->precision == 0)
	{
		if (!flag->width)
			return ("");
		return (pad_maker(' ', flag->width));
	}
	if (flag->precision > flag->width)
		return (pad_maker('0', flag->precision));
	if (flag->zero)
		return (pad_maker('0', flag->width));
	if (flag->minus && flag->width)
	{
		if (flag->precision > 0)
			return (ft_strjoin(pad_maker('0', flag->precision), pad_maker(' ', flag->width - flag->precision)));
		if (flag->precision == 0)
			return (pad_maker(' ', flag->width));
		return (add_char_to_str('0', pad_maker(' ', flag->width - 1), 0));
	}
	if (flag->precision > 0)
		return (ft_strjoin(pad_maker(' ', flag->width - flag->precision), pad_maker('0', flag->precision)));
	if (flag->width && flag->precision > 0)
		return (add_char_to_str('0', pad_maker(' ', flag->width - 1), 1));
	if (flag->width && flag->precision == -1)
		return (add_char_to_str('0', pad_maker(' ', flag->width - 1), 1));
	return ("0");
}


char	*convers_u(va_list ap, t_flag *flag)
{
	char	*init;
	long long unsigned int 	num;
	int		size;
	char	*final;

	num = va_arg(ap, long long unsigned int);
	init = ft_u(num);
	size = ft_strlen(init);
	if (!init)
	{
		final = convers_u_param_zero(flag);
		return (final);
	}
	if (ft_strncmp(init, "4294967295", 10) == 0)
		return (ft_strdup("4294967295"));
	final = ft_strdup("");
	if (flag->precision)
	{
		if (flag->precision > size)
			final = ft_strjoin(pad_maker('0', flag->precision - size), init);
		else
			final = ft_strdup(init); // gets rid of 0
	}
	if (flag->precision == 0)
		final = ft_strdup(init);		
	if (flag->minus)
		if (flag->width > size)
			final = ft_strjoin(final, pad_maker(' ', flag->width - ft_strlen(final)));
	if (flag->zero)
		if (flag->width > size)
			final = ft_strjoin(pad_maker('0', flag->width - size), final);
	if (flag->width && !flag->minus && !flag->zero)
		if (flag->width > size)
		{
			if (flag->precision == 0 && num == 0)
				return (pad_maker(' ', flag->width));
			if (flag->precision != -1 && flag->precision > size)
				final = ft_strjoin(pad_maker(' ', flag->width - flag->precision), final);
			else
				final = ft_strjoin(pad_maker(' ', flag->width - size), final);
		}
	return (final);
}
