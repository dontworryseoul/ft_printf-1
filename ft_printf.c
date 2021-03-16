/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyel <seungyel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 19:52:41 by seungyel          #+#    #+#             */
/*   Updated: 2021/03/17 00:04:44 by seungyel         ###   ########.fr       */
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
		min_width = va_arg(ap, int); // 해야할일: min_width가 음수일 때 -flag가 on
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
	g_flag.flag_precision = 0;
	if (**format == '.') // precision
	{
		g_flag.flag_precision = 1;
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

void	ft_c_type(va_list ap) //c까지 출력이 된다.
{
  char type;

  type = va_arg(ap, int);
  if (g_flag.min_width == 0)
    ft_putchar(type);
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
}

/*
min_width를 비교 argument_len

if (precision < argument_len) precision.다음에 나오는 숫자들
	argument_len = precision에 넣는다.
if (precision > argument_len)
	
	if (min_width < argument_len)
		argument_len을 프린트한다.
	if (min_width > argument_len)
		flag_minus가 있으면 1.argument_len출력 2. flag_minus-argument_len만큼 공백출력
		flag_minus가 없으면 1.flag_minus-argument_len만큼 공백출력 후, 2. argument_len출력
*/
void	ft_s_type(va_list ap)
{
	char *type;
	int gap;
	int argument_len;
	
	type = va_arg(ap, char*);
	if (type == NULL)
		type = "(null)";
	argument_len = ft_strlen(type); //가변인자의 길이
	if (g_flag.precision < 0)
		g_flag.precision = argument_len; // precision의 값이 음수면 무시하기 위헤.
	if (g_flag.precision < argument_len && g_flag.flag_precision == 1)
		argument_len = g_flag.precision;
	if (g_flag.min_width <= argument_len)
	{
		while (argument_len--)
			ft_putchar(*type++);
	}
	else if (g_flag.min_width > argument_len)
	{
		gap = g_flag.min_width - argument_len;
		if (g_flag.flag_minus == 1)
		{
			while (argument_len--)
				ft_putchar(*type++);
			while (gap--)
				ft_putchar(' ');
		}
		else
		{
			while (gap--)
				ft_putchar(' ');
			while (argument_len--)
				ft_putchar(*type++);
		}
	}
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
  else if (**format == 's')
	ft_s_type(ap);
  // else if (**format == '%')
  // else
  ++(*format);
}

// if (*format == '%') //%%를 출력
      // {
      //   ++format;
      //   ft_putchar('%');
	  // }
//ft_bzero(g_flag, 5);

int	ft_printf(const char *format, ...)
{
	int i;
	int j;
	int arg;
	//int star_arg;
	char *char_arg;
	va_list	ap;

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
		}
      //d 또는 다른게 있는지 확인..d,i,u,x,X,p,c,s,%
      //%를 한번 더 만나는 지 확인 -> 타입?
    	else
		{
			ft_putchar(*format);
			++format;
		}
		if (*format == 'd') // d 옵션 판단
		{
			arg = va_arg(ap, int);
			char_arg = ft_itoa(arg);
			while (char_arg[j] != 0)
			{
				ft_putchar(char_arg[j]);
				j++;
			}
			i++;
		}
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
	//ft_printf("%-8d\n", 42);
	// ft_printf("|%c|\n", 'a');
	// ft_printf("|%-c|\n", 'a');
	// ft_printf("|%-5c|\n", '\0');
	ft_printf("|%3.2s|\n", "abcde");
	ft_printf("|%-s|\n", "abcde");
	ft_printf("|%-3s|\n", "abcde");
	ft_printf("|%7s|\n", "abcde");
	//ft_printf("|%-7.*s|\n", -3,"abcde");
	printf("answer : |%*.3s|\n", -8,"abcde");
	return (0);
}