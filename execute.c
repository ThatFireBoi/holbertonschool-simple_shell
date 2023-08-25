#include "simple_shell.h"

/**
 * execute - Function to execute a command using fork and execve
 *
 * @command: The command to execute
 *
 * @env: The environment variables
 */

void execute(char *command, char **env)
{
	pid_t child_pid;
	char *token = NULL;
	char **tokens = NULL;
	int token_count = 0;

	token = strtok(command, " \n"); /* Tokenization */
	if (token == NULL)
		return;

	while (token != NULL)
	{
		tokens = realloc(tokens, sizeof(char *) * (token_count + 2));
		if (tokens == NULL)
		{
			perror("realloc");
			return;
		}
		tokens[token_count] = token;
		token_count++;
		token = strtok(NULL, " \n");
	}
	tokens[token_count] = NULL;
	child_pid = fork(); /* Fork syscall to create child process */
	if (child_pid == -1)
	{
		perror("Fork Failure");
		free(tokens);
		return;
	}
	if (child_pid == 0)
	{
		if (tokens[0][0] == '/')
		{
			if (execve(tokens[0], tokens, env) == -1) /* Execute using execve */
			{
				perror("Execve Error");
				exit(EXIT_FAILURE); /* Exit child process with failure status */
			}
		}
		else
		{
		char **paths = handle_paths(); /* Search in dir listed in PATH */
		int i;

		for (i = 0; paths[i] != NULL; i++)
		{
			char *full_path = (char *)malloc(strlen(paths[i]) + strlen(tokens[0]) + 2);

			if (full_path == NULL)
			{
				perror("malloc");
				free(paths);
				exit(EXIT_FAILURE);
			}
			sprintf(full_path, "%s/%s", paths[i], tokens[0]);
			if (access(full_path, X_OK) == 0)
			{
				if (execve(full_path, tokens, env) == -1)
				{
					perror("Execve Error");
					exit(EXIT_FAILURE);
				}
				free(full_path);
				return;
			}
			free(full_path);
		}
		fprintf(stderr, "./hsh: 1: %s: not found\n", tokens[0]);
		free(paths);
		exit(EXIT_FAILURE);
	}
	}
	else
	{
		waitpid(child_pid, NULL, 0); /* Await end of child */
		free(tokens);
	}
}
