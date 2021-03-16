/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyel <seungyel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 19:52:41 by seungyel          #+#    #+#             */
/*   Updated: 2021/03/15 17:28:39 by seungyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "sources/ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *input, ...)
{
	int i;
	int j;
	int arg;
	int char_count;
	int min_width;
	int precision;
	int flag_minus;
	int flag_zero;
	int star_arg;
	char *char_arg;
	va_list	ap;

	i = 0;
	j = 0;
	min_width = 0;
	char_count = 0;
	flag_minus = 0;
	flag_zero = 0;
	precision = 0;
	va_start(ap, input);
	while (input[i] != 0)
	{
		if (input[i] == '%')
		{
			i++;
			while (input[i] == '-' || input[i] == '0') // flag확인
			{
				if (input[i] == '-')
				{
					flag_minus = 1;
				}
				else if (input[i] == '0')
				{
					flag_zero = 1;
				}
				i++;
			}
			if (input[i] == '*') // * 옵션 판단
			{
				min_width = va_arg(ap, int);
				i++;
			}
			while (ft_isdigit(input[i]) == 1) // min_width
			{
				min_width = min_width * 10 + (input[i] - '0');
				i++;
				j = 1;
				// while (j < min_width)
				// {
				// 	//ft_putchar(" ");
				// 	j++;
				// }
			}
			if (input[i] == '.') // precision
			{
				i++;
				if (input[i] == '*') // * 옵션 판단
				{
					precision = va_arg(ap, int);
					i++;
				}
				while (ft_isdigit(input[i]) == 1)
				{
					precision = precision * 10 + (input[i] - '0');
					i++;
				}
			}
			if (input[i] == 'd') // d 옵션 판단
			{
				arg = va_arg(ap, int);
				char_arg = ft_itoa(arg);
				while (char_arg[j] != 0)
				{
					ft_putchar(char_arg[j]);
					char_count++;
					j++;
				}
				i++;
			}
		}
		else
		{
			ft_putchar(input[i]);
			char_count++;
			i++;
		}
	}
	va_end(ap);
	return (char_count);
}

int	main()
{
	//int n = ft_printf("%5.7d\n", 9);
	//길이: 원래숫자길이 > precision > min_width; 원래 숫자가 더 중요
	// 원래숫자길이 < precision < min_width: 공백,0,원래숫자 프린트
	printf("a%8.7d", 999999);
	return (0);
}
