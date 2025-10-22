/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** Pointer (%p) handling (Epitech style)
*/
#include "my.h"
#include "ints_data.h"

static void reverse_buf(char *buf, int n)
{
    int i;
    char t;

    i = 0;
    while (i < n / 2) {
        t = buf[i];
        buf[i] = buf[n - 1 - i];
        buf[n - 1 - i] = t;
        i += 1;
    }
}

static int utoa16(char *buf, unsigned long long v)
{
    const char *d;
    int n;

    d = "0123456789abcdef";
    n = 0;
    if (v == 0) {
        buf[n] = '0';
        n += 1;
    }
    while (v != 0) {
        buf[n] = d[v % 16];
        n += 1;
        v /= 16;
    }
    reverse_buf(buf, n);
    return n;
}

static int print_ptr(fmt_t *f, ptr_data_t *d)
{
    int out;

    out = 0;
    if (!f->flag_minus && !(f->flag_zero && f->precision < 0))
        out += pad((d->w > 0) ? d->w : 0, ' ');
    out += my_putstrn("0x", 2);
    if (!f->flag_minus && f->flag_zero && f->precision < 0)
        out += pad((d->w > 0) ? d->w : 0, '0');
    out += pad(d->prec, '0');
    out += my_putstrn(d->buf, d->len);
    if (f->flag_minus)
        out += pad((d->w > 0) ? d->w : 0, ' ');
    return out;
}

int out_ptr(fmt_t *f, va_list *ap)
{
    unsigned long long v;
    char buf[64];
    ptr_data_t d;

    v = (unsigned long long)(uintptr_t)va_arg(*ap, void *);
    d.len = utoa16(buf, v);
    if (f->precision == 0 && v == 0)
        d.len = 0;
    d.prec = (f->precision > d.len) ? f->precision - d.len : 0;
    d.w = f->width - 2 - d.prec - d.len;
    d.buf = buf;
    return print_ptr(f, &d);
}
