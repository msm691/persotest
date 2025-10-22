/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** put_nbr
*/

#include "my.h"

int my_put_nbr(int nombre)
{
    if (nombre < 0) {
        my_putchar('-');
        nombre = -nombre;
    }
    if (nombre > 9) {
        my_put_nbr(nombre / 10);
    }
    my_putchar((nombre % 10) + '0');
    return 0;
}