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
	char **new_env = (char **)malloc((num_vars + 3) * sizeof(char *));
	int i;
	int new_env_index = 0;
	while (env[num_vars] != NULL)
	{
		num_vars++;
	}

	/* Create a new environment array with space for the modified PATH */
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
			new_env[new_env_index] = env[i];
			new_env_index++;
			new_env[new_env_index] = NULL; /* Terminate the array */
			break;
		}
	}

	/* Modify PATH and add standard directories */
	new_env[new_env_index] = "PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin";
	new_env_index++;

	/* Copy the remaining environment variables */
	for (i = 0; env[i] != NULL; i++)
	{
		if (strncmp(env[i], variable_to_keep, strlen(variable_to_keep)) != 0)
		{
			new_env[new_env_index] = env[i];
			new_env_index++;
		}
	}
	new_env[new_env_index] = NULL;

	/* Execute the command with the modified environment */
	execute("env", new_env);

	/* Free the new environment array */
	free(new_env);
}
