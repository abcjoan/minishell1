/*
** EPITECH PROJECT, 2025
** B-PSU-200-MAR-2-1-minishell1-joan.augier-billault
** File description:
** Path handling functions
*/

#include "my.h"

char *try_path_directory(char *dir, char *command)
{
    char *slash = str_concat(dir, "/");
    char *full_path;

    if (!slash)
        return NULL;
    full_path = str_concat(slash, command);
    free(slash);
    if (!full_path)
        return NULL;
    if (access(full_path, X_OK) == 0)
        return full_path;
    free(full_path);
    return NULL;
}

char *init_path_search(char *command, char **env, char **path_ptr)
{
    char *path = get_path_from_env(env);
    char *path_copy;

    if (!path)
        return NULL;
    path_copy = my_strdup(path);
    if (!path_copy) {
        free(path);
        return NULL;
    }
    *path_ptr = path;
    return path_copy;
}

char *path_loop(char *command, char **env)
{
    char *path;
    char *token;
    char *path_copy;
    char *full_path;
    char *saveptr;
}

static char *search_in_path_dirs(char *path_copy, char *command, char *path)
{
    char *token;
    char *full_path;
    char *saveptr;

    token = strtok_r(path_copy, ":", &saveptr);
    while (token != NULL) {
        full_path = try_path_directory(token, command);
        if (full_path) {
            free(path);
            free(path_copy);
            return full_path;
        }
        token = strtok_r(NULL, ":", &saveptr);
    }
    return NULL;
}

char *find_path(char *command, char **env)
{
    char *path;
    char *path_copy;
    char *full_path;

    path_copy = init_path_search(command, env, &path);
    if (!path_copy)
        return NULL;
    full_path = search_in_path_dirs(path_copy, command, path);
    if (full_path)
        return full_path;
    free(path);
    free(path_copy);
    return NULL;
}

char *get_command_path(char *cmd, char **env)
{
    if (cmd[0] == '/' || cmd[0] == '.') {
        if (access(cmd, X_OK) == 0)
            return my_strdup(cmd);
        my_printf("%s: Permission denied or not found.\n", cmd);
        return NULL;
    }
    return find_path(cmd, env);
}
