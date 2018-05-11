/*
** EPITECH PROJECT, 2018
** get.c
** File description:
** fs_get functions
*/

#include "my.h"
#include "fsys.h"
#include "buffer.h"

static int	my_wrapper_getnbr(const char *str)
{
	int	i = 0;
	int	nb = (-1);

	while (str[i] != 0) {
		if (my_char_isnum(str[i])) {
			nb = my_getnbr(&str[i]);
			return (nb);
		}
		i++;
	}
	return (nb);
}

int	fs_get_number_from_first_line(char const *filepath)
{
	char	buffer[BUFF_SIZE] = {'\0'};
	int	fd = open(filepath, O_RDONLY);
	int	limit = 0;
	int	my_number = (-1);
	int	status = 0;

	status = read(fd, buffer, BUFF_SIZE);
	if (status <= 0)
		return (-1);
	limit = get_x_bytes_until_char(buffer, '\n');
	buffer[limit] = '\0';
	if (my_str_hasnum(buffer))
		my_number = my_wrapper_getnbr(buffer);
	close(fd);
	return (my_number);
}
