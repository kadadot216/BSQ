/*
** EPITECH PROJECT, 2018
** board_check.c
** File description:
** Function for board checking
*/

static int	is_valid_char(char point)
{
	if (point == 'o' || point == '.' || point == '\n' || point == '\0')
		return (1);
	else
		return (0);
}

int	check_board_integrity(char **map, int nb_rows, int nb_cols)
{
	int	x = 0;
	int	y = 0;

	while ((y < nb_rows) && (x < nb_cols)) {
		if (!is_valid_char(map[y][x]))
			return (0);
		x++;
		if (x == nb_cols && y < nb_rows) {
			y++;
			x = 0;
		}
	}
	return (1);
}
