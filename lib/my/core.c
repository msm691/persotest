/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** Core loop (Epitech style)
*/
#include "my.h"

static int handle_format(const char *fmt, int *i, va_list *ap)
{
    fmt_t f;
    int j;
    int out;

    j = parse_conv(fmt, *i + 1, &f, ap);
    out = 0;
    if (j > 0)
        out += dispatch(&f, ap);
    else
        out += my_putchar(fmt[*i + 1]);
    *i += 1 + j;
    return out;
}

int vmy_printf(const char *fmt, va_list *ap)
{
    int i;
    int out;

    i = 0;
    out = 0;
    while (fmt[i] != '\0') {
        if (fmt[i] == '%' && fmt[i + 1] != '\0')
            out += handle_format(fmt, &i, ap);
        else
            out += my_putchar(fmt[i]);
        i += 1;
    }
    return out;
}
