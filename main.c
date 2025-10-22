/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** main test
*/

#include "my.h"

int main(void)
{
    my_printf("=== BASIC TYPES ===\n");
    my_printf("Char: %c\n", 'A');
    my_printf("String: %s\n", "Epitech");
    my_printf("Pointer: %p\n", (void *)0x1234abcd);
    my_printf("Signed int: %d\n", -12345);
    my_printf("Unsigned int: %u\n", 12345U);
    my_printf("Hex lower: %x\n", 3735928559U);
    my_printf("Hex upper: %X\n", 3735928559U);
    my_printf("Octal: %o\n", 511);

    my_printf("\n=== FLAGS ===\n");
    my_printf("Plus: %+d\n", 42);
    my_printf("Space: % d\n", 42);
    my_printf("Zero padded: %05d\n", 42);
    my_printf("Left align: %-6d<\n", 42);
    my_printf("Hash (oct): %#o\n", 511);
    my_printf("Hash (hex): %#x\n", 3735928559U);

    my_printf("\n=== WIDTH & PRECISION ===\n");
    my_printf("Width 10: %10d<\n", 42);
    my_printf("Precision .5: %.5d<\n", 42);
    my_printf("Width+prec: %10.5d<\n", 42);
    my_printf("String precision: %.3s<\n", "Hello");
    my_printf("Hex precision: %#10.4x<\n", 255);

    my_printf("\n=== LENGTH MODIFIERS ===\n");
    my_printf("Short: %hd\n", (short)32000);
    my_printf("Long: %ld\n", 1234567890L);
    my_printf("Long long: %lld\n", 9223372036854775807LL);

    my_printf("\n=== MIXED ===\n");
    my_printf("Mix: %08X %5.3d %s %c\n", 48879, 7, "Epitech", '!');
    my_printf("Null string: %s\n", (char *)0);
    my_printf("Zero precision + zero value: '%.0d'\n", 0);
    my_printf("Negative width: '%*d'\n", -8, 42);

    return 0;
}
