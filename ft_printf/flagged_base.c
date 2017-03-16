#include "ft_printf.h"

void	h_flag3(t_printf *p, va_list ap, int base)
{
	int					len;
	unsigned short int	nb;
	char				*s;
	int zero;
	int i;

	nb = (unsigned short)va_arg(ap, int);
	zero = 0;
	s = ft_itoa_base(nb, base);
	len = (int) ft_strlen(s);
	if (len < p->precision)
		zero = p->precision - len;
	if (nb != 0 && p->sharp == 2)
		len += 2;
	if (p->minus != 1)
		print_spaces(p, len + zero);
	if (nb != 0 && p->sharp == 2) {
		if (p->convers == 'x') {
			ft_lowercase(s);
			c_putstr("0x");
		} else
			c_putstr("0X");
	}
	i = -1;
	while (++i < zero)
		c_putchar('0');
	c_putstr(s);
	if (p->minus == 1)
		print_spaces(p, len + zero);
}

void	hh_flag3(t_printf *p, va_list ap, int base)
{
	int			len;
	unsigned char	nb;
	char 			*s;
	int 	zero;
	int 	i;

	nb = (unsigned char)va_arg(ap, int);
	zero = 0;
	s = ft_itoa_base(nb, base);
	len = (int) ft_strlen(s);
	if (len < p->precision)
		zero = p->precision - len;
	if (nb != 0 && p->sharp == 2)
		len += 2;
	if (p->minus != 1)
		print_spaces(p, len + zero);
	if (nb != 0 && p->sharp == 2) {
		if (p->convers == 'x') {
			ft_lowercase(s);
			c_putstr("0x");
		} else
			c_putstr("0X");
	}
	i = -1;
	while (++i < zero)
		c_putchar('0');
	c_putstr(s);
	if (p->minus == 1)
		print_spaces(p, len + zero);
}

void	l_flag3(t_printf *p, va_list ap, int base)
{
	int				len;
	unsigned long	nb;
	char			*s;
	int i;
	int zero;

	nb = va_arg(ap, unsigned long );
	zero = 0;
	s = ft_itoa_base(nb, base);
	len = (int) ft_strlen(s);
	if (len < p->precision)
		zero = p->precision - len;
	if (nb != 0 && p->sharp == 2)
		len += 2;
	if (p->minus != 1)
		print_spaces(p, len + zero);
	if (nb != 0 && p->sharp == 2) {
		if (p->convers == 'x') {
			ft_lowercase(s);
			c_putstr("0x");
		} else
			c_putstr("0X");
	}
	i = -1;
	while (++i < zero)
		c_putchar('0');
	c_putstr(s);
	if (p->minus == 1)
		print_spaces(p, len + zero);
}

void	ll_flag3(t_printf *p, va_list ap, int base)
{
	int					len;
	unsigned long long	nb;
	char				*s;
	int i;
	int zero;

	nb = va_arg(ap, unsigned long long);
	zero = 0;
	s = ft_itoa_base(nb, base);
	len = (int) ft_strlen(s);
	if (len < p->precision)
		zero = p->precision - len;
	if (nb != 0 && p->sharp == 2)
		len += 2;
	if (p->minus != 1)
		print_spaces(p, len + zero);
	if (nb != 0 && p->sharp == 2) {
		if (p->convers == 'x') {
			ft_lowercase(s);
			c_putstr("0x");
		} else
			c_putstr("0X");
	}
	i = -1;
	while (++i < zero)
		c_putchar('0');
	c_putstr(s);
	if (p->minus == 1)
		print_spaces(p, len + zero);
}

void	z_flag3(t_printf *p, va_list ap, int base)
{
	int		len;
	size_t	nb;
	char	*s;
	int i;
	int zero;

	nb = va_arg(ap, size_t);
	zero = 0;
	s = ft_itoa_base(nb, base);
	len = (int) ft_strlen(s);
	if (len < p->precision)
		zero = p->precision - len;
	if (nb != 0 && p->sharp == 2)
		len += 2;
	if (p->minus != 1)
		print_spaces(p, len + zero);
	if (nb != 0 && p->sharp == 2) {
		if (p->convers == 'x') {
			ft_lowercase(s);
			c_putstr("0x");
		} else
			c_putstr("0X");
	}
	i = -1;
	while (++i < zero)
		c_putchar('0');
	c_putstr(s);
	if (p->minus == 1)
		print_spaces(p, len + zero);
}

void	j_flag3(t_printf *p, va_list ap, int base)
{
	int			len;
	intmax_t	nb;
	char		*s;
	int i;
	int zero;

	nb = va_arg(ap, intmax_t);
	zero = 0;
	s = ft_itoa_base(nb, base);
	len = (int) ft_strlen(s);
	if (len < p->precision)
		zero = p->precision - len;
	if (nb != 0 && p->sharp == 2)
		len += 2;
	if (p->minus != 1)
		print_spaces(p, len + zero);
	if (nb != 0 && p->sharp == 2) {
		if (p->convers == 'x') {
			ft_lowercase(s);
			c_putstr("0x");
		} else
			c_putstr("0X");
	}
	i = -1;
	while (++i < zero)
		c_putchar('0');
	c_putstr(s);
	if (p->minus == 1)
		print_spaces(p, len + zero);
}