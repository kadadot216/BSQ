/*
** EPITECH PROJECT, 2018
** square.c
** File description:
** Functions for squares
*/

#include "my.h"
#include "square.h"
#include "board.h"

static square_t	set_square(int x, int y, int size, enum status_e STATUS)
{
	square_t	square;
	square.ox = x;
	square.oy = y;
	square.size = size;
	square.status = STATUS;

	return (square);
}

square_t	find_biggest_square(board_t *b)
{
	square_t	best = set_square(0, 0, 0, UNSET);
	square_t	curr = set_square(0, 0, 0, UNSET);

	while ((curr.oy < b->nb_rows) && (curr.ox < b->nb_cols)) {
		while ((curr.size < (b->nb_rows - curr.oy)) &&
		is_square_of_size(b->map, curr.ox, curr.oy, (curr.size + 1))) {
			curr.size++;
		}
		if (curr.size > best.size)
			best = set_square(curr.ox, curr.oy, curr.size, SET);
		curr.ox++;
		curr.size = 0;
		if (curr.ox == (b->nb_cols - 1) && (curr.oy < b->nb_rows)) {
			curr.oy++;
			curr.ox = 0;
		}
	}
	return (best);
}
