/*
** EPITECH PROJECT, 2018
** cat.c
** File description:
** Cat functions with files
*/

#include "my.h"
#include "fsys.h"

void	fs_cat_x_bytes(char const *filepath, int x)
{
	char		buffer[BUFF_SIZE] = {'\0'};
	int		fd = open(filepath, O_RDONLY);
	int		status = 0;

	if (BUFF_SIZE >= x) {
		status = read(fd, buffer, x);
		if (status <= 0)
			my_putstr("Error");
		else if (status <= x)
			my_putstr(buffer);
	}
	close(fd);
}

void	fs_cat_500_bytes(const char *filepath)
{
	char		buffer[BUFF_SIZE] = {'\0'};
	const int	maxsize = 500;
	int		fd = open(filepath, O_RDONLY);
	int		status = 0;

	if (BUFF_SIZE >= maxsize) {
		status = read(fd, buffer, maxsize);
		if (status <= 0)
			my_putstr("Error");
		else if (status <= 500)
			my_putstr(buffer);
	}
	close(fd);
}
