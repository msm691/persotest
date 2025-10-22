/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** printf
*/

#include "my.h"

int my_printf(const char *fmt, ...)
{
    va_list ap;
    int out;

    va_start(ap, fmt);
    out = vmy_printf(fmt, &ap);
    va_end(ap);
    return out;
}
