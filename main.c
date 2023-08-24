#include "simple_shell.h"

/**
 * main - Function to initialize shell
 *
 * @argc: argument count
 *
 * @argv: argument vector
 *
 * @env: environment variables
 *
 * Return: Zero
 */

int main(int argc, char **argv, char **env)
{
	char **tokens;
	char *input = NULL;
	size_t len = 0;
	ssize_t read;
	int is_non_interactive = !isatty(STDIN_FILENO);
	(void)argc;
	(void)argv;

	if (is_non_interactive)
		noninteractive_mode(env);
	else
	{
		while (1)
		{
			printf("$ "); /* Shell prompt */
			read = getline(&input, &len, stdin); /* Read user input */
			if (read == -1)
			{
				printf("\n");
				break;
			}
			if (input[read - 1] == '\n')
				input[read - 1] = '\0'; /* Remove newline character */
			if (strcmp(input, "exit") == 0)
				break;
			if (isspace((unsigned char)input[0]))
				continue;
			if (input[0] == '\0' || input[0] == ' ')
				continue;
			tokens = tokenize_command(input);
			if (tokens)
			{
				execute_command(tokens, env); /* Execute the command entered by the user */
				free(tokens);
			}
		}
		free(input);
		return (0);
	} free(input);
	return (0);
}
