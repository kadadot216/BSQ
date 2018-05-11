/*
** EPITECH PROJECT, 2018
** bsq_helpers.c
** File description:
** Helper functions for BSQ
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "my.h"
#include "buffer_constants.h"

//char	*load_file_in_mem(char const *filepath)
//{
//	char	buffer[BUFSIZE] = {0};
//	char	*membuf;
//	int	fd = open(filepath, O_RDONLY);
//	int	rstat = 0;
//
//	if (fd < 0)
//		return (NULL);
//	rstat = read(fd, buffer, BUFSIZE);
//	if (rstat < 1)
//		return (NULL);
//	membuf = my_strdup(buffer);
//	return (membuf);
//}


int	is_square_of_size(char **map, int col, int row, int square_size)
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

//int	find_biggest_square(char **map, int nb_rows, int nb_cols, int row, int col)
//{
//	int	i = col;
//	int	j = row;
//	int	res = 0;
//	int	besti = 0;
//	int	bestj = 0;
//	int	offset = 1;
//	int	best_score = 0;
//
//	while (j < nb_rows && i < nb_cols) {
//		res = is_square_of_size(map, j, i, offset);
//		if (res) {
//			if (best_score < offset) {
//				best_score = offset;
//				besti = i;
//				bestj = j;
//			}
//			offset++;
//		}
//		else {
//			i++;
//			offset = 0;
//		}
//		if (i == nb_cols - 1) {
//			j++;
//			i = 0;
//			offset = 0;
//		}
//	}
//	my_putstr("Biggest square at pos ");
//	my_put_nbr(bestj);
//	my_putstr(", ");
//	my_put_nbr(besti);
//	return (0);
//}
