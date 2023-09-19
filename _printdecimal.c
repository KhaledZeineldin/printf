#include "main.h"

/**
 * print_decimal prints integer to stdout
 * @n: integer to print
 *
 * Returns void
 */

int print_decimal(int n) {
char buffer[12];
int i = 0;
int digitcount = 0;
    if (n == 0) {
        _putchar('0');
        return 1;
    }

    if (n < 0) {
        _putchar('-');
        n = -n;
    }

    while (n > 0) {
        buffer[i++] = '0' + n % 10;
        n /= 10;
        digitcount++;
    }

    while (i > 0) {
        _putchar(buffer[--i]); 
    }
    return digitcount;

}
