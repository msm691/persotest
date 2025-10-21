/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** Dispatch specifiers
*/
#include "my.h"

int dispatch(fmt_t *f, va_list *ap)
{
    if (f->spec == 'c')
        return out_char(f, ap);
    if (f->spec == 's')
        return out_str(f, ap);
    if (f->spec == 'd' || f->spec == 'i')
        return out_signed(f, ap);
    if (f->spec == 'u')
        return out_unsigned(f, ap, 10, 0);
    if (f->spec == 'o')
        return out_unsigned(f, ap, 8, 0);
    if (f->spec == 'x')
        return out_unsigned(f, ap, 16, 0);
    if (f->spec == 'X')
        return out_unsigned(f, ap, 16, 1);
    if (f->spec == 'p')
        return out_ptr(f, ap);
    return my_putchar('%');
}
