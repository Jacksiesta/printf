/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:48:44 by jherrald          #+#    #+#             */
/*   Updated: 2019/12/17 13:00:33 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf(const char *coucou, ...)
{
	int		x;
	va_list	(ap);
	char	*value;

	x = 0;
	va_start(ap, coucou); 
	while (coucou[x])
	{
		if (coucou[x] == '%')
		{
			if (coucou[x + 1] == 's')
			{
				value = va_arg(ap, char *);
				write(1, value, 4);
			}
		}
		write(1, &coucou[x], 1);		
		x++;
	}

	va_end(ap);
	return (0);
}

int main()
{
	ft_printf("test: %s", "kiko");
	
}
