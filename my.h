/*
** EPITECH PROJECT, 2025
** B-PSU-200-MAR-2-1-minishell1-joan.augier-billault
** File description:
** my
*/

/*
** EPITECH PROJECT, 2025
** B-PSU-200-MAR-2-1-minishell1-joan.augier-billault
** File description:
** Header file for minishell1
*/

#ifndef MY_H_
    #define MY_H_

    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <sys/wait.h>
    #include <string.h>
    #include <signal.h>
    #include <stdarg.h>

/* Environment functions */
char *get_path_from_env(char **env);
char *get_env_var(char **env, const char *name);

/* Path handling */
char *try_path_directory(char *dir, char *command);
char *find_path(char *command, char **env);
char *get_command_path(char *cmd, char **env);

/* Built-in commands */
int handle_cd(char **args, char **env);
int handle_builtin(char **args, char **env);

/* Command execution */
int execute_command(char **args, char **env);
void execute_child_process(char *cmd_path, char **args, char **env);
int execute_parent_process(pid_t pid, char *cmd_path);

/* Command parsing */
char **parse_command(char *line);
void free_args(char **args);

/* String utilities */
int my_printf(char const *format, ...);
int my_strcmp(char const *s1, char const *s2);
int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(const char *src);
int my_strncmp(char const *s1, char const *s2, int n);
char *str_concat(const char *s1, const char *s2);

#endif
