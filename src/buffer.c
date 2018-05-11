/*
** EPITECH PROJECT, 2018
** buffer.c
** File description:
** Buffer maniupation function
*/

int	get_x_bytes_until_char(char const *buffer, char c)
{
	int	i = 0;

	while (buffer[i] != c)
		i++;
	return (i);
}

