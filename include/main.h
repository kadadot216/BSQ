#ifndef __MAIN_H__
#define __MAIN_H__

#include "square.h"
#include "board.h"

square_t	find_biggest_square(board_t *b);
board_t	init_board(char const *filepath);
void	display_square(square_t *square, board_t *board);
int	clean_board(board_t *board);
int	clean_square(square_t *biggest_square);

#endif
