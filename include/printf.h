#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include "../42-sp-libft/include/libft.h"

typedef struct s_flags
{
	char			*f;
	char			*str;
	char			*spaces;
	char			print_c;
	int				s_len;
	int				just;
	int				prec;
	int				width;
	int				zero;
	int				neg;
	char			c;
}					t_flags;

char				*ft_utoa(size_t num, int base, int capitalize);
char				*ft_ptoa(uintptr_t num, int prec);
char				*ft_ctoa(char c);
int					ft_printf(const char *fmt, ...);
int					ft_printf_putchar(char c);
int					ft_printf_print(t_flags *lst);
int					ft_printf_print_p_str(t_flags *lst);
int					ft_printf_print_c(t_flags *lst);
int					ft_printf_isflag(int c);
void				ft_printf_empty_zeros(t_flags ***lst);
void				ft_printf_get_flag(char *s, va_list args, t_flags ***lst);
t_flags				*ft_printf_newflag(void);
void				to_string(const char *f, va_list args, t_flags ***lst);

#endif
