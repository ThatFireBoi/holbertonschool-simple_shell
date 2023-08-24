#include "simple_shell.h"

/**
 * tokenize_command - Tokenize the command string
 *
 * @command: The command to tokenize
 *
 * Return: An array of tokens
 */

void execute_command(char **tokens, char **env);

char **tokenize_command(char *command)
{
	char **tokens = NULL;
	char *token = NULL;
	int token_count = 0;

	token = strtok(command, " \n");
	if (token == NULL)
		return NULL;

	while (token != NULL)
	{
		tokens = realloc(tokens, sizeof(char *) * (token_count + 2));
		if (tokens == NULL)
		{
			perror("realloc");
			return NULL;
		}
		tokens[token_count] = token;
		token_count++;
		tokens[token_count] = NULL;
		token = strtok(NULL, " \n");
	}
	return tokens;
}

/**
 * execute_command - Execute a command using fork and execve
 *
 * @tokens: The array of tokens representing the command
 *
 * @env: The environment variables
 */

void execute_command(char **tokens, char **env)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
		free(tokens);
		return;
	}
	if (child_pid == 0) /* Child process */
	{
		if (tokens[0][0] == '/')
		{
			if (execve(tokens[0], tokens, env) == -1)
			{
				perror("execve error");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			search_and_execute(tokens, env);
		}
	}
	else /* Parent process */
	{
		waitpid(child_pid, NULL, 0);
	}
}

/**
 * search_and_execute - Search for the command in PATH directories and execute
 *
 * @tokens: The array of tokens representing the command
 *
 * @env: The environment variables
 */

void search_and_execute(char **tokens, char **env)
{
	char **paths = handle_paths();
	int i;

	for (i = 0; paths[i] != NULL; i++)
	{
		char *full_path = build_full_path(paths[i], tokens[0]);

		if (access(full_path, X_OK) == 0)
		{
			if (execve(full_path, tokens, env) == -1)
			{
				perror("execve error");
				exit(EXIT_FAILURE);
			}
			free(full_path);
			return;
		}
		free(full_path);
	}
	fprintf(stderr, "Command not found\n");
	free(paths);
	exit(EXIT_FAILURE);
}

/**
 * build_full_path - Buld the full path for a command using a directory
 *
 * @dir: Directory path
 *
 * @command: Command name
 *
 * Return: Returns the full path
 */

char *build_full_path(char *dir, char *command)
{
	size_t full_path_length = strlen(dir) + strlen(command) + 2;

	char *full_path = (char *)malloc(full_path_length);
	if (full_path == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	snprintf(full_path, full_path_length, "%s/%s", dir, command);
	return (full_path);
}

/**
 * execute - Main execution function to execute a command
 *
 * @command: The command to execute
 *
 * @env: The environment variables
 */

void execute(char *command, char **env)
{
	char **tokens = tokenize_command(command);
	if (tokens != NULL)
	{
		execute_command(tokens, env);
	}
}
