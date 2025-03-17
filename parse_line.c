/*
** EPITECH PROJECT, 2025
** B-PSU-200-MAR-2-1-minishell1-joan.augier-billault
** File description:
** parse_line
*/
#include "my.h"

char **parse_command(char *line)
{
    char *token;
    char **args = malloc(sizeof(char *) * 100);
    int i = 0;

    if (!args)
        return NULL;
    token = strtok(line, " \n\t");
    while (token != NULL && i < 99) {
        args[i] = my_strdup(token);
        i = i + 1;
        token = strtok(NULL, " \n\t");
    }
    args[i] = NULL;
    return args;
}
