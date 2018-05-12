/*
** EPITECH PROJECT, 2018
** debug.c
** File description:
** Main file for GDB
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "my.h"
#include "fsys.h"
#include "main.h"
#include "bsq.h"

int	bsq(char const *filepath, int guess)
{
	char	buffer[BUFF_SIZE] = {'\0'};
	int	fd = fs_open_file(filepath);

	if (guess > BUFF_SIZE)
		return (84);
	fs_understand_return_of_read(fd, buffer, guess);
	close(fd);
	return (0);
}

int	load_file_from_buffer(char *buffer, char const *filepath)
{
	int	fd = open(filepath, O_RDONLY);
	int	rst = 0;

	if (fd < 0)
		return (0);
	rst = read(fd, buffer, 4000);
	if (rst < 1)
		return (0);
	return (1);
}

int	get_nb_cols(char *buffer)
{
	int	nb_rows = 0;

	while (buffer[nb_rows] != '\n')
		nb_rows++;
	return (nb_rows);
}

int	get_nb_rows(char *buffer)
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

char	**load_2d_arr_from_buffer(char *buffer, int nb_rows, int nb_cols)
{
	char	**arr;
	int	i = 0;
	int	j = 0;

	arr = malloc(sizeof(char *) * (nb_rows + 1));
	while (j < nb_rows) {
		arr[j] = malloc(sizeof(char) * (nb_cols + 1));
		my_strncpy(arr[j], &buffer[i], nb_cols);
		arr[j][nb_cols + 1] = '\0';
		i += (nb_cols + 1);
		j++;
	}
	arr[nb_rows + 1] = NULL;
	return (arr);
}

board_t	init_board(char const *filepath)	
{
	char	buffer[4000] = {0};

	board_t	b;
	b.status = OFF;
	if (!load_file_from_buffer(buffer, filepath))
		return (b);
	b.nb_rows = get_nb_rows(buffer);
	b.nb_cols = get_nb_cols(buffer);
	b.map = load_2d_arr_from_buffer(buffer, b.nb_rows, b.nb_cols);
	b.status = ON;
	return (b);
}

int	in_square(int x, int y, square_t *square)
{
	int	size = square->size;
	int	ox = square->ox;
	int	oy = square->oy;

	if (x >= ox && x < ox + size && y >= oy && y < oy + size) {
		return (1);
	} else {
		return (0);
	}
}

void	display_square(square_t *square, board_t *board)
{
	int	x = 0;
	int	y = 0;

	while (y < board->nb_rows && x < board->nb_cols) {
		if (in_square(x, y, square))
			my_putchar('X');
		else
			my_putchar(board->map[y][x]);
		x++;
		if (x == board->nb_cols - 1) {
			y++;
			x = 0;
			my_putchar('\n');
		}
	}
}

square_t	find_biggest_square(board_t *b)
{
	square_t	square;

	square.ox = 0;
	square.oy = 0;
	square.size = 0;
	int	x = 0;
	int	y = 0;
	int	offset = 0;

	while (y < b->nb_rows && x < b->nb_cols) {
		while (offset < b->nb_rows - y && is_square_of_size(b->map, x, y, (offset + 1)))
			offset++;
		if (offset > square.size) {
			square.size = offset;
			square.ox = x;
			square.oy = y;
		}
		x++;
		if (x == (b->nb_cols - 1) && y < b->nb_rows) {
			y++;
			x = 0;
		} 
		offset = 0;
	}
	my_putstr("Biggest square at pos (");
	my_put_nbr(square.ox);
	my_putstr(", ");
	my_put_nbr(square.oy);
	my_putstr(")\n");
	my_putstr("of size: ");
	my_put_nbr(square.size);
	my_putstr("\n");
	return (square);
}


int	main(int ac, char **av)
{
	board_t		board;
	square_t	biggest_square;

	if (ac != 2)
		return (84);
	board = init_board(av[1]);
	if (board.status == OFF)
		return (84);
	biggest_square = find_biggest_square(&board);
	display_square(&biggest_square, &board);
	return (0);
}
