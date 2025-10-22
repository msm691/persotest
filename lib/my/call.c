/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** Call
*/
#include "my.h"

int call(char spec, va_list *ap)
{
    if (spec == 'c')
        return my_putchar((char)va_arg(*ap, int));
    if (spec == 's')
        return my_putstr(va_arg(*ap, const char *));
    if (spec == 'd' || spec == 'i')
        return my_put_nbr(va_arg(*ap, int));
    return my_putchar(spec);
}
