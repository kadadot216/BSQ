/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** GDB Main file
*/

#include "my.h"
#include "bsq.h"

int	main(int ac, char **av)
{
	char	**map = load_2d_arr_from_file("./rectangle", 9, 18);

	find_biggest_square(map, 9, 18, 0, 0);
	free(map);
	return (0);
}

