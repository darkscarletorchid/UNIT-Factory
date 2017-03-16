#include "ft_printf.h"

void	h_flag2(t_printf *p, va_list ap)
{
	int					len;
	unsigned short int	nb;
	int zero;
	int i;

	nb = (unsigned short)va_arg(ap, int);
	zero = 0;
	len = unsigned_nblen(nb, 10);
	if (len < p->precision)
		zero = p->precision - len;
	if (p->minus != 1)
		print_spaces(p, len + zero);
	i = -1;
	while (++i < zero)
		c_putchar('0');
	c_putnbr(nb);
	if (p->minus == 1)
		print_spaces(p, len + zero);
}

void	hh_flag2(t_printf *p, va_list ap)
{
	int			len;
	unsigned char	nb;
	int zero;
	int i;

	nb = (unsigned char)va_arg(ap, int);
	zero = 0;
	len = unsigned_nblen(nb, 10);
	if (len < p->precision)
		zero = p->precision - len;
	if (p->minus != 1)
		print_spaces(p, len + zero);
	i = -1;
	while (++i < zero)
		c_putchar('0');
	c_putnbr(nb);
	if (p->minus == 1)
		print_spaces(p, len + zero);
}

void	ll_flag2(t_printf *p, va_list ap)
{
	int					len;
	unsigned long long	nb;
	int zero;
	int i;

	nb = va_arg(ap, unsigned long long);
	zero = 0;
	len = unsigned_nblen(nb, 10);
	if (len < p->precision)
		zero = p->precision - len;
	if (p->minus != 1)
		print_spaces(p, len + zero);
	i = -1;
	while (++i < zero)
		c_putchar('0');
	c_putnbr(nb);
	if (p->minus == 1)
		print_spaces(p, len + zero);
}

void	z_flag2(t_printf *p, va_list ap)
{
	int		len;
	size_t	nb;
	int zero;
	int i;

	nb = va_arg(ap, size_t);
	zero = 0;
	len = unsigned_nblen(nb, 10);
	if (len < p->precision)
		zero = p->precision - len;
	if (p->minus != 1)
		print_spaces(p, len + zero);
	i = -1;
	while (++i < zero)
		c_putchar('0');
	c_putnbr(nb);
	if (p->minus == 1)
		print_spaces(p, len + zero);
}

void	j_flag2(t_printf *p, va_list ap)
{
	int			len;
	intmax_t	nb;
	int zero;
	int i;

	nb = va_arg(ap, intmax_t);
	zero = 0;
	len = unsigned_nblen(nb, 10);
	if (len < p->precision)
		zero = p->precision - len;
	if (p->minus != 1)
		print_spaces(p, len + zero);
	i = -1;
	while (++i < zero)
		c_putchar('0');
	c_putnbr(nb);
	if (p->minus == 1)
		print_spaces(p, len + zero);
}
