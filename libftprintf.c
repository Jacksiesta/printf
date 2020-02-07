/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <jherrald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:48:44 by jherrald          #+#    #+#             */
/*   Updated: 2020/02/07 15:10:40 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	init_struct(t_flag *flag)
{
	flag->zero_flag = 0; // pour pas avoir de valeur residuelle
	flag->minus_flag = 0;
	flag->width = 0;
	flag->precision = -1;
}

int	parser(va_list ap, const char *str, t_flag *flag) // activates flags
{
    int		x;

    x = 0;
	init_struct(flag);
	if (ft_isalpha(str[x]) == 0)
	{
        while (str[x] == '0')
        {
            flag->zero_flag = 1;
            x++;
        }
        while (str[x] == '-')
        {
            flag->minus_flag = 1;
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
                    flag->minus_flag = 1;
                    flag->width = -flag->width;
                }
            }
            else
                flag->width = ft_atoi(&str[x], &x);
        }
        if (str[x] == '.')
        {
            x++;
            if (str[x] == '*')
                flag->precision = va_arg(ap, int);
            else
                flag->precision = ft_atoi(&str[x], &x);
        }
	}
	if (flag->precision != -1 || flag->minus_flag != 0)
		flag->zero_flag = 0;
	if (str[x] == '%')
		return (1);
    return (0);
}

char	*convers_d(va_list ap, t_flag *flag)
{
	char	*init;
	int 	num;
	int		size;
	int		neg;
	char	*final;

	num = va_arg(ap, int);
	neg = (num < 0) ? 1 : 0;
	num = (num < 0) ? -num : num;
	init = ft_d(num);
	size = ft_strlen(init);
	final = ft_strdup("");
	if (flag->precision)
	{
		if (flag->precision > size)
			final = ft_strjoin(pad_maker('0', flag->precision - size), init);
		else
			final = ft_strdup(init); // gets rid of 0
	}
	if (flag->minus_flag)
	{
		if (flag->width > size)
			final = ft_strjoin(final, pad_maker(' ', flag->width - ft_strlen(final) - neg));
	}
	if (flag->zero_flag)
	{
		if (flag->width > size)
			final = ft_strjoin(pad_maker('0', flag->width - size - neg), final);
	}
	if (flag->width && !flag->minus_flag && !flag->zero_flag)
	{
		if (flag->width > size)
		{
			if (flag->precision == 0 && num == 0)
				return (pad_maker(' ', flag->width));
			if (neg)
				final = ft_strjoin(ft_strdup(pad_maker('-', 1)), final);
			if (flag->precision != -1 && flag->precision > size)
				final = ft_strjoin(pad_maker(' ', flag->width - neg - flag->precision), final);	
			else
				final = ft_strjoin(pad_maker(' ', flag->width - size - neg), final);
		}
	}
	if (neg && search_for('-', final))
		final = ft_strjoin(ft_strdup(pad_maker('-', 1)), final);
	return (final);
}

char	*convers_s_null(t_flag *flag)
{
	char	*final;
	
	final = ft_strdup("(null)");
	if (flag->precision == 0)
		if (flag->width)
			return (pad_maker(' ', flag->width));
	if (flag->precision > 0 && flag->precision <= 6)
		final = ft_substr(final, 0, flag->precision);
	if (flag->minus_flag && flag->width)
	{
		if (flag->width > ft_strlen(final))
			final = ft_strjoin(final, pad_maker(' ', flag->width - ft_strlen(final)));
		else
			return (final);
	}
	if (flag->width && !flag->minus_flag)
	{
		if (flag->width > ft_strlen(final))
			final = ft_strjoin(pad_maker(' ', flag->width - ft_strlen(final)), final);
		else
			return (final);
	}
	return (final);
}

char	*convers_s(va_list ap, t_flag *flag)
{
	char	*init;
	char	*final;
	int		size;
	
	final = ft_strdup("");
	init = va_arg(ap, char *);
	if (init)
		size = ft_strlen(init);
	if (init == NULL)
		return (convers_s_null(flag));
	if (flag->zero_flag && flag->width > ft_strlen(init))
		return (ft_strjoin(pad_maker('0', flag->width - ft_strlen(init)), init));
	if (flag->precision != -1)
	{
		if (flag->precision < size)
			final = ft_strdup(cropped_str(init, flag->precision));
		else
			final = ft_strdup(init);
	}
	if (flag->precision == -1)
		final = ft_strdup(init);	
	if (flag->minus_flag)
		if (flag->width > ft_strlen(final)) // size of init
			final = ft_strjoin(final, pad_maker(' ', flag->width - ft_strlen(final)));
	if (flag->width && !flag->minus_flag)
	{
		if (flag->width > ft_strlen(final))
			final = ft_strjoin(pad_maker(' ', flag->width - ft_strlen(final)), final);	
	}
	return (final);
}

char	*convers_prc(t_flag *flag)
{
	char	*final;
	int		size;

	final = ft_strdup("%");
	if (flag->minus_flag)
		if (flag->width > 1)
			return (ft_strjoin(final, pad_maker(' ', flag->width - 1)));
	if (flag->zero_flag)
		if (flag->width > 1)
			return (ft_strjoin(pad_maker('0', flag->width - 1), final));
	if (flag->width && !flag->minus_flag && !flag->zero_flag)
		if (flag->width > 1)
			return (ft_strjoin(pad_maker(' ', flag->width - 1), final));
	return (final);
}

char	*convers_u(va_list ap, t_flag *flag)
{
    char	*init;
    int 	num;
    int		size;
    char	*final;

    num = va_arg(ap, int);
    init = ft_u(num);
    size = ft_strlen(init);
	if (ft_strncmp(init, "4294967295", size) == 0)
		return (ft_strdup("4294967295"));
    final = ft_strdup("");
    if (flag->precision)
    {
        if (flag->precision > size)
            final = ft_strjoin(pad_maker('0', flag->precision - size), init);
        else
            final = ft_strdup(init); // gets rid of 0
    }
    if (flag->minus_flag)
    {
        if (flag->width > size)
            final = ft_strjoin(final, pad_maker(' ', flag->width - ft_strlen(final)));
    }
    if (flag->zero_flag)
    {
        if (flag->width > size)
            final = ft_strjoin(pad_maker('0', flag->width - size), final);
    }
    if (flag->width && !flag->minus_flag && !flag->zero_flag)
    {
        if (flag->width > size)
        {
            if (flag->precision == 0 && num == 0)
                return (pad_maker(' ', flag->width));
            if (flag->precision != -1 && flag->precision > size)
                final = ft_strjoin(pad_maker(' ', flag->width - flag->precision), final);
            else
                final = ft_strjoin(pad_maker(' ', flag->width - size), final);
        }
    }
    return (final);
}

char	*convers_hex_low_zero(t_flag *flag)
{
	char	*final;

	final = ft_strdup("0");
	if (flag->minus_flag)
		if (flag->width > 1)
			final = ft_strjoin(final, pad_maker(' ', flag->width - 1));
	if (flag->zero_flag)
		if (flag->width > 1)
			final = ft_strdup(pad_maker('0', flag->width));
	if (flag->width > 1 && !flag->minus_flag && !flag->zero_flag)
		final = ft_strjoin(pad_maker(' ', flag->width - 1), final);
	return (final);
}

char	*convers_hex_low(va_list ap, t_flag *flag)
{
	char	*final;
	char	*init;
	unsigned int		num;
	int		size;

	num = va_arg(ap, int);
	init = ft_x(num);
    size = ft_strlen(init);
   	final = ft_strdup("");
	if (num == 0 && flag->precision < 0)
		return (convers_hex_low_zero(flag));
	if (num == 4294967295)
		return ("ffffffff");
    if (flag->precision)
    {
        if (flag->precision > size)
            final = ft_strjoin(pad_maker('0', flag->precision - size), init);
        else
            final = ft_strdup(init); // gets rid of 0
    }
    if (flag->minus_flag)
    {
        if (flag->width > size)
            final = ft_strjoin(final, pad_maker(' ', flag->width - ft_strlen(final)));
    }
    if (flag->zero_flag)
    {
        if (flag->width > size)
            final = ft_strjoin(pad_maker('0', flag->width - size), final);
    }
    if (flag->width && !flag->minus_flag && !flag->zero_flag)
    {
        if (flag->width > size)
        {
            if (flag->precision == 0 && num == 0)
                return (pad_maker(' ', flag->width));
            if (flag->precision != -1 && flag->precision > size)
                final = ft_strjoin(pad_maker(' ', flag->width - flag->precision), final);
            else
                final = ft_strjoin(pad_maker(' ', flag->width - size), final);
        }
    }
    return (final);
}

int		size_percent(const char *str)
{
    int x;
    int	y;

    x = 0;
    y = 1;
    while (str[x] != '%')
        x++;
    while (ft_isalpha(str[x]) == 0)
    {
        x++;
        y++;
    }
    return (y);
}

int		size_percent_percent(const char *str)
{
	int x;

	x = 0;
	while (str[x] != '%')
		x++;
	return (x);
}


int		ft_printf(const char *coucou, ...)
{
	int		x;
	int		y;
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
			parser(ap, &coucou[x + 1], &flag);
			if (parser(ap, &coucou[x + 1], &flag) == 1)
			{
				len = size_percent_percent(&coucou[x + 1]) + 1;
				temp = convers_prc(&flag);
				x = x + len;
			}
		    len = size_percent(&coucou[x]);
			if (coucou[x + len - 1] == 's')
			{
				temp = convers_s(ap, &flag);
				x = x + len - 1;
			}
			else if (coucou[x + len - 1] == 'c')
				ft_c(ap);
			else if (coucou[x + len - 1] == 'd' || coucou[x + len - 1] == 'i')
			{
				temp = convers_d(ap, &flag);
				x = x + len - 1;
			}
			else if (coucou[x + len - 1] == 'x' || coucou[x + len - 1] == 'X')
			{
				temp = convers_hex_low(ap, &flag);
				if (coucou[x + len - 1] == 'X' && temp == "ffffffff")
					temp = ft_strdup("FFFFFFFF");
				else if (coucou[x + len - 1] == 'X')
					temp = ft_str_upper(temp);
				x = x + len - 1;
			}
			else if (coucou[x + len - 1] == 'X')
				ft_xx(ap);
			else if (coucou[x + len - 1] == 'u')
			{
				temp = convers_u(ap, &flag);
				x = x + len - 1;
			}
			else if (coucou[x + len - 1] == 'p')
				ft_p(ap);
			y = y + ft_strlen(temp) - 1;
			buffer = ft_strjoin(buffer, temp);
	//		x = x + len - 1;
		}
		else
			buffer[y] = coucou[x];
		x++;
		y++;
	}
	ft_putstr(buffer);
	return (ft_strlen(buffer));
}

/*
int main()
{
//	printf("%d\n", ft_printf("YES%7d", 33));
	printf("\n%X\n", 42949672);
	ft_printf("%X", 42949672);
//	printf("[%d] [%d]", 12345, 56789);
	return (0);
}
*/
