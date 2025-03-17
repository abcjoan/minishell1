/*
** EPITECH PROJECT, 2025
** B-PSU-200-MAR-2-1-minishell1-joan.augier-billault
** File description:
** Environment utility functions
*/

#include "my.h"

char *get_path_from_env(char **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        if (my_strncmp(env[i], "PATH=", 5) == 0)
            return my_strdup(env[i] + 5);
    }
    return NULL;
}

char *get_env_var(char **env, const char *name)
{
    int len = my_strlen(name);

    for (int i = 0; env[i]; i++) {
        if (my_strncmp(env[i], name, len) == 0 && env[i][len] == '=')
            return env[i] + len + 1;
    }
    return NULL;
}
