#include "ft_printf.h"
#include <stdio.h>

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

	// printf("%7d\n", -12345);
	// ft_printf("%7d\n", -12345);
	// printf("%0*d\n", 8, -12345);
	// ft_printf("%0*d\n", 8, -12345);
	// printf("%08.7d\n", -12345);
	// ft_printf("%08.7d\n", -12345);
	printf("%-8.7d\n", -12345);
	ft_printf("%-8.7d\n", -12345);
	printf("%7d\n", 12345);
	ft_printf("%7d\n", 12345);
	printf("%-d\n", 12345);
	ft_printf("%-d\n", 12345);
	printf("%*.*d\n", -9, 7, 12345);
	ft_printf("%*.*d\n", -9, 7, 12345);
	return (0);
}
