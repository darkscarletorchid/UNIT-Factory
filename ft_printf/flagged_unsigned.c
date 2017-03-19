#include "ft_printf.h"


void 	uns_smth(t_printf  *p, unsigned long long int nb)
{
	int			len;
	int			prec;
	int 		w;
	int			i;

	len = unsigned_nblen(nb, 10);
	prec = 0;
	if (nb == 0)
		number_zero(p);
	else {
		if (p->precision >= len) {
			prec = p->precision - len;
		}
		w = p->width - prec - len;
		while (w > 0 && p->minus != 1 &&
			   (p->zero != 1 || (p->zero == 1 && p->precision > 0))) {
			c_putchar(' ');
			w--;
		}
		while (w > 0 && p->minus != 1 && p->zero == 1 && prec == 0) {
			c_putchar('0');
			w--;
		}
		i = -1;
		while (++i < prec)
			c_putchar('0');
		c_putnbr(nb);
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
void	h_flag2(t_printf *p, va_list ap)
{
	unsigned short int	nb;

	nb = (unsigned short)va_arg(ap, int);
	uns_smth(p, nb);
}

void	hh_flag2(t_printf *p, va_list ap)
{
	unsigned char	nb;

	nb = (unsigned char)va_arg(ap, int);
	uns_smth(p, nb);
}

void	ll_flag2(t_printf *p, va_list ap)
{
	unsigned long long	nb;

	nb = va_arg(ap, unsigned long long);
	uns_smth(p, nb);
}

void	z_flag2(t_printf *p, va_list ap)
{
	size_t	nb;

	nb = va_arg(ap, size_t);
	uns_smth(p, nb);
}

void	j_flag2(t_printf *p, va_list ap)
{
	intmax_t	nb;

	nb = va_arg(ap, intmax_t);
	uns_smth(p, nb);
}
