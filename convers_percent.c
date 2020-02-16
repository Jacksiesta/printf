/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convers_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:37:41 by jherrald          #+#    #+#             */
/*   Updated: 2020/02/16 03:39:20 by jherrald         ###   ########.fr       */
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

char	*convers_prc(t_flag *flag)
{
	char	*final;
	int		size;

	final = ft_strdup("%");
	if (flag->minus)
		if (flag->width > 1)
			return (ft_strjoin(final, pad_maker(' ', flag->width - 1)));
	if (flag->zero)
		if (flag->width > 1)
			return (ft_strjoin(pad_maker('0', flag->width - 1), final));
	if (flag->width && !flag->minus && !flag->zero)
		if (flag->width > 1)
			return (ft_strjoin(pad_maker(' ', flag->width - 1), final));
	return (final);
}
