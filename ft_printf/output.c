//
// Created by Anastasiia Trepyton on 3/15/17.
//

#include "ft_printf.h"

void	put_arg(t_printf *p, va_list ap)
{
	if (p->convers == 'd' || p->convers == 'i')
		put_d_i(p, ap);
	else if (p->convers == 'D')
		put_long_d(p, ap);
	else if (p->convers == 'o')
		put_octal(p, ap);
	else if (p->convers == 'O')
		put_long_octal(p, ap);
	else if (p->convers == 'X' || p->convers == 'x')
		put_hex(p, ap);
	else if (p->convers == 'u')
		put_unsigned_i(p, ap);
	else if (p->convers == 'U')
		put_unsigned_long_i(p, ap);
	else if (p->convers == 's')
		put_string(p, ap);
	else if (p->convers == 'c')
		put_char(p, ap);
/*-********************************************************-*/
//	else if (p.convers == 'S')
//		c_putstr(va_arg(ap, char *)); UNICODE CHARS
//	else if (p.convers == 'C')
//		c_putstr(va_arg(ap, char *)); UNICODE CHARS
//	else if (p.convers == 'p')
//		c_putstr(va_arg(ap, char *)); pointer to address
}