#include "ft_printf.h"

void	base_smth(t_printf *p, unsigned long long nb, int base)
{
	int		len;
	char	*s;
	int 	prec;
	int w;
	int flag;
	int 	i;

	s = ft_itoa_base(nb, base);
	len = ft_strlen(s);
	prec = 0;
	if (nb == 0)
		number_zero(p);
	else {
		flag = p->sharp == 2 ? 2 : 0;
		if (p->precision >= len)
			prec = p->precision - len;
		w = p->width - prec - len - flag;
		while (w > 0 && p->minus != 1 &&
			   (p->zero != 1 || (p->zero == 1 && p->precision > 0))) {
			c_putchar(' ');
			w--;
		}
		if (flag && p->convers == 'x')
			c_putstr("0x");
		else if (flag && p->convers == 'X')
			c_putstr("0X");
		while (w > 0 && p->minus != 1 && p->zero == 1 && prec == 0) {
			c_putchar('0');
			w--;
		}
		i = -1;
		while (++i < prec)
			c_putchar('0');
		if (p->convers == 'x')
			ft_lowercase(s);
		c_putstr(s);
		while (w > 0 && p->minus == 1) {
			c_putchar(' ');
			w--;
		}
		while (w > 0 && p->minus == 1 && p->zero == 1 && prec == 0) {
			c_putchar('0');
			w--;
		}
	}
}

void	h_flag3(t_printf *p, va_list ap, int base)
{
	unsigned short int	nb;

	nb = (unsigned short)va_arg(ap, int);
	base_smth(p, nb, base);
//	zero = 0;
//	s = ft_itoa_base(nb, base);
//	len = (int) ft_strlen(s);
//	if (len < p->precision)
//		zero = p->precision - len;
//	if (nb != 0 && p->sharp == 2)
//		len += 2;
//	if (p->minus != 1)
//		print_spaces(p, len + zero);
//	if (nb != 0 && p->sharp == 2) {
//		if (p->convers == 'x') {
//			ft_lowercase(s);
//			c_putstr("0x");
//		} else
//			c_putstr("0X");
//	}
//	i = -1;
//	while (++i < zero)
//		c_putchar('0');
//	c_putstr(s);
//	if (p->minus == 1)
//		print_spaces(p, len + zero);
}

void	hh_flag3(t_printf *p, va_list ap, int base)
{
	int			len;
	unsigned char	nb;
	char 			*s;
	int 	zero;
	int 	i;

	nb = (unsigned char)va_arg(ap, int);
	base_smth(p, nb, base);
//	zero = 0;
//	s = ft_itoa_base(nb, base);
//	len = (int) ft_strlen(s);
//	if (len < p->precision)
//		zero = p->precision - len;
//	if (nb != 0 && p->sharp == 2)
//		len += 2;
//	if (p->minus != 1)
//		print_spaces(p, len + zero);
//	if (nb != 0 && p->sharp == 2) {
//		if (p->convers == 'x') {
//			ft_lowercase(s);
//			c_putstr("0x");
//		} else
//			c_putstr("0X");
//	}
//	i = -1;
//	while (++i < zero)
//		c_putchar('0');
//	c_putstr(s);
//	if (p->minus == 1)
//		print_spaces(p, len + zero);
}

void	l_flag3(t_printf *p, va_list ap, int base)
{
	int				len;
	unsigned long	nb;
	char			*s;
	int i;
	int zero;

	nb = va_arg(ap, unsigned long );
	base_smth(p, nb, base);
//	zero = 0;
//	s = ft_itoa_base(nb, base);
//	len = (int) ft_strlen(s);
//	if (len < p->precision)
//		zero = p->precision - len;
//	if (nb != 0 && p->sharp == 2)
//		len += 2;
//	if (p->minus != 1)
//		print_spaces(p, len + zero);
//	if (nb != 0 && p->sharp == 2) {
//		if (p->convers == 'x') {
//			ft_lowercase(s);
//			c_putstr("0x");
//		} else
//			c_putstr("0X");
//	}
//	i = -1;
//	while (++i < zero)
//		c_putchar('0');
//	c_putstr(s);
//	if (p->minus == 1)
//		print_spaces(p, len + zero);
}

void	ll_flag3(t_printf *p, va_list ap, int base)
{
	int					len;
	unsigned long long	nb;
	char				*s;
	int i;
	int zero;

	nb = va_arg(ap, unsigned long long);
	base_smth(p, nb, base);
//	zero = 0;
//	s = ft_itoa_base(nb, base);
//	len = (int) ft_strlen(s);
//	if (len < p->precision)
//		zero = p->precision - len;
//	if (nb != 0 && p->sharp == 2)
//		len += 2;
//	if (p->minus != 1)
//		print_spaces(p, len + zero);
//	if (nb != 0 && p->sharp == 2) {
//		if (p->convers == 'x') {
//			ft_lowercase(s);
//			c_putstr("0x");
//		} else
//			c_putstr("0X");
//	}
//	i = -1;
//	while (++i < zero)
//		c_putchar('0');
//	c_putstr(s);
//	if (p->minus == 1)
//		print_spaces(p, len + zero);
}

void	z_flag3(t_printf *p, va_list ap, int base)
{
	int		len;
	size_t	nb;
	char	*s;
	int i;
	int zero;

	nb = va_arg(ap, size_t);
	base_smth(p, nb, base);
//	zero = 0;
//	s = ft_itoa_base(nb, base);
//	len = (int) ft_strlen(s);
//	if (len < p->precision)
//		zero = p->precision - len;
//	if (nb != 0 && p->sharp == 2)
//		len += 2;
//	if (p->minus != 1)
//		print_spaces(p, len + zero);
//	if (nb != 0 && p->sharp == 2) {
//		if (p->convers == 'x') {
//			ft_lowercase(s);
//			c_putstr("0x");
//		} else
//			c_putstr("0X");
//	}
//	i = -1;
//	while (++i < zero)
//		c_putchar('0');
//	c_putstr(s);
//	if (p->minus == 1)
//		print_spaces(p, len + zero);
}

void	j_flag3(t_printf *p, va_list ap, int base)
{
	int			len;
	intmax_t	nb;
	char		*s;
	int i;
	int zero;

	nb = va_arg(ap, intmax_t);
	base_smth(p, nb, base);
//	zero = 0;
//	s = ft_itoa_base(nb, base);
//	len = (int) ft_strlen(s);
//	if (len < p->precision)
//		zero = p->precision - len;
//	if (nb != 0 && p->sharp == 2)
//		len += 2;
//	if (p->minus != 1)
//		print_spaces(p, len + zero);
//	if (nb != 0 && p->sharp == 2) {
//		if (p->convers == 'x') {
//			ft_lowercase(s);
//			c_putstr("0x");
//		} else
//			c_putstr("0X");
//	}
//	i = -1;
//	while (++i < zero)
//		c_putchar('0');
//	c_putstr(s);
//	if (p->minus == 1)
//		print_spaces(p, len + zero);
}