/*
** EPITECH PROJECT, 2025
** B-PSU-200-MAR-2-1-minishell1-joan.augier-billault
** File description:
** Built-in commands implementation
*/

#include "my.h"

int handle_cd(char **args, char **env)
{
    char *home;

    if (args[1] == NULL || (args[1][0] == '~' && args[1][1] == '\0')) {
        home = get_env_var(env, "HOME");
        if (home == NULL || chdir(home) != 0)
            perror("cd");
    } else if (chdir(args[1]) != 0) {
        perror("cd");
    }
    return 1;
}

int handle_builtin(char **args, char **env)
{
    if (!args || !args[0])
        return 0;
    if (my_strcmp(args[0], "exit") == 0)
        exit(0);
    if (my_strcmp(args[0], "cd") == 0)
        return handle_cd(args, env);
    return 0;
}
