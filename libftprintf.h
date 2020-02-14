/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherrald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 18:07:46 by jherrald          #+#    #+#             */
/*   Updated: 2020/02/14 20:31:33 by jherrald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>
# include "libft_for_printf/libft.h"

typedef struct		s_flag
{
	int 			zero;
	int 			minus;
	int				width;
	int				precision;
	int				percent;
	int				alone_percent;
}					t_flag;

typedef struct		s_final
{
	char	*buffer;
	int		pos;
	int		taille;
}					t_final;

int	    printf(const char *coucou, ...);
char	*ft_d(int num);
char	ft_s(va_list ap);
char	ft_c(va_list ap);
char	*ft_u(unsigned int num);
void	ft_putstr(char *str);
void	ft_putchar(char c);
int		ft_lenght_int(int num);
int		ft_lenght_hex(long long unsigned int num);
char	ft_hex_conversion(unsigned long long int n);
char	*ft_x(long long unsigned int num);
char	ft_hex_maj_conversion(int n);
char	*ft_xx(va_list ap);
char	*ft_p(va_list ap);
char	*pad_maker(char c, int len);
int		search_for(char c, const char *str);
char	*cropped_str(char *str, int len);
char	*convers_hex_low(va_list ap, t_flag *flag);
char	*add_char_to_str(char c, char *str, int i);
char	*ft_percent_alone(va_list ap, t_flag *flag);
char	*convers_d(va_list ap, t_flag *flag);
char	*convers_s_null(t_flag *flag);
char	*convers_s(va_list ap, t_flag *flag);
char	*convers_u(va_list ap, t_flag *flag);
char	*convers_hex_zero(t_flag *flag);
char	*convers_hex(va_list ap, t_flag *flag);
char	*convers_hex_precision(t_flag *flag, int size, char *init);
char	*convers_hex_width(t_flag *flag, char *init, char *fn);
char	*temp_maker(const char *format, t_flag *flag, va_list ap, int len);
char	*convers_char(va_list ap, t_flag *flag);
char	*convers_ptr(va_list ap, t_flag *flag);
char	*convers_double_percent(t_flag *flag);
char	*convers_ptr(va_list ap, t_flag *flag);
char	*convers_char(va_list ap, t_flag *flag);
char	*convers_prc(t_flag *flag);

#endif
