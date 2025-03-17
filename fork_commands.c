/*
** EPITECH PROJECT, 2025
** B-PSU-200-MAR-2-1-minishell1-joan.augier-billault
** File description:
** fork_commands
*/
#include "my.h"

void execute_child_process(char *cmd_path, char **args, char **env)
{
    if (execve(cmd_path, args, env) == -1) {
        perror("execve");
        free(cmd_path);
        exit(1);
    }
}

int execute_parent_process(pid_t pid, char *cmd_path)
{
    int status;

    waitpid(pid, &status, 0);
    free(cmd_path);
    if (WIFSIGNALED(status))
        return 128 + WTERMSIG(status);
    return WEXITSTATUS(status);
}
