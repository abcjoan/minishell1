/*
** EPITECH PROJECT, 2024
** strdup
** File description:
** allocate memory
*/
#include "../my.h"


char *my_strdup(const char *src)
{
    size_t i = 0;
    char *dest;

    dest = (char *)malloc(sizeof(char) * (my_strlen(src) + 1));
    if (dest == NULL) {
        return NULL;
    }
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
