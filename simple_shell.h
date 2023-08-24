#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char **argv, char **env);
char **tokenize_command(char *command);
void execute_command(char **tokens, char **env);
void search_and_execute(char **tokens, char **env);
char *build_full_path(char *dir, char *command);
void execute(char *command, char **env);
char **handle_paths(void);
void noninteractive_mode(char **env);
int is_empty_or_whitespace(const char *str);

#endif
