/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <jherrald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:48:44 by jherrald          #+#    #+#             */
/*   Updated: 2020/02/16 05:27:30 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	init_struct(t_flag *flag)
{
	flag->zero = 0; // pour pas avoir de valeur residuelle
	flag->minus = 0;
	flag->width = 0;
	flag->precision = -1;
	flag->percent = 0;
	flag->alone_percent = 0;
}

int	parser(va_list ap, const char *str, t_flag *flag) // activates flags
{
	int		x;
	char	*specifiers;

	specifiers = ft_strdup("scxXdiup%");
	x = 0;
	init_struct(flag);
	if (ft_isalpha(str[x]) == 0)
	{
		while (str[x] == '0')
		{
			flag->zero = 1;
			x++;
		}
		while (str[x] == '-')
		{
			flag->minus = 1;
			x++;
		}
		while (str[x] == '0')
			x++;
		if (str[x] == '*' || (str[x] >= '1' && str[x] <= '9'))
		{
			if (str[x] == '*')
			{
				flag->width = va_arg(ap, int);
				if (flag->width < 0)
				{
					flag->minus = 1;
					flag->width = -flag->width;
				}
				x++;
			}
			else
				flag->width = ft_atoi(&str[x], &x);
		}
		if (str[x] == '.')
		{
			x++;
			if (str[x] == '*')
			{
				flag->precision = va_arg(ap, int);
				x++;
			}
			else
				flag->precision = ft_atoi(&str[x], &x);
		}
	}
	if (flag->precision != -1 || flag->minus != 0)
		flag->zero = 0;
	if (str[x] == '%')
		flag->percent = 1;
	if (ft_search_char(specifiers, str[x]) == 0)
		flag->alone_percent = 1;
	return (x);
}

/*
   void	final_init(t_final final)
   {
   if (!(final->buffer = (t_final)malloc(sizeof(t_final) * taille; 
   }
   */

int		ft_printf(const char *coucou, ...)
{
	int		x;
	int		y;
	int		z;
	int     len;
	va_list	ap;
	char	*buffer;
	char	*temp;
	t_flag	flag;

	x = 0;
	y = 0;
	va_start(ap, coucou);
	if (!(buffer = (char *)malloc(sizeof(char) * 1000000)))
		return (0);
	if (!(temp = (char *)malloc(sizeof(char) * 10000000)))
		return (0);
	while (coucou[x])
	{
		if (coucou[x] == '%')
		{
			temp = ft_strdup("");
			init_struct(&flag);
			z = parser(ap, &coucou[x + 1], &flag);
			if (flag.alone_percent)
				x = x + z + 1;
			else
			{
				temp = temp_maker(&coucou[x + 1], &flag, ap, z);
				buffer = ft_strjoin(buffer, temp);
				x = x + z + 1;	
				y = y + ft_strlen(temp) - 1;
			}
		}
		else
			buffer[y] = coucou[x];
		x++;
		y++;
	}
	ft_putstr(buffer);
	return (ft_strlen(buffer));
}



int main()
{
	//	char c;

	//	c = 'a';
//	ft_printf("%.0d\n", 100);
//	ft_printf("%0151.*d", -88, 1234567899);
	printf("%5.s", "coucou");
	printf("\n%5s", "coucou");
	printf("\n%-.*d", 10, 123);
	return (0);
}
