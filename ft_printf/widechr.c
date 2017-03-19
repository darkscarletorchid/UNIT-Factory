//
// Created by Anastasiia Trepyton on 3/17/17.
//

#include "ft_printf.h"

void				wint_convert_c(wint_t c)
{
	if (c <= 0x7F)
		c_putchar(c);
	if (c <= 0x7FF)
	{
		c_putchar((char)(((c & 0x07c0) >> 6) + 0xc0));
		c_putchar((char)((c & 0x003F) + 0x80));
	}
	else if (c <= 0xFFFF)
	{
		c_putchar((char)(((c & 0xF000) >> 12) + 0xE0));
		c_putchar((char)(((c & 0x0Fc0) >> 6) + 0x80));
		c_putchar((char)((c & 0x003F) + 0x80));
	}
	else if (c <= 0x10FFFF)
	{
		c_putchar((char)(((c & 0x1c0000) >> 18) + 0xF0));
		c_putchar((char)(((c & 0x03F000) >> 12) + 0x80));
		c_putchar((char)(((c & 0x0Fc0) >> 6) + 0x80));
		c_putchar((char)(((c & 0x003F) + 0x80)));
	}
}

void	put_char_unicode(t_printf *p, va_list ap)
{
	wint_t c;

	c = va_arg(ap, wint_t);
	if (c != 0) {
		if (p->minus != 1)
			print_spaces(p, 1);
		wint_convert_c(c);
		if (p->minus == 1)
			print_spaces(p, 1);
	}
}