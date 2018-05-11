/*
** EPITECH PROJECT, 2018
** bsq.h
** File description:
** Header file for bsq_helpers.c
*/

#ifndef __BSQ_H__
#define __BSQ_H__

enum	status_e { OFF, ON };

typedef struct	board_s {
	enum status_e	status;
	int		nb_rows;
	int		nb_cols;
	char		**map;
}	board_t;

typedef struct	square_s {
	int	size;
	int	ox;
	int	oy;
}	square_t;

char	**load_2d_arr_from_file(char const *filepath, int nb_rows, int nb_cols);
//int	find_biggest_square(char **map, int nb_rows, int nb_cols, int row, int col);
int	is_square_of_size(char **map, int col, int row, int square_size);

#endif
