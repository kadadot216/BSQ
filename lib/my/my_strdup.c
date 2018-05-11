/*
** EPITECH PROJECT, 2018
** my_strdup.c
** File description:
** Allocates memory and copies the string given as argument in it
*/

#include "my.h"
#include <stdlib.h>

char	*my_strdup(char const *src)
{
	int	i = 0;
	int	srcl = my_strlen(src);
	char	*copy;

	copy = malloc(sizeof(*src) * (srcl + 1));
	my_memset(copy, '\0', srcl);
	while (src[i] != '\0') {
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
