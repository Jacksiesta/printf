/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:48:44 by jherrald          #+#    #+#             */
/*   Updated: 2019/12/19 20:10:19 by jherrald         ###   ########.fr       */
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

char	ft_c(char c, va_list ap)
{
	char	a;

	a = va_arg(ap, int);
	write(1, &a, 1);
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		strlen_int(int i)
{
	
}


void	ft_d(int n, va_list ap)
{
	int		nbr;

	nbr = va_arg(ap, int);
	//printf("n is %d \n", nbr);
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr >= 10)
		ft_d((nbr / 10), ap);		
	ft_putchar(nbr % 10 + '0');
}

int		ft_printf(const char *coucou, ...)
{
	int		x;
	va_list	ap;
	char	*value;
	char	a;
	int		nbr;

	x = 0;
	nbr = 0;
	va_start(ap, coucou); 
	while (coucou[x])
	{
		if (coucou[x] == '%')
		{
			if (coucou[x + 1] == 's')
				ft_s(value, ap);
			if (coucou[x + 1] == 'c')
				ft_c(a, ap);
			if (coucou[x + 1] == 'd' || coucou[x + 1] == 'i')
				ft_d(nbr, ap);
			x = x + 2;
		}
		write(1, &coucou[x], 1);
		x++;
	}
	return (0);
}

int main()
{
	char 	*temp = "kikouuuu";
	char	*oups = "wHaTTT";
	char	a = 'B';
	int		num = 15;
	ft_printf("what : %s WHAT \n", oups);
	ft_printf("number test = %d nono \n", num);
	//printf("what : %s WHAT \n", oups);
	//printf("coucoucou %.4s", oups);
}
