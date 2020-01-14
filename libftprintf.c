/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:48:44 by jherrald          #+#    #+#             */
/*   Updated: 2020/01/14 18:59:39 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_list	*init_struct(t_flag *flag)
{
	flag->zero_flag = 0; // pour pas avoir de valeur residuelle
	flag->minus_flag = 0;
	flag->width = 0;
	flag->precision = -1;
}

example () //example of how to use structure
{
	t_flag	*struc;

	struc = (t_flag*)malloc(sizeof(t_flag)); // place allouee pour la structure
	struc = init_struc(struc); // 
	if (struc->zero_flag == 1) // either exists or doesn't (1 or 0)

	else

}

int		param_width(va_list ap, char *str)
{
	int x;

	x = 0;


}


int		param_zero_flag(va_list ap, char *str) // value of flag
{
	int 	x;
	int		y;
	char	*str_param;
	int		param;

	x = 0;
	while (str[x] != '0')
		x++;
	x = x + 1;
	if (str[x] == '*')
		param = va_arg(ap, int);
	while (str[x] >= 0 && str[x] <= 9)
	{
		*str_param = str[x];
		str_param++;
		x++;
	}
	param = ft_atoi(str_param);
	return (param);
}

char	*parser(char *str, t_flag *flag)
{
	int x;

	x = 0;
	while (str[x])
	{
		if (ft_isdigit(str[x]) == 1)
			flag->width = 1;
		if (str[x] == '0')
		{
			flag->zero_flag = 1;
			
		}
		if (str[x] == '-')
			flag->minus_flag = 1;
		if (str[x] == '*' || ft_isdigit(str[x]) == 1)
			flag->width = 1;
		if (str[x] == '.' && x++)
			if (str[x] == '*' || ft_isdigit(str[x]) == 1)
				flag->precision = 0;
		x++;	
	}	
}

char	ft_s(va_list ap)
{
	char	*value;
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

int		ft_lenght_int(int num)
{
	int x;

	x = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		x++;
		num *= -1;
	}
	while (num > 0)
	{
		num = num / 10;
		x++;
	}
	return (x);
}

int		ft_lenght_hex(int num)
{
	int x;

	x = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		x++;
		num *= -1;
	}
	while (num > 0)
	{
		num = num / 16;
		x++;
	}
	return (x);
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		ft_putchar(*str);
		str++;
	}
}

char	*ft_d(va_list ap)
{
	int			num;
	int			size;
	int			sign;
	char		*new;

	num = va_arg(ap, int);
	if (num == -2147483648)
		return (ft_strdup("-2147483648"));
	sign = (num < 0) ? 1 : 0;
	num = (num < 0) ? -num : num;
	size = ft_lenght_int(num);
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
	ft_putstr(new);
	return (NULL);
}

char	ft_hex_conversion(int n)
{
	int		mod;
	char	*hex;

	if (!(hex = ft_strdup("0123456789abcdef")))
		return (0);
	if (n)
	{
		mod = n % 16;
		return (hex[mod]);
	}
	return (0);
}

char	*ft_x(va_list ap)
{
	int		num;
	int		size;
	char	*new;

	num = va_arg(ap, int);
	size = ft_lenght_hex(num);
	if (!(new = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	new[size] = '\0';
	while (size-- > 0)
	{
		new[size] = ft_hex_conversion(num);
		num = num / 16;
	}
	ft_putstr(new);
	return (NULL);
}

char	ft_hex_maj_conversion(int n)
{
	int		mod;
	char	*maj_hex;

	maj_hex = ft_strdup("0123456789ABCDEF");
	while (n)
	{
		mod = n % 16;
		return (maj_hex[mod]);
	}
	return (0);
}

char	*ft_xx(va_list ap)
{
	unsigned int		num;
	int		size;
	char	*new;

	num = va_arg(ap, unsigned int);
	size = ft_lenght_hex(num);
	if (!(new = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	new[size] = '\0';
	while (size-- > 0)
	{
		new[size] = ft_hex_maj_conversion(num);
		num = num / 16;
	}
	ft_putstr(new);
	return (NULL);
}

int		ft_u(va_list ap)
{
	unsigned int	num;
	int				size;
	char			*new;

	num = va_arg(ap, unsigned int);
	size = ft_lenght_int(num);
	if (!(new = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	new[size] = '\0';
	while (size-- > 0)
	{
		new[size] = (num % 10) + '0';
		num = num / 10;
	}
	ft_putstr(new);
	return (1);	
}

int		ft_p(va_list ap)
{
	//cast in void*	
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
			if (coucou[x + 1] == 'x')
				ft_x(ap);
			if (coucou[x + 1] == 'X')
				ft_xx(ap);
			if (coucou[x + 1] == 'u')
				ft_u(ap);
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
	int		numba = 35;
	ft_printf("unsigned test : %x \n", numba);
	printf("OG test : %x \n", numba);
	printf("%d\n", numba);
//	ft_printf("un : %s troie \n", oups);
//	ft_printf("number test = %d nono \n", numba);
	//printf("what : %s WHAT \n", oups);
	//printf("coucoucou %.4s", oups);
//	return (0);
}
