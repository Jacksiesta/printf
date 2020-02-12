/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convers_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 22:01:51 by jherrald          #+#    #+#             */
/*   Updated: 2020/02/12 16:16:04 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*convers_s_null(t_flag *flag)
{
	char	*fin;

	fin = ft_strdup("(null)");
	if (flag->precision == 0)
	{
		if (flag->width)
			return (pad_maker(' ', flag->width));
		else
			return (ft_strdup(""));
	}
	if (flag->precision > 0 && flag->precision <= 6)
		fin = ft_substr(fin, 0, flag->precision);
	if (flag->minus && flag->width)
	{
		if (flag->width > ft_strlen(fin))
			fin = ft_strjoin(fin, pad_maker(' ', flag->width - ft_strlen(fin)));
		else
			return (fin);
	}
	if (flag->zero)
	{
		if (flag->width > ft_strlen(fin))
			fin = ft_strjoin(pad_maker('0', flag->width - ft_strlen(fin)), fin);
	}
	if (flag->width && !flag->minus && !flag->zero)
		if (flag->width > ft_strlen(fin))
			fin = ft_strjoin(pad_maker(' ', flag->width - ft_strlen(fin)), fin);
	return (fin);
}

char	*convers_s(va_list ap, t_flag *flag)
{
	char	*in;
	char	*fin;
	int		size;

	fin = ft_strdup("");
	in = va_arg(ap, char *);
	if (in == NULL)
		return (convers_s_null(flag));
	size = ft_strlen(in);
	if (flag->zero && flag->width > ft_strlen(in))
		return (ft_strjoin(pad_maker('0', flag->width - ft_strlen(in)), in));
	if (flag->precision != -1)
		if (flag->precision < size)
			fin = ft_strdup(cropped_str(in, flag->precision));
	if (flag->precision == -1 || (flag->precision != -1
				&& flag->precision >= size))
		fin = ft_strdup(in);
	if (flag->minus)
		if (flag->width > ft_strlen(fin))
			fin = ft_strjoin(fin, pad_maker(' ', flag->width - ft_strlen(fin)));
	if (flag->width && !flag->minus)
		if (flag->width > ft_strlen(fin))
			fin = ft_strjoin(pad_maker(' ', flag->width - ft_strlen(fin)), fin);
	return (fin);
}
