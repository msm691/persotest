/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** Basic writers
*/
#include <unistd.h>
#include "my.h"

int my_putchar(char c)
{
    return (int)write(1, &c, 1);
}

int my_putstrn(const char *s, int n)
{
    int i;

    i = 0;
    while (i < n) {
        write(1, &s[i], 1);
        i += 1;
    }
    return n;
}

int pad(int n, char c)
{
    int i;

    i = 0;
    while (i < n) {
        write(1, &c, 1);
        i += 1;
    }
    return n < 0 ? 0 : n;
}
