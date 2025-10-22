/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** putchar
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
