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
	char *input = NULL;
	ssize_t read;
	size_t len = 0;
	int is_non_interactive = !isatty(STDIN_FILENO);
	(void)argc, argv;

	if (is_non_interactive)
		noninteractive_mode(env);
	else
	{
		while (1)
		{
			printf("$ "); /* PS1 prompt */
			read = getline(&input, &len, stdin);
			if (read == -1)
			{
				printf("\n");
				break;
			}
			if (input[read - 1] == '\n')
				input[read - 1] = '\0';
			if (strcmp(input, "exit") == 0)
				break;
			if (isspace((unsigned char)input[0]))
				continue;
			if (input[0] == '\0' || input[0] == ' ')
				continue;
			execute(input, env); /* Execute inputted command */
		}
		free(input);
		return (0);
	} free(input);
	return (0);
}
