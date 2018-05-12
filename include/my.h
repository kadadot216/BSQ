/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** Header file for my lib
*/

#ifndef __MY_H__
#define __MY_H__

#include <unistd.h>
#include <stdlib.h>

void	my_memset(char *str, char c, unsigned int size);
void	my_putchar(char c);
int	my_put_nbr(int nb);
int	my_putstr(const char *str);
int	my_puterror(const char *str);
char	*my_strncpy(char *dest, char const *src, int n);

#endif
