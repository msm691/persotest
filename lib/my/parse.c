/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** Parse flags and modifiers (Epitech style)
*/
#include "my.h"

static void reset_fmt(fmt_t *f)
{
    f->flag_plus = 0;
    f->flag_minus = 0;
    f->flag_zero = 0;
    f->flag_space = 0;
    f->flag_hash = 0;
    f->width = 0;
    f->precision = -1;
    f->len1 = 0;
    f->len2 = 0;
}

static int read_number(const char *s, int i, int *v)
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

static int read_flags(const char *s, int i, fmt_t *f)
{
    while (s[i] == '-' || s[i] == '+' || s[i] == '0'
        || s[i] == ' ' || s[i] == '#') {
        f->flag_minus |= (s[i] == '-');
        f->flag_plus |= (s[i] == '+');
        f->flag_zero |= (s[i] == '0');
        f->flag_space |= (s[i] == ' ');
        f->flag_hash |= (s[i] == '#');
        i += 1;
    }
    return i;
}

static int read_length(const char *s, int k, fmt_t *f)
{
    if (s[k] == 'h' || s[k] == 'l' || s[k] == 'j'
        || s[k] == 'z' || s[k] == 't' || s[k] == 'L') {
        f->len1 = s[k];
        k += 1;
        if ((f->len1 == 'h' && s[k] == 'h')
            || (f->len1 == 'l' && s[k] == 'l')) {
            f->len2 = s[k];
            k += 1;
        }
    }
    return k;
}

static void handle_precision(const char *s, int *k, fmt_t *f, va_list *ap)
{
    int n;

    f->precision = 0;
    *k += 1;
    if (s[*k] == '*') {
        n = va_arg(*ap, int);
        f->precision = (n < 0) ? -1 : n;
        *k += 1;
    } else
        *k += read_number(s, *k, &f->precision);
}

int parse_conv(const char *s, int i, fmt_t *f, va_list *ap)
{
    int k;

    reset_fmt(f);
    k = read_flags(s, i, f);
    if (s[k] == '*') {
        f->width = va_arg(*ap, int);
        if (f->width < 0) {
            f->flag_minus = 1;
            f->width = -f->width;
        }
        k += 1;
    } else
        k += read_number(s, k, &f->width);
    if (s[k] == '.')
        handle_precision(s, &k, f, ap);
    k = read_length(s, k, f);
    f->spec = s[k];
    return k - i + 1;
}
