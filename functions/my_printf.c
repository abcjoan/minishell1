/*
** EPITECH PROJECT, 2024
** mini_printf.c
** File description:
** mini printf
*/

#include "../my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i]){
        my_putchar(str[i]);
        i++;
    }
    return 0;
}

int my_putnbr(int nb)
{
    if (nb < 0){
        nb = -nb;
        my_putchar('-');
        my_putnbr(nb);
    } else if (nb < 10){
        my_putchar(nb + 48);
    } else {
        my_putnbr(nb / 10);
        my_putnbr(nb % 10);
    }
    return 0;
}

void print_with_switch(char format, va_list args)
{
    switch (format){
    case 'd':
        my_putnbr(va_arg(args, int));
        break;
    case 's':
        my_putstr(va_arg(args, char *));
        break;
    case 'c':
        my_putchar(va_arg(args, int));
        break;
    case 'i':
        my_putnbr(va_arg(args, int));
        break;
    case '%':
        my_putchar('%');
        break;
    default:
        break;
    }
}

int my_printf(char const *format, ...)
{
    va_list args;

    va_start(args, format);
    for (int i = 0; format[i]; i++){
        if (format[i] == '%'){
            print_with_switch(format[i + 1], args);
            i++;
        } else {
            my_putchar(format[i]);
        }
    }
    va_end(args);
    return 0;
}
