/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** Public prototypes
*/
#ifndef MY_H_
    #define MY_H_

    #include <stdarg.h>

    int my_printf(const char *fmt, ...);
    int call(char spec, va_list *ap);
    int my_putchar(char c);
    int my_putstr(const char *s);
    int my_put_nbr(int n);

#endif /* !MY_H_ */
