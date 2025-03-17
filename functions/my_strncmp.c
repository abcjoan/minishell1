/*
** EPITECH PROJECT, 2024
** my_strcmp
** File description:
** compare 2 strings
*/
#include "../my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    while (n > 0 && *s1 != '\0' && *s2 != '\0') {
        if (*s1 != *s2) {
            return (unsigned char)*s1 - (unsigned char)*s2;
        }
        s1++;
        s2++;
        n--;
        }
    if (n == 0) {
        return 0;
    }
    return (unsigned char)*s1 - (unsigned char)*s2;
}
