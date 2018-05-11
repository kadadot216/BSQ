/*
** EPITECH PROJECT, 2018
** my_char_isnum.c
** File description:
** Check wheter a char is an numerical character
*/

int	my_char_isnum(char const c)
{
	if ((c >= '0' && c <= '9') || c == '-')
		return (1);
	else
		return (0);
}

