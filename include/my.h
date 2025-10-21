/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** Public prototypes and fmt state
*/
#ifndef MY_H_
    #define MY_H_

    #include <stdarg.h>
    #include <stddef.h>
    #include <stdint.h>

    typedef struct {
        int flag_plus;
        int flag_minus;
        int flag_zero;
        int flag_space;
        int flag_hash;
        int width;
        int precision;
        char len1;
        char len2;
        char spec;
    } fmt_t;

    int my_printf(const char *fmt, ...);

    int vmy_printf(const char *fmt, va_list *ap);
    int parse_conv(const char *s, int i, fmt_t *f, va_list *ap);
    int dispatch(fmt_t *f, va_list *ap);

    int my_putchar(char c);
    int my_putstrn(const char *s, int n);
    int pad(int n, char c);
    int put_prefix(fmt_t *f, int negative, int base, int uppercase);

    int out_char(fmt_t *f, va_list *ap);
    int out_str(fmt_t *f, va_list *ap);
    int out_signed(fmt_t *f, va_list *ap);
    int out_unsigned(fmt_t *f, va_list *ap, int base, int uppercase);
    int out_ptr(fmt_t *f, va_list *ap);
#endif
