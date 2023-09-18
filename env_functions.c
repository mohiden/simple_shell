#include "shell.h"

/**
 * builtin_env - shows the environment where the shell runs
 * @data: struct for the program's data
 * Return: zero if sucess, or other number if its declared in the arguments
 */

int _env(data_of_program *data)
{
	int i;
	char c[50] = {'\0'};
	char *_copy = NULL;

	if (data->tokens[1] == NULL)
		print_environ(data);
	else
	{
		for (i = 0; data->tokens[1][i]; i++)
		{
			if (data->tokens[1][i] == '=')
			{

				_copy = str_dup(env_get_key(c, data));
				if (_copy != NULL)
					env_set_key(c, data->tokens[1] + i + 1, data);


				print_environ(data);
				if (env_get_key(c, data) == NULL)
				{
					_print(data->tokens[1]);
					_print("\n");
				}
				else
				{
					env_set_key(c, _copy, data);
					free(_copy);
				}
				return (0);
			}
			c[i] = data->tokens[1][i];
		}
		errno = 2;
		perror(data->command_name);
		errno = 127;
	}
	return (0);
}

/**
 * _set_env - ..
 * @data: struct for the program's data
 * Return: zero if sucess, or other number if its declared in the arguments
 */

int _set_env(data_of_program *data)
{

	if (data->tokens[1] == NULL || data->tokens[2] == NULL)
		return (0);
	if (data->tokens[3] != NULL)
	{
		errno = E2BIG;
		perror(data->command_name);
		return (5);
	}

	env_set_key(data->tokens[1], data->tokens[2], data);

	return (0);
}

/**
 * _unset_env - ..
 * @data: struct for the program's data'
 * Return: ..
 */

int _unset_env(data_of_program *data)
{

	if (data->tokens[1] == NULL)
		return (0);
	if (data->tokens[2] != NULL)
	{
		errno = E2BIG;
		perror(data->command_name);
		return (5);
	}
	env_remove_key(data->tokens[1], data);

	return (0);
}
