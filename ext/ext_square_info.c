/*
** EPITECH PROJECT, 2018
** ext_square_info.c
** File description:
** ext file for more display options
*/

#include "square.h"
#include "my.h"

void	display_square_info(square_t *square)
{
	my_putstr("Biggest square at pos (");
	my_put_nbr(square->ox);
	my_putstr(", ");
	my_put_nbr(square->oy);
	my_putstr(")\n");
	my_putstr("of size: ");
	my_put_nbr(square->size);
	my_putstr("\n");
}

