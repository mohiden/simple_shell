#include "shell.h"

/**
* _getline - read one line from the prompt.
* @data: struct for the program's data
*
* Return: reading counting bytes.
*/

int _getline(data_of_program *data)
{
	char buff[BUFFER_SIZE] = {'\0'};
	static char *commands[10] = {NULL};
	static char operators[10] = {'\0'};
	ssize_t bytes_read, i = 0;

	if (!commands[0] || (operators[0] == '&' && errno != 0) ||
		(operators[0] == '|' && errno == 0))
	{

		for (i = 0; commands[i]; i++)
		{
			free(commands[i]);
			commands[i] = NULL;
		}


		bytes_read = read(data->file_descriptor, &buff, BUFFER_SIZE - 1);
		if (bytes_read == 0)
			return (-1);


		i = 0;
		do {
			commands[i] = str_dup(_strtok(i ? NULL : buff, "\n;"));
			/*checks and split for && and || operators*/
			i = check_logic_ops(commands, i, operators);
		} while (commands[i++]);
	}
	data->input_line = commands[0];
	for (i = 0; commands[i]; i++)
	{
		commands[i] = commands[i + 1];
		operators[i] = operators[i + 1];
	}

	return (str_length(data->input_line));
}


/**
* check_logic_ops - checks and split for && and || operators
* @commands: array of the commands.
* @i: index in the array_commands to be checked
* @operators: array of the logical operators for each previous command
*
* Return: index of the last command in the array_commands.
*/

int check_logic_ops(char *commands[], int i, char operators[])
{
	char *temp = NULL;
	int j;

	for (j = 0; commands[i] != NULL  && commands[i][j]; j++)
	{
		if (commands[i][j] == '&' && commands[i][j + 1] == '&')
		{

			temp = commands[i];
			commands[i][j] = '\0';
			commands[i] = str_dup(commands[i]);
			commands[i + 1] = str_dup(temp + j + 2);
			i++;
			operators[i] = '&';
			free(temp);
			j = 0;
		}
		if (commands[i][j] == '|' && commands[i][j + 1] == '|')
		{

			temp = commands[i];
						commands[i][j] = '\0';
			commands[i] = str_dup(commands[i]);
			commands[i + 1] = str_dup(temp + j + 2);
			i++;
			operators[i] = '|';
			free(temp);
			j = 0;
		}
	}
	return (i);
}
