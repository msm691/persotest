/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** Entry point printf-like
*/
#include "my.h"

int my_printf(const char *fmt, ...)
{
    va_list ap;
    int i;
    int out;

    va_start(ap, fmt);
    i = 0;
    out = 0;

    while (fmt[i] != '\0') {
        if (fmt[i] == '%' && fmt[i + 1] != '\0') {
            out += call(fmt[i + 1], &ap);
            i += 2;
        } else {
            out += my_putchar(fmt[i]);
            i += 1;
        }
    }
    va_end(ap);
    return out;
}
