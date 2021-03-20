#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"

int main()
{
	char *p;

	// p = "1230";
	p = 0;

	ft_printf("|%-16.p|\n", p);
	printf("|%-16.p|\n", p);
	ft_printf("|%-16p|\n", p);
	printf("|%-16p|\n", p);
	return (0);
}
