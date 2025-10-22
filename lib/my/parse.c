/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** Parser
*/

#include "my.h"

static int is_flag(char c)
{
    if (c == '-' || c == '+' || c == '0' || c == ' ' || c == '#')
        return 1;
    return 0;
}

static int rd_int(const char *s, int i, int *v)
{
    int k;
    int acc;

    k = i;
    acc = 0;
    while (s[k] >= '0' && s[k] <= '9') {
        acc = acc * 10 + (s[k] - '0');
        k += 1;
    }
    *v = acc;
    return k - i;
}

int parse_conv(const char *s, int i, fmt_t *f, va_list *ap)
{
    int k;

    (void)ap;
    f->flag_plus = 0; f->flag_minus = 0; f->flag_zero = 0;
    f->flag_space = 0; f->flag_hash = 0;
    f->width = 0; f->precision = -1; f->len1 = 0; f->len2 = 0;
    k = i;

    while (is_flag(s[k])) {
        f->flag_minus |= (s[k] == '-');
        f->flag_plus  |= (s[k] == '+');
        f->flag_zero  |= (s[k] == '0');
        f->flag_space |= (s[k] == ' ');
        f->flag_hash  |= (s[k] == '#');
        k += 1;
    }
    if (s[k] == '*') {
        f->width = va_arg(*ap, int);
        if (f->width < 0) { f->flag_minus = 1; f->width = -f->width; }
        k += 1;
    } else {
        k += rd_int(s, k, &f->width);
    }
    if (s[k] == '.') {
        int n;

        f->precision = 0;
        k += 1;
        if (s[k] == '*') {
            n = va_arg(*ap, int);
            f->precision = (n < 0) ? -1 : n;
            k += 1;
        } else {
            k += rd_int(s, k, &f->precision);
        }
    }
    if (s[k] == 'h' || s[k] == 'l' || s[k] == 'j'
        || s[k] == 'z' || s[k] == 't' || s[k] == 'L') {
        f->len1 = s[k];
        k += 1;
        if ((f->len1 == 'h' && s[k] == 'h') || (f->len1 == 'l' && s[k] == 'l')) {
            f->len2 = s[k];
            k += 1;
        }
    }
    f->spec = s[k];
    return k - i + 1;
}
