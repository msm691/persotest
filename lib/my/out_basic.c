/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** %c %s and %%
*/
#include "my.h"

int out_char(fmt_t *f, va_list *ap)
{
    char c;
    int w;
    int out;

    c = (char)va_arg(*ap, int);
    w = (f->width > 1) ? f->width - 1 : 0;
    out = 0;
    if (!f->flag_minus)
        out += pad(w, ' ');
    out += my_putchar(c);
    if (f->flag_minus)
        out += pad(w, ' ');
    return out;
}

int out_str(fmt_t *f, va_list *ap)
{
    const char *s;
    int len;
    int use;
    int out;

    s = va_arg(*ap, const char *);
    if (s == 0)
        s = "(null)";
    len = 0;
    while (s[len] != '\0')
        len += 1;
    use = (f->precision >= 0 && f->precision < len) ? f->precision : len;
    out = 0;
    if (!f->flag_minus)
        out += pad((f->width > use) ? f->width - use : 0, ' ');
    out += my_putstrn(s, use);
    if (f->flag_minus)
        out += pad((f->width > use) ? f->width - use : 0, ' ');
    return out;
}
