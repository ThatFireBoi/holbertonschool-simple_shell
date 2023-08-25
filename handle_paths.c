#include "simple_shell.h"

/**
 * handle_paths - Extracts paths from the PATH environment variable
 *
 * Return: A pointer to an array of strings containing the paths
 *         NULL on failure or if PATH is not found
 */

char **handle_paths(void)
{
	int num_paths = 0;
	char *path_env = NULL;
	char *token = NULL;
	char **paths = NULL;

	path_env = getenv("PATH");
	if (path_env == NULL)
	{
		perror("error ");
		return (NULL);
	}

	token = strtok(path_env, ":");
	while (token != NULL)
	{
		paths = realloc(paths, sizeof(char *) * (num_paths + 1));
		if (paths == NULL)
		{
			perror("error ");
			free(paths);
			return (NULL);
		}

		paths[num_paths] = token;
		num_paths++;
		token = strtok(NULL, ":"); /* Next token */
	}

	paths = realloc(paths, sizeof(char *) * (num_paths + 1));
	paths[num_paths] = NULL; /* End of array NULL pointer */

	return (paths);
}
