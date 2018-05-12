#ifndef __BOARD_H__
#define __BOARD_H__

#include "status.h"

typedef struct	board_s {
	enum status_e	status;
	int		nb_rows;
	int		nb_cols;
	char		**map;
}	board_t;

int	check_board_integrity(char **map, int nb_rows, int nb_cols);

#endif
