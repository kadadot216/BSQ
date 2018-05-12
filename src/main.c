/*
** EPITECH PROJECT, 2018
** debug.c
** File description:
** Main file for GDB
*/

#include "main.h"

int	main(int ac, char **av)
{
	board_t		board;
	square_t	biggest_square;

	if (ac != 2)
		return (84);
	board = init_board(av[1]);
	if (board.status == UNSET)
		return (84);
	biggest_square = find_biggest_square(&board);
	if (biggest_square.status == UNSET)
		return (84);
	display_square(&biggest_square, &board);
	display_square_info(&biggest_square);
	clean_board(&board);
	clean_square(&biggest_square);
	if (biggest_square.status == UNSET && board.status == UNSET)
		return (0);
	else
		return (84);
}
