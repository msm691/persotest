/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** %p conversion
*/
#include "my.h"

static int utoa16(char *buf, unsigned long long v)
{
    const char *d = "0123456789abcdef";
    int n;
    int i;

    n = 0;
    if (v == 0)
        buf[n++] = '0';
    while (v != 0) {
        buf[n++] = d[v % 16];
        v /= 16;
    }
    i = 0;
    while (i < n / 2) {
        char t = buf[i];
        buf[i] = buf[n - 1 - i];
        buf[n - 1 - i] = t;
        i += 1;
    }
    return n;
}

int out_ptr(fmt_t *f, va_list *ap)
{
    unsigned long long v;
    char buf[64];
    int len;
    int w;
    int out;
    int prec;

    v = (unsigned long long)(uintptr_t)va_arg(*ap, void *);
    len = utoa16(buf, v);
    if (f->precision == 0 && v == 0)
        len = 0;
    prec = (f->precision > len) ? f->precision - len : 0;
    w = f->width - 2 - prec - len;
    out = 0;
    if (!f->flag_minus && !(f->flag_zero && f->precision < 0))
        out += pad((w > 0) ? w : 0, ' ');
    out += my_putstrn("0x", 2);
    if (!f->flag_minus && f->flag_zero && f->precision < 0)
        out += pad((w > 0) ? w : 0, '0');
    out += pad(prec, '0');
    out += my_putstrn(buf, len);
    if (f->flag_minus)
        out += pad((w > 0) ? w : 0, ' ');
    return out;
}
