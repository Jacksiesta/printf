/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 03:12:21 by jherrald          #+#    #+#             */
/*   Updated: 2020/02/12 17:56:53 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*temp_maker(const char *format, t_flag *flag, va_list ap, int len)
{
	char	*final;

	final = ft_strdup("");
	if (format[len] == 'd' || format[len] == 'i')
		final = convers_d(ap, flag);
	if (format[len] == 'c')
		final = convers_char(ap, flag);
	if (format[len] == 's')
		final = convers_s(ap, flag);
	if (format[len] == 'x' || format[len] == 'X')
	{
		final = convers_hex(ap, flag);
		printf("hex final is %s\n", final);
		if (format[len] == 'X' && (ft_strncmp(final, "fffffff", 9) == 0))
		{
			printf("coui\n");
			final = ft_strdup("FFFFFFFF");
			printf("hex is %s\n", final);
		}
		else if (format[len] == 'X')
			return (ft_str_upper(final));
	}
	if (format[len] == 'u')
		final = convers_u(ap, flag);
	if (format[len] == 'p')
		final = convers_ptr(ap, flag);
	if (flag->percent)
		final = convers_double_percent(flag);
	return (final);
	if (flag->width || flag->zero || flag->minus || flag->precision != -1)
		// % alone 
	return (0);
}
