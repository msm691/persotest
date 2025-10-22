/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** Core
*/

#include "my.h"

static int is_spec(char c)
{
    if (c == 'c' || c == 's' || c == 'd' || c == 'i')
        return 1;
    if (c == 'u' || c == 'o' || c == 'x' || c == 'X')
        return 1;
    if (c == 'p' || c == '%')
        return 1;
    return 0;
}

int vmy_printf(const char *fmt, va_list *ap)
{
    int i;
    int out;

    i = 0;
    out = 0;
    while (fmt[i] != '\0') {
        if (fmt[i] == '%' && fmt[i + 1] != '\0') {
            fmt_t f;
            int j;

            j = parse_conv(fmt, i + 1, &f, ap);
            if (j > 0 && is_spec(f.spec))
                out += dispatch(&f, ap);
            else
                out += my_putchar(fmt[i + 1]);
            i += 1 + j;
        } else {
            out += my_putchar(fmt[i]);
        }
        i += 1;
    }
    return out;
}
