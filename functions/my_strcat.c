/*
** EPITECH PROJECT, 2024
** strncat.c
** File description:
** concatenates
*/
#include "../my.h"

char *my_strcat(char *dest, const char *src)
{
    int dest_len = my_strlen(dest);
    int i = 0;

    while (src[i]) {
        dest[dest_len + i] = src[i];
        i++;
    }
    dest[dest_len + i] = '\0';
    return dest;
}

char *str_concat(const char *s1, const char *s2)
{
    char *result = malloc(my_strlen(s1) + my_strlen(s2) + 1);

    if (!result)
        return NULL;
    my_strcpy(result, s1);
    my_strcat(result, s2);
    return result;
}
