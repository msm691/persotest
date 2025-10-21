/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** put_nbr implementation
*/
#include "my.h"

static int print_rec(long n)
{
    int cnt;

    cnt = 0;
    if (n > 9)
        cnt += print_rec(n / 10);
    cnt += my_putchar((char)('0' + (n % 10)));
    return cnt;
}

int my_put_nbr(int n)
{
    long v;

    v = n;
    if (v < 0) {
        my_putchar('-');
        v = -v;
        return 1 + print_rec(v);
    }
    return print_rec(v);
}
