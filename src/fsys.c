/*
** EPITECH PROJECT, 2018
** fsys.c
** File description:
** File handling function
*/

#include "my.h"
#include "fsys.h"

int	fs_open_file(char const *filepath)
{
	int	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		my_putstr("FAILURE\n");
	else
		my_putstr("SUCCESS\n");
	return (fd);
}

static char	*get_message(int res, int size)
{
	if (res <= 0) {
		return (res == 0) ?
			"read has nothing more to read\n" : 
			"read failed\n";
	} else if (size < res) {
		return ("read didn't complete the entire buffer\n");
	} else
		return ("read completed the entire buffer\n");
}

void	fs_understand_return_of_read(int fd, char *buffer, int size)
{
	int	res = read(fd, buffer, BUFF_SIZE);
	char	*message = get_message(res, size);

	my_putstr(message);
}
