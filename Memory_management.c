#include "shell.h"

/**
 * free_recurrent - free the fields needed each loop
 * @data: struct of the program's data
 * Return: Nothing
 */

void free_recurrent(data_of_program *data)
{
	if (data->tokens)
		free_array(data->tokens);
	if (data->input_line)
		free(data->input_line);
	if (data->command_name)
		free(data->command_name);

	data->input_line = NULL;
	data->command_name = NULL;
	data->tokens = NULL;
}

/**
 * free_all - free all field of the data
 * @data: struct of the program's data
 * Return: Nothing
 */
void free_all(data_of_program *data)
{
	if (data->file_descriptor != 0)
	{
		if (close(data->file_descriptor))
			perror(data->program_name);
	}
	free_recurrent(data);
	free_array(data->env);
	free_array(data->alias_list);
}

/**
 * free_array - frees each pointer of an array of pointers and the
 * array too
 * @array: array of pointers
 * Return: nothing
 */

void free_array(char **array)
{
	int i;

	if (array != NULL)
	{
		for (i = 0; array[i]; i++)
			free(array[i]);

		free(array);
		array = NULL;
	}
}
