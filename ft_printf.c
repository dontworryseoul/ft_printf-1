/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyel <seungyel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 19:52:41 by seungyel          #+#    #+#             */
/*   Updated: 2021/03/12 23:45:27 by seungyel         ###   ########.fr       */
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
	char *char_arg;
	va_list	ap;

	i = 0;
	j = 0;
	char_count = 0;
	va_start(ap, input);
	while (input[i] != 0)
	{
		if (input[i] == '%')
		{
			while (ERROR != 0)
			{
				if (input[++i] == 'd')
				{
					i++;
					arg = va_arg(ap, int);
					char_arg = ft_itoa(arg);
					while (char_arg[j] != 0)
					{
						ft_putchar(char_arg[j]);
						char_count++;
						j++;
					}
				}
			}	
			else
			{
				min_width = input[i];
				char_count = char_count + min_width;
				printf("min_width: %d", min_width);
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
	int n = ft_printf("aa%3daa\n", 10);
	printf("%d\n", n);
	return (0);
}
