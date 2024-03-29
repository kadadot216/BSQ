#include "my.h"
#include "square.h"
#include "board.h"

static square_t	set_square(int x, int y, int size)
{
	square_t	square;
	square.ox = x;
	square.oy = y;
	square.size = size;

	return (square);
}

static void	set_square_status(enum status_e *STATUS)
{
	if (*STATUS == UNSET)
		*STATUS = SET;
}

square_t	find_biggest_square(board_t *b)
{
	square_t	best = set_square(0, 0, 0);
	square_t	curr = set_square(0, 0, 0);

	best.status = UNSET;
	curr.status = UNSET;
	while ((curr.oy < b->nb_rows) && (curr.ox < b->nb_cols)) {
		while ((curr.size < (b->nb_rows - curr.oy)) &&
		is_square_of_size(b->map, curr.ox, curr.oy, (curr.size + 1))) {
			curr.size++;
			set_square_status(&best.status);
		}
		if (curr.size > best.size)
			best = set_square(curr.ox, curr.oy, curr.size);
		curr.ox++;
		curr.size = 0;
		if (curr.ox == (b->nb_cols - 1) && (curr.oy < b->nb_rows)) {
			curr.oy++;
			curr.ox = 0;
		}
	}
	return (best);
}
