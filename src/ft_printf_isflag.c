#include "../include/printf.h"

int	ft_printf_isflag(int c)
{
	if (c == '*' || c == '.' || c == '-')
		return (1);
	else
		return (0);
}
