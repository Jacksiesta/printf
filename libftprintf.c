/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:48:44 by jherrald          #+#    #+#             */
/*   Updated: 2019/12/17 16:41:30 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_strlen(char *s)
{
	size_t	x;

	x = 0;
	while (s[x])
		x++;
	return (x);
}

char	ft_s(char *s, va_list ap)
{
	char	*value;

	value = va_arg(ap, char *);
	write(1, value, ft_strlen(value));
	return (0);
}

int		ft_printf(const char *coucou, ...)
{
	int		x;
	va_list	ap;
	char	*value;
	char	a;

	x = 0;
	va_start(ap, coucou); 
	while (coucou[x])
	{
		if (coucou[x] == '%')
		{
			if (coucou[x + 1] == 's')
				ft_s(value, ap);
				break;		
			if (coucou[x + 1] == 'c')
			{
				a = va_arg(ap, int);
				write(1, &a, 1);
				return (0);
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
	char 	*temp = "kikouuuu";
	char	*oups = "what";
	char	a = 'c';
	ft_printf("test :%s", oups);
//	ft_printf("test :%c", a);
		
}
