/*
** EPITECH PROJECT, 2018
** square_info.c
** File description:
** Info function for square structures
*/

#include "my.h"
#include "square.h"
#include "board.h"

int		is_square_of_size(char **map, int col, int row, int square_size)
{
	int	i = col;
	int	j = row;

	while (j < row + square_size && i < col + square_size) {
		if (map[j][i] == 'o' || map[j][i] == '\0')
			return (0);
		if (i == col + (square_size - 1) && j < row + square_size) {
			i = col;
			j++;
		} else
			i++;
	}
	return (1);
}

static int	in_square(int x, int y, square_t *square)
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

void		display_square(square_t *square, board_t *board)
{
	int	x = 0;
	int	y = 0;

	while (y < board->nb_rows && x < board->nb_cols) {
		if (in_square(x, y, square))
			my_putchar('x');
		else
			my_putchar(board->map[y][x]);
		x++;
		if (x == board->nb_cols && y < board->nb_rows) {
			y++;
			x = 0;
			my_putchar('\n');
		}
	}
	#if defined(BONUS)
		display_square_info(square);
	#endif
}
