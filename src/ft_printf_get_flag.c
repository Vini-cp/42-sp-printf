#include "../include/printf.h"

static	int	define_just(char c, int just)
{
	if (c == '-')
		return (1);
	return (just);
}

static	int	define_prec(char c, int prec)
{
	if (c == '.')
		return (0);
	return (prec);
}

static	int	define_zero(char c, int prec, int zero)
{
	if (c == '0' && prec < 0)
		return (1);
	return (zero);
}

void	ft_printf_get_flag(char *s, va_list args, t_flags ***lst)
{
	int	i;

	i = 0;
	while (s[i])
	{
		(**lst)->just = define_just(s[i], (**lst)->just);
		(**lst)->prec = define_prec(s[i], (**lst)->prec);
		if (s[i] == '*' && (**lst)->prec >= 0)
			(**lst)->prec = va_arg(args, int);
		else if (s[i] == '*' && (**lst)->prec < 0)
			(**lst)->width = va_arg(args, int);
		if (ft_isdigit(*(s + i)))
		{
			(**lst)->zero = define_zero(s[i], (**lst)->prec, (**lst)->zero);
			if ((**lst)->prec >= 0)
				(**lst)->prec = ft_atoi((s + i));
			else
				(**lst)->width = ft_atoi((s + i));
			while (ft_isdigit(s[i]))
				i++;
			i--;
		}
		i++;
	}
}
