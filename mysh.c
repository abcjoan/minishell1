/*
** EPITECH PROJECT, 2025
** B-PSU-200-MAR-2-1-minishell1-joan.augier-billault
** File description:
** Main program entry point
*/

#include "my.h"

void free_args(char **args)
{
    for (int i = 0; args[i] != NULL; i++)
        free(args[i]);
    free(args);
}

int main(int argc, char **argv, char **env)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char **args;
    int ret_val = 0;

    while (1) {
        my_printf("$> ");
        read = getline(&line, &len, stdin);
        if (read == -1)
            break;
        args = parse_command(line);
        if (args) {
            ret_val = execute_command(args, env);
            free_args(args);
        }
    }
    free(line);
    return ret_val;
}
