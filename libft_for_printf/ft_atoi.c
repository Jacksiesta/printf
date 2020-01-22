/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <jherrald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 09:47:30 by jherrald          #+#    #+#             */
/*   Updated: 2019/11/04 18:27:25 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str, int *len)
{
	int						x;
	unsigned long long int	nb;
	int						symb;

	x = 0;
	nb = 0;
	symb = 1;
	while (str[x] == '\t' || str[x] == '\v' || str[x] == '\n'
			|| str[x] == '\r' || str[x] == '\f' || str[x] == ' ')
		x++;
	if (str[x] == '+' || str[x] == '-')
	{
		if (str[x++] == '-')
			symb = symb * (-1);
	}
	while (str[x] >= '0' && str[x] <= '9')
	{
		nb = (nb * 10) + (str[x] - 48);
		if (nb > LONG_MAX)
			return ((symb + 1) / -2);
		x++;
        (*len)++;
	}
	return ((int)(nb * symb));
}
