/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** Convert int
*/

#include "my.h"

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

static int utoa_base(char *buf, unsigned long long v, int base, int up)
{
    const char *digits;
    int n;
    int i;

    digits = up ? "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                : "0123456789abcdefghijklmnopqrstuvwxyz";
    n = 0;
    if (v == 0)
        buf[n++] = '0';
    while (v != 0) {
        buf[n++] = digits[v % (unsigned)base];
        v /= (unsigned)base;
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

int out_signed(fmt_t *f, va_list *ap)
{
    long long sv;
    unsigned long long uv;
    char buf[64];
    int len;
    int prec;
    int w;
    int out;
    int neg;

    sv = get_smul(f, ap);
    neg = (sv < 0);
    uv = (neg) ? (unsigned long long)(-sv) : (unsigned long long)sv;
    len = utoa_base(buf, uv, 10, 0);
    prec = (f->precision > len) ? f->precision - len : 0;
    w = f->width - prec - len - ((neg || f->flag_plus || f->flag_space) ? 1 : 0);
    if (f->precision == 0 && uv == 0)
        len = 0;
    if (!f->flag_minus && !(f->flag_zero && f->precision < 0))
        out = pad((w > 0) ? w : 0, ' ');
    else
        out = 0;
    out += put_prefix(f, neg, 10, 0);
    if (!f->flag_minus && f->flag_zero && f->precision < 0)
        out += pad((w > 0) ? w : 0, '0');
    out += pad(prec, '0');
    out += my_putstrn(buf, len);
    if (f->flag_minus)
        out += pad((w > 0) ? w : 0, ' ');
    return out;
}

int out_unsigned(fmt_t *f, va_list *ap, int base, int uppercase)
{
    unsigned long long uv;
    char buf[64];
    int len;
    int prec;
    int add;
    int w;
    int out;

    uv = get_umul(f, ap);
    len = utoa_base(buf, uv, base, uppercase);
    if (f->precision == 0 && uv == 0)
        len = 0;
    add = 0;
    if (f->flag_hash && base == 8 && !(f->precision == 0 && uv == 0))
        add = 1;
    if (f->flag_hash && base == 16 && uv != 0)
        add = 2;
    prec = (f->precision > len) ? f->precision - len : 0;
    w = f->width - prec - len - add;
    if (!f->flag_minus && !(f->flag_zero && f->precision < 0))
        out = pad((w > 0) ? w : 0, ' ');
    else
        out = 0;
    if (f->flag_hash && base == 8 && !(f->precision == 0 && uv == 0))
        out += my_putchar('0');
    if (f->flag_hash && base == 16 && uv != 0)
        out += my_putstrn(uppercase ? "0X" : "0x", 2);
    if (!f->flag_minus && f->flag_zero && f->precision < 0)
        out += pad((w > 0) ? w : 0, '0');
    out += pad(prec, '0');
    out += my_putstrn(buf, len);
    if (f->flag_minus)
        out += pad((w > 0) ? w : 0, ' ');
    return out;
}
