/*
** EPITECH PROJECT, 2024
** my_strcpy
** File description:
** c'est trop chinat a chaque fois frr
*/

#include "../my.h"

char *my_strcpy(char *dest, char const *src)
{
    int j = 0;

    for (j; src[j]; j++) {
        dest[j] = src[j];
    }
    dest[j] = '\0';
    return (dest);
}
