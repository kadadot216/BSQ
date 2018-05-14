/*
** EPITECH PROJECT, 2018
** my_str_isnum.c
** File description:
** Check wheter a string contains only numerals
*/

#include "my.h"

int	my_strn_isnum(char const *str, int n)
{
	int	i = 0;

	if (str[0] == '-')
		i++;
	while (str[i] != '\0' && i < n) {
		if (!(my_char_isnum(str[i])))
			return (0);
		else
			i++;
	}
	return (1);
}

