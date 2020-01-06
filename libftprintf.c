/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:48:44 by jherrald          #+#    #+#             */
/*   Updated: 2020/01/06 12:08:39 by jherrald         ###   ########.fr       */
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

char	ft_s(va_list ap)
{
	char	*value;

	value = va_arg(ap, char *);
	write(1, value, ft_strlen(value));
	return (0);
}

char	ft_c(va_list ap)
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

int		ft_d_lenght_nbr(int num)
{
	int x;

	x = 0;
	if (num == 0)
		return (1);
	if (num < 0)
		x++;
	while (num > 0)
	{
		num  /= 10;
		x++;
	}
	return (x);
}

void	ft_putstr(char *str)
{
	while (str)
	{
		write(1, &str, 1);
		str++;
	}
}

char	*ft_d(va_list ap)
{
	int					num;
	int					size;
	int					sign;
	char				*new;

	printf("yes\n");
	num = va_arg(ap, int);
//	if (n == -2147483648)
//		return (ft_strdup("-2147483648");
	sign = (num < 0) ? 1 : 0;
	num = (num < 0) ? -num : num;
	size = (ft_d_lenght_nbr(num));
	if (!(new = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	new[size] = '\0';
	if (sign == 1)
		new[0] = '-';
	while (size-- > sign)
	{
		new[size] = (num % 10) + '0';
		num = num / 10;
	}
	printf("new is %s\n", new);
//	ft_putstr(new);
	return (new);
}

int		ft_printf(const char *coucou, ...)
{
	int		x;
	va_list	ap;

	x = 0;
	va_start(ap, coucou); 
	while (coucou[x])
	{
		if (coucou[x] == '%')
		{
			if (coucou[x + 1] == 's')
				ft_s(ap);
			if (coucou[x + 1] == 'c')
				ft_c(ap);
			if (coucou[x + 1] == 'd' || coucou[x + 1] == 'i')
				ft_d(ap);
			x = x + 2;
		}
		write(1, &coucou[x], 1);
		x++;
	}
	return (0);
}

int main()
{
//	char 	*temp = "kikouuuu";
//	char	*oups = "DEUX";
//	char	a = 'B';
	int		numba = 150;
//	ft_printf("un : %s troie \n", oups);
	ft_printf("number test = %d nono \n", numba);
	//printf("what : %s WHAT \n", oups);
	//printf("coucoucou %.4s", oups);
}
