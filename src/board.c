/*
** EPITECH PROJECT, 2018
** board.c
** File description:
** Board functions
*/

#include "fsys.h"
#include "my.h"
#include "board.h"

static int	load_file_from_buffer(char *buffer, char const *filepath)
{
	int	fd = open(filepath, O_RDONLY);
	int	rst = 0;

	if (fd < 0)
		return (0);
	rst = read(fd, buffer, MAXBUFSIZE);
	if (rst < 1)
		return (0);
	return (1);
}

static char	**load_2d_arr_from_buffer(char *buffer,
int nb_rows, int nb_cols)
{
	char	**arr;
	int	i = 0;
	int	j = 0;

	arr = malloc(sizeof(char *) * (nb_rows + 1));
	while (j < nb_rows) {
		arr[j] = malloc(sizeof(char) * (nb_cols + 1));
		my_memset(arr[j], '\0', (nb_cols + 1));
		my_strncpy(arr[j], &buffer[i], nb_cols);
		i += (nb_cols + 1);
		j++;
	}
	arr[nb_rows + 1] = NULL;
	return (arr);
}

static int	get_nb_cols(char *buffer)
{
	int	nb_rows = 0;

	while (buffer[nb_rows] != '\n')
		nb_rows++;
	return (nb_rows);
}

static int	get_nb_rows(char *buffer)
{
	int	i = 0;
	int	nb_cols = 0;

	while (buffer[i] != '\0') {
		if (buffer[i] == '\n')
			nb_cols++;
		i++;
	}
	return (nb_cols);
}

board_t	init_board(char const *filepath)
{
	char	buffer[MAXBUFSIZE] = {0};

	board_t	b;
	b.status = UNSET;
	if (!load_file_from_buffer(buffer, filepath)) {
		my_puterror("Error - Couldn't load file");
		return (b);
	}
	b.nb_rows = get_nb_rows(buffer);
	b.nb_cols = get_nb_cols(buffer);
	b.map = load_2d_arr_from_buffer(buffer, b.nb_rows, b.nb_cols);
	if (!check_board_integrity(b.map, b.nb_rows, b.nb_cols)) {
		my_puterror("Error - Invalid map");
		return (b);
	}
	b.status = SET;
	return (b);
}
