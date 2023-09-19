#include "shell.h"
/**
 * tokenize - this function separate the string using a designed delimiter
 * @data: a pointer to the program's data
 * Return: data_of_program
 */
void tokenize(data_of_program *data)
{
	char *delimiter = " \t";
	int i, j, counter = 2, length;

	length = str_length(data->input_line);
	if (length)
	{
		if (data->input_line[length - 1] == '\n')
			data->input_line[length - 1] = '\0';
	}

	for (i = 0; data->input_line[i]; i++)
	{
		for (j = 0; delimiter[j]; j++)
		{
			if (data->input_line[i] == delimiter[j])
				counter++;
		}
	}

	data->tokens = malloc(counter * sizeof(char *));
	if (data->tokens == NULL)
	{
		perror(data->program_name);
		exit(errno);
	}
	i = 0;
	data->tokens[i] = str_dup(_strtok(data->input_line, delimiter));
	data->command_name = str_dup(data->tokens[0]);
	while (data->tokens[i++])
	{
		data->tokens[i] = str_dup(_strtok(NULL, delimiter));
	}
}
