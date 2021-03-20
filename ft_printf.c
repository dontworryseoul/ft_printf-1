/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyel <seungyel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 19:52:41 by seungyel          #+#    #+#             */
/*   Updated: 2021/03/20 21:17:22 by seungyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

typedef struct s_d_vars t_d_vars;

struct s_d_vars
{
	int zero_remains;
	int num_len;
	long long num;
	unsigned int u_num;
	unsigned int x_num;
	int is_negative;
	char symbol_of_padding;
	char *str_of_num;
};

void	ft_minus_zero_check(const char **format)
{
	g_flag.flag_zero = 0;
	g_flag.flag_minus = 0;
	while (**format == '-' || **format == '0')
	{
		if (**format == '-')
			g_flag.flag_minus = 1;
		else if (**format == '0')
			g_flag.flag_zero = 1;
		++(*format);
	}
}

int		ft_min_width(const char **format, va_list ap)
{
	int min_width;

	min_width = 0;
	if (**format == '*')
	{
		min_width = va_arg(ap, int);
		++(*format);
		if (min_width < 0)
		{
			g_flag.flag_minus = 1;
			min_width *= -1;
		}
	}
	while (ft_isdigit(**format) == 1)
	{
		min_width = min_width * 10 + (**format - '0');
		++(*format);
	}
	return (min_width);
}

int		ft_precision(const char **format, va_list ap)
{
	int	precision;

	precision = 0;
	g_flag.flag_precision = 0;
	if (**format == '.')
	{
		g_flag.flag_precision = 1;
		++(*format);
		if (**format == '*')
		{
			precision = va_arg(ap, int);
			++(*format);
		}
		while (ft_isdigit(**format) == 1)
		{
			precision = precision * 10 + (**format - '0');
			++(*format);
		}
	}
	return (precision);
}

void	d_no_minus_flag(t_d_vars var)
{
	int padding_size;

	if (g_flag.flag_zero && var.is_negative)
		ft_putchar('-');
	if (g_flag.precision < var.num_len)
		padding_size = g_flag.min_width - var.num_len - var.is_negative;
	else
		padding_size = g_flag.min_width - g_flag.precision - var.is_negative;
	while (padding_size-- > 0)
			ft_putchar(var.symbol_of_padding);
	if (!g_flag.flag_zero && var.is_negative)
		ft_putchar('-');
	var.zero_remains = g_flag.precision - var.num_len;
	while (var.zero_remains-- > 0)
		ft_putchar('0');
	while ((var.num_len)--)
		ft_putchar(*(var.str_of_num)++);
}

void	d_minus_flag(t_d_vars var)
{
	int padding_size;

	if (var.is_negative)
		ft_putchar('-');
	if (g_flag.precision < var.num_len)
		padding_size = g_flag.min_width - var.num_len - var.is_negative;
	else
		padding_size = g_flag.min_width - g_flag.precision - var.is_negative;
	var.zero_remains = g_flag.precision - var.num_len;
	while (var.zero_remains-- > 0)
		ft_putchar('0');
	while ((var.num_len)--)
		ft_putchar(*(var.str_of_num)++);
	while (padding_size-- > 0)
		ft_putchar(var.symbol_of_padding);
}

void  ft_d_type(va_list ap)
{
	t_d_vars var;

	var.zero_remains = 0;
	var.is_negative = 0;
	var.num = va_arg(ap, int);
	if (g_flag.flag_zero)
		var.symbol_of_padding = '0';
	else
		var.symbol_of_padding = ' ';
	if (var.num < 0)
	{
		var.num *= (-1);
		var.is_negative = 1;
	}
	var.str_of_num = ft_itoa(var.num);
	if (!var.str_of_num)
		return ;
	var.num_len = ft_strlen(var.str_of_num);
	if (g_flag.flag_minus == 0)
		d_no_minus_flag(var);
	else
		d_minus_flag(var);
	free(var.str_of_num);
}

void	u_no_minus_flag(t_d_vars var)
{
	int padding_size;

	if (g_flag.precision < var.num_len)
		padding_size = g_flag.min_width - var.num_len;
	else
		padding_size = g_flag.min_width - g_flag.precision;
	while (padding_size-- > 0)
			ft_putchar(var.symbol_of_padding);
	var.zero_remains = g_flag.precision - var.num_len;
	while (var.zero_remains-- > 0)
		ft_putchar('0');
	while ((var.num_len)--)
		ft_putchar(*(var.str_of_num)++);
}

void	u_minus_flag(t_d_vars var)
{
	int padding_size;

	if (g_flag.precision < var.num_len)
		padding_size = g_flag.min_width - var.num_len;
	else
		padding_size = g_flag.min_width - g_flag.precision;
	var.zero_remains = g_flag.precision - var.num_len;
	while (var.zero_remains-- > 0)
		ft_putchar('0');
	while ((var.num_len)--)
	{
		//오늘의 숙제: 여기 조건 설정. -> u고쳐보기.
		if (g_flag.flag_precision == 1 && g_flag.precision == 0 && )
			if (*var.str_of_num == 0)
				*var.str_of_num = ' ';
		ft_putchar(*(var.str_of_num)++);
	}
	while (padding_size-- > 0)
		ft_putchar(var.symbol_of_padding);
}

void  ft_u_type(va_list ap)
{
	t_d_vars var;

	var.zero_remains = 0;
	var.u_num = va_arg(ap, unsigned int);
	if (g_flag.flag_zero)
		var.symbol_of_padding = '0';
	else
		var.symbol_of_padding = ' ';
	var.str_of_num = ft_itoa(var.u_num);
	if (!var.str_of_num)
		return ;
	var.num_len = ft_strlen(var.str_of_num);
	if (g_flag.flag_minus == 0)
		u_no_minus_flag(var);
	else
		u_minus_flag(var);
	free(var.str_of_num);
}

void	x_no_minus_flag(t_d_vars var)
{
	int padding_size;

	if (g_flag.precision < var.num_len)
		padding_size = g_flag.min_width - var.num_len;
	else
		padding_size = g_flag.min_width - g_flag.precision;
	while (padding_size-- > 0)
			ft_putchar(var.symbol_of_padding);
	var.zero_remains = g_flag.precision - var.num_len;
	while (var.zero_remains-- > 0)
		ft_putchar('0');
	while ((var.num_len)--)
		ft_putchar(*(var.str_of_num)++);
}

void	x_minus_flag(t_d_vars var)
{
	int padding_size;

	if (g_flag.precision < var.num_len)
		padding_size = g_flag.min_width - var.num_len;
	else
		padding_size = g_flag.min_width - g_flag.precision;
	var.zero_remains = g_flag.precision - var.num_len;
	while (var.zero_remains-- > 0)
		ft_putchar('0');
	while ((var.num_len)--)
		ft_putchar(*(var.str_of_num)++);
	while (padding_size-- > 0)
		ft_putchar(var.symbol_of_padding);
}

void  ft_x_type(va_list ap, char type)
{
	t_d_vars var;

	var.zero_remains = 0;
	var.x_num = va_arg(ap, int);
	if (g_flag.flag_zero)
		var.symbol_of_padding = '0';
	else
		var.symbol_of_padding = ' ';
	var.str_of_num = ft_itoa_hex(var.x_num, type);
	if (!var.str_of_num)
		return ;
	var.num_len = ft_strlen(var.str_of_num);
	if (g_flag.flag_minus == 0)
		u_no_minus_flag(var);
	else
		u_minus_flag(var);
	free(var.str_of_num);
}

void	ft_p_type(va_list ap, int i, int j, int index)
{
	int			gap;
	char		out[20];
	char		out_reverse[13];
	char		*numbers;
	long long	num;

	numbers = "0123456789abcdef";
	num = (long long)va_arg(ap, void *);
	while (num >= 16)
	{
		out_reverse[i++] = numbers[num % 16];
		num /= 16;
	}
	out_reverse[i] = numbers[num];
	index = i;
	out[0] = '0';
	out[1] = 'x';

	if (g_flag.flag_precision == 1 && g_flag.precision == 0 && num == 0)
		out[2] = '\0';
	else
	{
		while (j + 2 <= index + 2)
		{
			out[j + 2] = out_reverse[i--];
			j++;
		}
	}
	out[j + 2] = '\0';
	gap = g_flag.min_width - j - 2;
	j = 0;
	if (g_flag.flag_minus == 1)
	{
		while (out[j])
			ft_putchar(out[j++]);
		while (gap-- > 0)
			ft_putchar(' ');
	}
	else
	{
		while (gap-- > 0)
			ft_putchar(' ');
		while (out[j])
			ft_putchar(out[j++]);
	}
}

void	ft_type_check(const char **format, va_list ap)
{
	if (**format == 'd')
		ft_d_type(ap);
	else if (**format == 'i')
		ft_d_type(ap);
	else if (**format == 'u')
		ft_u_type(ap);
	else if (**format == 'x')
		ft_x_type(ap, 'x');
	else if (**format == 'X')
		ft_x_type(ap, 'X');
	else if (**format == 'p')
		ft_p_type(ap, 0, 0, 0);
	else if (**format == 'c')
		ft_c_type(ap);
	else if (**format == 's')
		ft_s_type(ap);
	else if (**format == '%')
		ft_percent_type();
	++(*format);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;

	g_flag.char_count = 0;
	va_start(ap, format);
	if (format == NULL)
		return (0);
	while (*format)
	{
		if (*format++ == '%')
		{
			ft_minus_zero_check(&format);
			g_flag.min_width = ft_min_width(&format, ap);
			g_flag.precision = ft_precision(&format, ap);
			ft_type_check(&format, ap);
		}
		else
			ft_putchar(*(format - 1));
	}
	va_end(ap);
	return (g_flag.char_count);
}
