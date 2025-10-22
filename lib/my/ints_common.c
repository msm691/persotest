/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** Integer handling (Epitech style, 0 warning Banana)
*/
#include "my.h"
#include "ints_data.h"

static unsigned long long get_umul(fmt_t *f, va_list *ap)
{
    if (f->len1 == 'l' && f->len2 == 'l')
        return (unsigned long long)va_arg(*ap, unsigned long long);
    if (f->len1 == 'l')
        return (unsigned long long)va_arg(*ap, unsigned long);
    if (f->len1 == 'h' && f->len2 == 'h')
        return (unsigned long long)(unsigned char)va_arg(*ap, unsigned int);
    if (f->len1 == 'h')
        return (unsigned long long)(unsigned short)va_arg(*ap, unsigned int);
    if (f->len1 == 'j')
        return (unsigned long long)va_arg(*ap, uintmax_t);
    if (f->len1 == 'z')
        return (unsigned long long)va_arg(*ap, size_t);
    if (f->len1 == 't')
        return (unsigned long long)va_arg(*ap, ptrdiff_t);
    return (unsigned long long)va_arg(*ap, unsigned int);
}

static long long get_smul(fmt_t *f, va_list *ap)
{
    if (f->len1 == 'l' && f->len2 == 'l')
        return (long long)va_arg(*ap, long long);
    if (f->len1 == 'l')
        return (long)va_arg(*ap, long);
    if (f->len1 == 'h' && f->len2 == 'h')
        return (long long)(signed char)va_arg(*ap, int);
    if (f->len1 == 'h')
        return (long long)(short)va_arg(*ap, int);
    if (f->len1 == 'j')
        return (long long)va_arg(*ap, intmax_t);
    if (f->len1 == 't')
        return (long long)va_arg(*ap, ptrdiff_t);
    return (long long)va_arg(*ap, int);
}

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

static int utoa_base(char *buf, unsigned long long v, int base, int up)
{
    const char *digits;
    int n;

    digits = up ? "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        : "0123456789abcdefghijklmnopqrstuvwxyz";
    n = 0;
    if (v == 0) {
        buf[n] = '0';
        n += 1;
    }
    while (v != 0) {
        buf[n] = digits[v % (unsigned)base];
        n += 1;
        v /= (unsigned)base;
    }
    reverse_buf(buf, n);
    return n;
}

int put_prefix(fmt_t *f, int negative, int base, int uppercase)
{
    int out;

    out = 0;
    if (negative)
        return out + my_putchar('-');
    if (f->flag_plus)
        return out + my_putchar('+');
    if (f->flag_space)
        return out + my_putchar(' ');
    if (f->flag_hash && base == 8)
        return out + my_putchar('0');
    if (f->flag_hash && base == 16)
        return out + my_putstrn(uppercase ? "0X" : "0x", 2);
    return out;
}

static int print_signed(fmt_t *f, sdata_t *d)
{
    int out;

    out = 0;
    if (!f->flag_minus && !(f->flag_zero && f->precision < 0))
        out += pad((d->w > 0) ? d->w : 0, ' ');
    out += put_prefix(f, d->neg, 10, 0);
    if (!f->flag_minus && f->flag_zero && f->precision < 0)
        out += pad((d->w > 0) ? d->w : 0, '0');
    out += pad(d->prec, '0');
    out += my_putstrn(d->buf, d->len);
    if (f->flag_minus)
        out += pad((d->w > 0) ? d->w : 0, ' ');
    return out;
}

int out_signed(fmt_t *f, va_list *ap)
{
    long long sv;
    unsigned long long uv;
    char buf[64];
    sdata_t d;

    sv = get_smul(f, ap);
    d.neg = (sv < 0);
    uv = (d.neg) ? (unsigned long long)(-sv) : (unsigned long long)sv;
    d.len = utoa_base(buf, uv, 10, 0);
    d.prec = (f->precision > d.len) ? f->precision - d.len : 0;
    d.w = f->width - d.prec - d.len
        - ((d.neg || f->flag_plus || f->flag_space) ? 1 : 0);
    d.buf = buf;
    if (f->precision == 0 && uv == 0)
        d.len = 0;
    return print_signed(f, &d);
}

static int print_unsigned(fmt_t *f, udata_t *d)
{
    int out;

    out = 0;
    if (!f->flag_minus && !(f->flag_zero && f->precision < 0))
        out += pad((d->w > 0) ? d->w : 0, ' ');
    if (f->flag_hash && d->base == 8 && !(f->precision == 0 && d->uv == 0))
        out += my_putchar('0');
    if (f->flag_hash && d->base == 16 && d->uv != 0)
        out += my_putstrn(d->uppercase ? "0X" : "0x", 2);
    if (!f->flag_minus && f->flag_zero && f->precision < 0)
        out += pad((d->w > 0) ? d->w : 0, '0');
    out += pad(d->prec, '0');
    out += my_putstrn(d->buf, d->len);
    if (f->flag_minus)
        out += pad((d->w > 0) ? d->w : 0, ' ');
    return out;
}

int out_unsigned(fmt_t *f, va_list *ap, int base, int uppercase)
{
    udata_t d;

    d.uv = get_umul(f, ap);
    d.buf = (char[64]){0};
    d.len = utoa_base(d.buf, d.uv, base, uppercase);
    if (f->precision == 0 && d.uv == 0)
        d.len = 0;
    d.base = base;
    d.uppercase = uppercase;
    if (f->flag_hash && base == 8 && !(f->precision == 0 && d.uv == 0))
        d.w = 1;
    else if (f->flag_hash && base == 16 && d.uv != 0)
        d.w = 2;
    else
        d.w = 0;
    d.prec = (f->precision > d.len) ? f->precision - d.len : 0;
    d.w = f->width - d.prec - d.len - d.w;
    return print_unsigned(f, &d);
}
