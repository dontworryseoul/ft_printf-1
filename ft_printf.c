#include <unistd.h>
#include <stdarg.h>
#include <string.h>

int ft_printf(char *args, ...)
{
	va_list ap;
	int num;
	int i;

	i = 0;
	va_start(ap, args);

	if (memchr(args, %) != NULL)
	{
		if (args)
	}

	while (i < count)
	{
		num = va_arg(ap, int);
		i++;
	}
	va_end(ap);

	return (0);
}

int main()
{
	ft_printf("%s", "안녕");

	return (0);
}
