/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <jherrald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:48:44 by jherrald          #+#    #+#             */
/*   Updated: 2020/02/23 19:10:36 by jherrald         ###   ########.fr       */
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
	printf("specifiers = %p to %p\n", specifiers, specifiers + 9);
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
	if (flag->precision < -1)
		flag->precision = -1;
	if (ft_search_char(specifiers, str[x]) == 0)
		flag->alone_percent = 1;
	free(specifiers);
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
	va_list	ap;
	char	*buffer;
	char	*temp;
	t_flag	flag;

	x = 0;
	y = 0;
	va_start(ap, coucou);
	printf("buffer = %p to %p\n", buffer, buffer + 1000);
	printf("temp = %p to %p\n", temp, temp + 1000);
	while (coucou[x])
	{
		if (coucou[x] == '%')
		{
			temp = NULL;
			init_struct(&flag);
			printf("av : buffer(%1$p to %2$p) is [%1$s]\n", buffer, buffer + ft_strlen(buffer));
			z = parser(ap, &coucou[x + 1], &flag);
			printf("ap : buffer(%1$p to %2$p) is [%1$s]\n\n", buffer, buffer + ft_strlen(buffer));
	//		printf("z is %d\n", z);
			if (flag.alone_percent)
				x = x + z + 1;
			else
			{
				temp = temp_maker(&coucou[x + 1], &flag, ap, z);
				buffer = ft_strjoin(buffer, temp);
				x = x + z + 1;	
				y = y + ft_strlen(temp) - 1;
			}
	//		printf("while : buffer is %s\n", buffer);
	//		printf("coucou %c\n", coucou[x]);
	//		printf("temp is [%s]\n", temp);
		}
		else
		{
	//		printf("coucou[%d] is %c\n", x, coucou[x]);
			buffer[y] = coucou[x];

	//		printf("buffer[%d] is %c\n\n", y, buffer[y]);
		}
		x++;
		y++;
	}
	buffer[y] = '\0';
	write(1, "\nhere[", 6);
	write(1, buffer, y);
	write(1, "]\n", 2);
	printf("len buffer %zu\n", ft_strlen(buffer));
	printf("y is %d\n", y);
	printf("buffer is [%s]\n", buffer);
	//ft_putstr(buffer);
//	len_final = ft_strlen(buffer);
//	free(buffer);
	return (y);
}



int main()
{
	char c;

	c = 'a';
//	ft_printf("%*.*X\n", 1, 0, 10);
//	printf("%*.*X\n", 1, 0, 10);
	ft_printf("{abcdefghi}%-12u123456", 10, 272);
//	printf("\n%10d************%-10u123456789", 10, 20);
//	printf("\n%10d************%-10u************", 10, 20);
//	ft_printf("\n%*d**************%*u*************", 10, 10, -50, 20);
//	printf("\n%*d**************%*u*************", 10, 10, -50, 20);
//	ft_printf(":%c", '\0');
//	ft_printf(":affiche ca : %c", 0);
//	printf("\n:%4c", 0);
//	printf("\n:%.4c", 0);
//	printf("\n:%04c", 0);
//	ft_printf("%5c", 0);
//	printf("\n[%.d]", 0);
//	printf("\n[%-5.d]", 0);
//	printf("\n[%05.d]", 0);
//	printf("\n:%c", 0);
//	ft_printf("%.0d\n", 100);
//	ft_printf("%0151.*d", -88, 1234567899);
//	printf("\n%-.*d", 10, 123);
//	ft_printf(".%%.%%.%%.%%.%%.%%.%%.%%.");
//	printf("\n.%%.%%.%%.%%.%%.%%.%%.%%.\n");
//	ft_printf("%x\n", -2147483648);
//	printf("%lx\n", -2147483648);
//	ft_printf("1caractere 1 %c caractere 2 %c\n\n", 'a', 'c');
//	ft_printf("1caractere 1 %c caractere 2 %d\n\n", 'a', 12);
//	printf("1caractere 1 %c caractere 2 %c\n\n", 'a', 'c');
//	printf("\n{%c}", '\0');
	return (0);
}

