/*
** EPITECH PROJECT, 2018
** array.c
** File description:
** Arrays functions
*/

#include "my.h"
#include "buffer.h"
#include "fsys.h"

void	array_1d_print_chars(char const *arr)
{
	while (*arr != '\0') {
		my_putchar(*arr);
		my_putchar('\n');
		arr++;
	}
}

void	array_1d_print_ints(int const *arr, int size)
{
	int	i = 0;

	while (i < size) {
		my_put_nbr(arr[i]);
		my_putchar('\n');
		i++;
	}
}

int	array_1d_sum(int const *arr, int size)
{
	int	i = 0;
	int	sum = 0;

	while (i < size) {
		sum += arr[i];
		i++;
	}
	return (sum);
}

int	array_2d_sum(int **arr, int nb_rows, int nb_cols)
{
	int	sum = 0;
	int	i = 0;
	int	j = 0;

	while (j < nb_rows && i < nb_cols) {
		sum += arr[j][i];
		i++;
		if (i == nb_cols && j < (nb_rows - 1)) {
			j++;
			i = 0;
		}
	}
	return (sum);
}

int	array_2d_how_many(int **arr, int nb_rows, int nb_cols, int number)
{
	int	nbnb = 0;
	int	i = 0;
	int	j = 0;

	while (j < nb_rows && i < nb_cols) {
		if (arr[j][i] == number)
			nbnb++;
		i++;
		if (i == nb_cols && j < (nb_rows - 1)) {
			j++;
			i = 0;
		}
	}
	return (nbnb);
}
