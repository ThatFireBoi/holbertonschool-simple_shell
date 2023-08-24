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
	int num_vars = 0;
	char **new_env = (char **)malloc((num_vars + 3) * sizeof(char *));
	int i;
	int new_env_index = 0;

	while (env[num_vars] != NULL)
	{
		num_vars++;
	}
	if (new_env == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
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
	new_env[new_env_index] =
		"PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin";
	new_env_index++;

	for (i = 0; env[i] != NULL; i++)
	{
		if (strncmp(env[i], variable_to_keep, strlen(variable_to_keep)) != 0)
		{
			new_env[new_env_index] = env[i];
			new_env_index++;
		}
	}
	new_env[new_env_index] = NULL;
	execute("env", new_env);
	free(new_env);
}
