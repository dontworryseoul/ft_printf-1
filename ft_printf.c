/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyel <seungyel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 19:52:41 by seungyel          #+#    #+#             */
/*   Updated: 2021/03/13 01:30:31 by seungyel         ###   ########.fr       */
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
	int flag_minus;
	int flag_zero;
	char *char_arg;
	va_list	ap;

	i = 0;
	j = 0;
	min_width = 0;
	char_count = 0;
	flag_minus = 0;
	flag_zero = 0;
	va_start(ap, input);
	while (input[i] != 0)
	{
		if (input[i] == '%')
		{
			i++;
			while (input[i] == '-' || input[i] == '0')
			{
				if (input[i] == '-') // flag확인
				{
					flag_minus = 1;
				}
				else if (input[i] == '0')
				{
					flag_zero = 1;
				}
				i++;
			}
			printf("flag_minus=%d\n", flag_minus);
			printf("flag_zero=%d\n", flag_zero);
			while (input[i] != 0)
			{
				if (input[i] == 'd')
				{
					arg = va_arg(ap, int);
					char_arg = ft_itoa(arg);
					while (char_arg[j] != 0)
					{
						ft_putchar(char_arg[j]);
						char_count++;
						j++;
					}
					break ;
				}
				else
				{
					if (ft_isdigit(input[i]) == 1)
					{
						min_width = min_width * 10 + (input[i] - '0');
					}
				}
				i++;
			}
			printf("min_width= %d\n", min_width);
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
	int n = ft_printf("aa%-30daa\n", 10);
	printf("%d\n", n);
	return (0);
}
