/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** Test main for my_printf
*/
#include "include/my.h"

int main(void)
{
    int n = 42;
    int *ptr = &n;

    my_printf("=== BASIC TESTS ===\n");
    my_printf("Char: %c\n", 'A');
    my_printf("String: %s\n", "Hello");
    my_printf("Signed int: %d\n", -12345);
    my_printf("Unsigned: %u\n", 12345);
    my_printf("Octal: %o\n", 255);
    my_printf("Hex lower: %x\n", 255);
    my_printf("Hex upper: %X\n", 255);
    my_printf("Pointer: %p\n", ptr);
    my_printf("Percent: %%\n");

    my_printf("\n=== FLAGS ===\n");
    my_printf("Plus: %+d %+d\n", 42, -42);
    my_printf("Space: % d % d\n", 42, -42);
    my_printf("Zero pad: %010d\n", 42);
    my_printf("Left align: %-10d!\n", 42);
    my_printf("Hash oct: %#o\n", 64);
    my_printf("Hash hex: %#x %#X\n", 255, 255);

    my_printf("\n=== WIDTH & PRECISION ===\n");
    my_printf("Width 8: '%8d'\n", 42);
    my_printf("Width left: '%-8d'\n", 42);
    my_printf("Precision .5: '%.5d'\n", 42);
    my_printf("Width+prec: '%8.5d'\n", 42);
    my_printf("String prec: '%.3s'\n", "HelloWorld");

    my_printf("\n=== LENGTH MODIFIERS ===\n");
    my_printf("short: %hd\n", (short)32000);
    my_printf("long: %ld\n", (long)1234567890);
    my_printf("long long: %lld\n", (long long)123456789012345);

    return 0;
}
