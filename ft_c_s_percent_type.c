#include "ft_printf.h"

void	ft_c_type(va_list ap)
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

void	ft_s_type(va_list ap)
{
	char *type;
	int gap;
	int argument_len;

	type = va_arg(ap, char*);
	if (type == NULL)
		type = "(null)";
	argument_len = ft_strlen(type); //가변인자의 길이
	// if (g_flag.precision < 0)
	// 	g_flag.precision = argument_len; // precision의 값이 음수면 무시하기 위해.
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

//precision의 값은 무시.
  // flag_minus가 있다면
  //  %출력후 공백
    // flag_minus가 없으면
    //   공백 출력후 %
    // flag_zero가 있으면 (첫 숫자가 0이면?)
    //   0출력후 %
    // flag_zero가 없으면
    // .은 무시 그냥 %출력
    // 다른 문자열도 무시
  //min_width의 값이 없으면
    //% 의 값만 나온다.
  //min_width의 값이 있다면
void  ft_percent_type(void)
{
  int count;

  count = g_flag.min_width;
  if (g_flag.flag_minus == 1) // flag가 -일때
  {
    ft_putchar('%');
    while (count-- > 0)
      ft_putchar(' ');
  }
  else if (g_flag.flag_minus == 0 && g_flag.flag_zero == 0)
  {
    while (count-- > 0)
      ft_putchar(' ');
    ft_putchar('%');
  }
  else if (g_flag.flag_zero == 1) // flag가 0일때,
  {
    while (count-- > 0)
      ft_putchar('0');
    ft_putchar('%');
  }
  else
    ft_putchar('%');
}
