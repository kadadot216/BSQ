/*
** EPITECH PROJECT, 2018
** print.c
** File description:
** Print functions
*/

#include "my.h"
#include "fsys.h"
#include "buffer.h"

void	fs_print_first_line(char const *filepath)
{
	char	buffer[BUFF_SIZE] = {'\0'};
	int	fd = open(filepath, O_RDONLY);
	int	limit = 0;
	char	tmp = 0;
	int	status = 0;

	status = read(fd, buffer, BUFF_SIZE);
	limit = get_x_bytes_until_char(buffer, '\n');
	tmp = buffer[limit];
	buffer[limit] = '\0';
	if (status <= 0)
		my_putstr("Error");
	else
		my_putstr(buffer);
	buffer[limit] = tmp;
	close(fd);

}
