/*
** EPITECH PROJECT, 2025
** B-PSU-200-MAR-2-1-minishell1-joan.augier-billault
** File description:
** Command execution functions
*/

#include "my.h"

static int handle_command_not_found(char **args)
{
    if (args[0][0] != '/' && args[0][0] != '.')
        my_printf("%s: Command not found.\n", args[0]);
    return 1;
}

static int launch_process(char *cmd_path, char **args, char **env)
{
    pid_t pid = fork();

    if (pid == 0) {
        execute_child_process(cmd_path, args, env);
    } else if (pid > 0) {
        return execute_parent_process(pid, cmd_path);
    }
    perror("fork");
    free(cmd_path);
    return 1;
}

int execute_command(char **args, char **env)
{
    char *cmd_path;

    if (!args || !args[0])
        return 0;
    if (handle_builtin(args, env))
        return 0;
    cmd_path = get_command_path(args[0], env);
    if (!cmd_path)
        return handle_command_not_found(args);
    return launch_process(cmd_path, args, env);
}
