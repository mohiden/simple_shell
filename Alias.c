#include "shell.h"

/**
 * _alias - add, remove or show aliases
 * @data: struct for the program's data
 * @alias: name of the alias to be printed
 * Return: zero if sucess, or other number if its declared in the arguments
 */

int _alias(data_of_program *data, char *alias)
{
	int i, j, len;
	char buffer[250] = {'\0'};

	if (data->alias_list)
	{
		len = str_length(alias);
		for (i = 0; data->alias_list[i]; i++)
		{
			if (!alias || (str_comp(data->alias_list[i], alias, len)
				&&	data->alias_list[i][len] == '='))
			{
				for (j = 0; data->alias_list[i][j]; j++)
				{
					buffer[j] = data->alias_list[i][j];
					if (data->alias_list[i][j] == '=')
						break;
				}
				buffer[j + 1] = '\0';
				buffer_add(buffer, "'");
				buffer_add(buffer, data->alias_list[i] + j + 1);
				buffer_add(buffer, "'\n");
				_print(buffer);
			}
		}
	}

	return (0);
}

/**
 * get_alias - add, remove or show aliases
 * @name: of alias
 * @data: struct for the program's data * @name: name of the requested alias.
 * Return: zero if sucess, or other number if its declared in the arguments
 */

char *get_alias(data_of_program *data, char *name)
{
	int i, len;

	if (name == NULL || data->alias_list == NULL)
		return (NULL);

	len = str_length(name);

	for (i = 0; data->alias_list[i]; i++)
	{
		if (str_comp(name, data->alias_list[i], len) &&
			data->alias_list[i][len] == '=')
		{
			return (data->alias_list[i] + len + 1);
		}
	}

	return (NULL);

}
/**
 * set_alias - add, or override alias
 * @s: alias to be set in the form (name='value')
 * @data: struct for the program's data
 * Return: zero if sucess, or other number if its declared in the arguments
 */

int set_alias(char *s, data_of_program *data)
{
	int i, j;
	char buffer[250] = {'0'}, *temp = NULL;

	if (s == NULL ||  data->alias_list == NULL)
		return (1);

	for (i = 0; s[i]; i++)
		if (s[i] != '=')
			buffer[i] = s[i];
		else
		{
			temp = get_alias(data, s + i + 1);
			break;
		}


	for (j = 0; data->alias_list[j]; j++)
		if (str_comp(buffer, data->alias_list[j], i) &&
				data->alias_list[j][i] == '=')
		{
			free(data->alias_list[j]);
			break;
		}

	if (temp)
	{
		buffer_add(buffer, "=");
		buffer_add(buffer, temp);
		data->alias_list[j] = str_dup(buffer);
	}
	else
		data->alias_list[j] = str_dup(s);
	return (0);
}
