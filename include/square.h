/*
** EPITECH PROJECT, 2018
** square.h
** File description:
** Header file for square structure
*/

#ifndef __SQUARE_H__
#define __SQUARE_H__

#include "status.h"

typedef struct	square_s {
	enum status_e	status;
	int		size;
	int		ox;
	int		oy;
}	square_t;

int	is_square_of_size(char **map, int col, int row, int square_size);
#if defined(BONUS)
void	display_square_info(square_t *square);
#endif

#endif
