/*
** EPITECH PROJECT, 2018
** my_str_isnum.c
** File description:
** Check wheter a string contains only numerals
*/

#include "my.h"

int	my_str_hasnum(char const *str)
{
	int	i = 0;
	int	nb = 0;

	while (str[i] != '\0') {
		if (my_char_isnum(str[i]))
			nb++;
		i++;
	}
	return (nb);
}

