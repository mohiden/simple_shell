#include "shell.h"

/**
 * builtins_list - search for match and execute the associate builtin
 * @data: struct for the program's data
 * Return: Returns the return of the function executed is there is a match,
 * otherwise returns -1.
 **/

int builtins_list(data_of_program *data)
{
	int i;
	builtins options[] = {
		{"exit", b_exit},
		{"help", _help},
		{"cd", _cd},
		{"alias", _alias},
		{"env", _env},
		{"setenv", _set_env},
		{"unsetenv", _unset_env},
		{NULL, NULL}
	};

	for (i = 0; options[i].builtin != NULL; i++)
	{
		if (str_comp(options[i].builtin, data->command_name, 0))
		{
			return (options[i].function(data));
		}
	}
	return (-1);
}
