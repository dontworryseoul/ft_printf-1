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
	argument_len = ft_strlen(type);
	if (g_flag.precision < 0)
		g_flag.precision = argument_len;
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

void  ft_percent_type(void)
{
  int count;

  count = g_flag.min_width;
  count--;
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
