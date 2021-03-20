#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"

int main()
{
	unsigned int u;
	u = 0;

	ft_printf("-->|%-4.*u|<--\n", 0, u);
	printf("-->|%-4.*u|<--\n", 0, u);
	ft_printf("-->|%-4.*u|<--\n", 0, u);
	printf("-->|%-4.*u|<--\n", 0, u);
	return (0);
}
