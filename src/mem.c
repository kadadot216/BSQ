/*
** EPITECH PROJECT, 2018
** mem.c
** File description:
** Memory allocation functions
*/

#include "my.h"
#include "mem.h"

char	*mem_alloc(char const *a, char const *b)
{
	int	sa = my_strlen(a);
	int	sb = my_strlen(b);
	char	*dest = malloc(sizeof(char) * (sa + sb + 1));

	my_memset(dest, '\0', sa + sb);
	my_strcat(dest, a);
	my_strcat(dest, b);
	return (dest);
}

char	**mem_alloc_2d_array(int nb_rows, int nb_cols)
{
	char	**array = malloc(sizeof(char *) * (nb_rows + 1));
	int	i = 0;

	array[nb_rows] = NULL;
	while (i < nb_rows) {
		array[i] = malloc(sizeof(char) * (nb_cols + 1));
		my_memset(array[i], '\0', nb_cols);
		i++;
	}
	return (array);
}

char	**mem_dup_2d_array(char **arr, int nb_rows, int nb_cols)
{
	char	**array = malloc(sizeof(char *) * (nb_rows + 1));
	int	i = 0;

	array[nb_rows] = NULL;
	while (i < nb_rows) {
		array[i] = my_strdup(arr[i]);
		i++;
	}
	return (array);
}
