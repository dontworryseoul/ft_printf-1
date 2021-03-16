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

#include "ft_printf.h"
#include <stdio.h> // 최종 제출시 삭제 필요

void  ft_minus_zero_check(const char **format)
{
  g_flag.flag_zero = 0;
  g_flag.flag_minus = 0;
  while (**format == '-' || **format == '0') // flag확인
	{
    if (**format == '-')
			g_flag.flag_minus = 1;
		else if (**format == '0')
			g_flag.flag_zero = 1;
    ++(*format);
	}
}

int  ft_min_width(const char **format, va_list ap)
{
  int min_width;

  min_width = 0;
	if (**format == '*') // * 옵션 판단
	{
		min_width = va_arg(ap, int);
    ++(*format);
	}
  while (ft_isdigit(**format) == 1)
	{
		min_width = min_width * 10 + (**format - '0');
    ++(*format);
	}
  return (min_width);
}

int ft_precision(const char **format, va_list ap)
{
  int precision;

  precision = 0;
  if (**format == '.') // precision
	{
    ++(*format);
		if (**format == '*') // * 옵션 판단
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

void ft_c_type(va_list ap)
{
  char type;

  type = va_arg(ap, int);
  if (g_flag.min_width == 0)
  {//min_width가 있는지 확인. 없으면 바로 출력
    ft_putchar(type);
  }
  else
  {
    if (g_flag.flag_minus == 1)
    {
      ft_putchar(type);
      while (--g_flag.min_width)
        ft_putchar(' ');
    }
    else if (g_flag.flag_minus == 0)
    {
      while (--g_flag.min_width)
        ft_putchar(' ');
      ft_putchar(type);
    }
  }
  //min_width가 있고 
  //flag_minus가 있으면 c 출력후 min_width - 1만큼 공백

  //min_width가 있고 
  //flag_minus가 없으면 min_width - 1 공백 출력후 c
}

void  ft_type_check(const char **format, va_list ap)
{
 // int, char*, char,,?->X, 

  // if (**format == 'd')
  // //ft_d_type(ap);
  // else if (**format == 'i')
  // else if (**format == 'u')
  // else if (**format == 'x')
  // else if (**format == 'X')
  // else if (**format == 'p')
  if (**format == 'c')
    ft_c_type(ap);
  // else if (**format == 's')
  // else if (**format == '%')
  // else
}
// if (*format == '%') //%%를 출력
      // {
      //   ++format;
      //   ft_putchar('%');
      // }

int	ft_printf(const char *format, ...)
{
	int i;
	int j;
	int arg;
	//int star_arg;
	char *char_arg;
	va_list	ap;
  //ft_bzero(g_flag, 5);

	i = 0;
	j = 0;
	g_flag.char_count = 0;
	va_start(ap, format);
  if (format == NULL)
    return (0);
	while (*format)
	{
    if (*format == '%')
		{
      ++format;
			ft_minus_zero_check(&format);
      g_flag.min_width = ft_min_width(&format, ap);
      g_flag.precision = ft_precision(&format, ap);
      ft_type_check(&format, ap);
      //d 또는 다른게 있는지 확인..d,i,u,x,X,p,c,s,%
      //%를 한번 더 만나는 지 확인 -> 타입?

      //출력 
      // precision 
    }
    else
      ++format;
	// 		if (input[i] == 'd') // d 옵션 판단
	// 		{
	// 			arg = va_arg(ap, int);
	// 			char_arg = ft_itoa(arg);
	// 			while (char_arg[j] != 0)
	// 			{
	// 				ft_putchar(char_arg[j]);
	// 				char_count++;
	// 				j++;
	// 			}
	// 			i++;
	// 		}
	// 	}
	// 	else
	// 	{
	// 		ft_putchar(*format);
	// 		char_count++;
	// 		i++;
	// 	}
	}
	va_end(ap);
	return (g_flag.char_count);
}

int	main()
{
	//int n = ft_printf("%5.7d\n", 9);
	//길이: 원래숫자길이 > precision > min_width; 원래 숫자가 더 중요
	// 원래숫자길이 < precision < min_width: 공백,0,원래숫자 프린트
	// ft_printf("a%08.7c\n", 999999);
  // ft_printf("%-8d\n", 42);
  ft_printf("|%c|\n", 'a');
  ft_printf("|%-c|\n", 'a');
  ft_printf("|%-5c|\n", '\0');
  // printf("a%8.7d\n", 999999);
  // printf("%8d\n", 42);
	return (0);
}

//