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
		min_width = va_arg(ap, int);
    ++(*format);
    if (min_width < 0) //음수일때
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

  //어떤 값이 들어온다. int char
//va_arg()를 받을 땐, 16진수 12개를 커버할 수 있는 범위의 자료형.
  //-> long long
  //받아온 수를 16을 나누고 나머지를 출력
void  ft_p_type(va_list ap) // 16진수로 된 주소표기
{
  int i;
  int len;
  char out[13];
  char *numbers;
  long long num;
//long long타입이여야하는데
//https://en.cppreference.com/w/cpp/utility/variadic/va_arg    // 참고 링크 
// one type is pointer to void and the other is a pointer to a character type (char, signed char, or unsigned char).//한 유형은 void에 대한 포인터이고 다른 유형은 문자 유형(char, signed char 또는 서명되지 않은 문자)에 대한 포인터입니다.,,
  i = 0;
  numbers = "0123456789abcdef";
  num = (long long)va_arg(ap, void*);//long long형태로 된 주소값.
  out[i]='\0';
  while (num >= 16)
  {
    len = num % 16;
    out[--i] = numbers[len];
    num = num / 16;
  }
  
  printf("%s",out); 
  //금요일까지 숙제: 거꾸로 프린트 할 수 있도록(p 다듬기).
  //s의 주소값. putchar를 변경하는 방법도 있음.
  //u를 어떻게 할지 생각해보기.
  //테스터기 돌릴 수 있는 환경을 만들어보자.
  //코드 정리(불필요한거 삭제) norm이나 함수들을 정리해보자.
  //ft_putchar를 변경했다는 표시. 함수명 바꾸기

  //3일동안 타입 3개씩.
}
//0의 갯수의 정보를 토대로 0패딩을 할 수 있다? -> d할 때?
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

void  ft_type_check(const char **format, va_list ap)
{
  // if (**format == 'd')
  // //ft_d_type(ap);
  // else if (**format == 'i')
  // else if (**format == 'u')
  // else if (**format == 'x')
  // else if (**format == 'X')
  if (**format == 'p')
    ft_p_type(ap);
  else if (**format == 'c')
    ft_c_type(ap);
  else if (**format == 's')
	  ft_s_type(ap);
  else if (**format == '%')
    ft_percent_type();
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
		// if (*format == 'd') // d 옵션 판단
		// {
		// 	arg = va_arg(ap, int);
		// 	char_arg = ft_itoa(arg);
		// 	while (char_arg[j] != 0)
		// 	{
		// 		ft_putchar(char_arg[j]);
		// 		j++;
		// 	}
		// 	i++;
		// }
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
	// ft_printf("|%3.2|\n", "abcde");
	// ft_printf("|%-s|\n", "abcde");
	// ft_printf("|%-3s|\n", "abcde");
	// ft_printf("|%7s|\n", "abcde");
	// //ft_printf("|%-7.*s|\n", -3,"abcde");
	// printf("answer : |%*.3s|\n", -8,"abcde");
  // ft_printf("|%.%|\n");
	// ft_printf("|%.0%|\n");
	// ft_printf("|%5.0%|\n");
	// ft_printf("|%5.%|\n");
	// ft_printf("|%*%|\n", 5);
	// ft_printf("|%*%|\n", -5);
	// ft_printf("|%.5%|\n");
	// ft_printf("|%-0%|\n");
	// ft_printf("|%-042%|\n");
	// ft_printf("|%042%|\n");
	// ft_printf("|%4.2%|\n");
	// ft_printf("|%2.4%|\n");
	// ft_printf("|%0.42%|\n");
	// ft_printf("|%.42%|\n");
  int a = 10;
  ft_printf("%p", &a);
  printf("\n");
  printf("%p\n",&a);
	return (0);
}