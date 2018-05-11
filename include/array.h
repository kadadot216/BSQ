/*
** EPITECH PROJECT, 2018
** array.h
** File description:
** Header file for array.c
*/

#ifndef __ARRAY_H__
#define __ARRAY_H__

void	array_1d_print_chars(char const *arr);
void	array_1d_print_ints(int const *arr, int size);
int	array_1d_sum(int const *arr, int size);
int	array_2d_sum(int **arr, int nb_rows, int nb_cols);
int	array_2d_how_many(int **arr, int nb_rows, int nb_cols, int number);

#endif
