/*
** EPITECH PROJECT, 2018
** my_puterror.c
** File description:
** Displays, one-by-one, the characters of a string
*/

#include "my.h"

int	my_puterror(const char *str)
{
	unsigned int	i = 0;

	while (str[i] != '\0')
		i++;
	write(2, str, i);
	return (0);
}
