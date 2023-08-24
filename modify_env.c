#include "simple_shell.h"

/**
 * modify_env - Function to modify environment variables
 *
 * @env: array
 *
 * @variable_to_keep: variable to keep as parameter
 *
 */

void modify_env(char **env, const char *variable_to_keep)
{
	/* Count the number of environment variables */
	int num_vars = 0;
	char **new_env = (char **)malloc((num_vars + 2) * sizeof(char *));
	int i;
	
	while (env[num_vars] != NULL)
	{
		num_vars++;
	}

	/* Allocate memory for the new environment array */
	if (new_env == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	/* Copy the desired environment variable into the new array */
	for (i = 0; env[i] != NULL; i++)
	{
		if (strncmp(env[i], variable_to_keep, strlen(variable_to_keep)) == 0)
		{
			new_env[0] = env[i];
			new_env[1] = NULL; /* Terminate the array */
			break;
		}
	}
	/* Free the old environment array */
	free(env);

	/* Execute the command with the modified environment */
	execute("env", new_env);

	/* Free the new environment array */
	free(new_env);
}
