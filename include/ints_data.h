/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** Structs for formatted data
*/

#ifndef INTS_DATA_H_
    #define INTS_DATA_H_

    typedef struct {
        int neg;
        int prec;
        int w;
        int len;
        char *buf;
    } sdata_t;

    typedef struct {
        int w;
        int prec;
        int len;
        char *buf;
    } ptr_data_t;

    typedef struct {
        int base;
        int uppercase;
        int len;
        int prec;
        int w;
        unsigned long long uv;
        char *buf;
    } udata_t;

#endif
