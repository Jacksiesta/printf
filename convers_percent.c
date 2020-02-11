/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convers_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:37:41 by jherrald          #+#    #+#             */
/*   Updated: 2020/02/11 15:50:55 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*convers_double_percent(t_flag *flag)
{
	char	*final;

	final = ft_strdup("%");
	if (flag->minus)
	{
		if (flag->width > 1)
			return (ft_strjoin(final, pad_maker(' ', flag->width - 1)));
		else
			return (final);
	}
	if (flag->zero)
	{
		if (flag->width > 1)
			return (ft_strjoin(pad_maker('0', flag->width - 1), final));
		else
			return (final);
	}
	if (flag->width && !flag->zero && !flag->minus)
	{
		if (flag->width > 1)
			return (ft_strjoin(pad_maker(' ', flag->width - 1), final));
		else
			return (final);
	}
	return ("%");
}
