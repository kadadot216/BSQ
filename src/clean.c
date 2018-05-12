/*
** EPITECH PROJECT, 2018
** clean.c
** File description:
** Clearing structures functions
*/

#include <stdlib.h>
#include "board.h"
#include "square.h"

int	clear_map(char **map, int nb_rows)
{
	int	y = 0;

	while (y < nb_rows) {
		y++;
		free(map[y]);
		map[y] = NULL;
	}
	free(map);
	map = NULL;
	return (1);
}

int	clean_board(board_t *board)
{
	clear_map(board->map, board->nb_rows);
	board->nb_rows = 0;
	board->nb_cols = 0;
	board->status = UNSET;
	return (1);
}

int	clean_square(square_t *square)
{
	square->ox = 0;
	square->oy = 0;
	square->size = 0;
	square->status = UNSET;
	return (1);
}
