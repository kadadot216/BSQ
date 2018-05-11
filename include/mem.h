/*
** EPITECH PROJECT, 2018
** mem.h
** File description:
** Header file for mem.c
*/

#ifndef __MEM_H__
#define __MEM_H__

#include <stdlib.h>

char	*mem_alloc(char const *a, char const *b);
char	**mem_alloc_2d_array(int nb_rows, int nb_cols);
char	**mem_dup_2d_array(char **arr, int nb_rows, int nb_cols);

#endif
