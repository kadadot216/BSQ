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
int	my_char_isnum(char const c);
int	my_getnbr(char const *str);
int	my_put_nbr(int nb);
int	my_putstr(const char *str);
int	my_str_hasnum(char const *str);
int	my_strncmp(char const *s1, char const *s2, int n);
char	**my_strtotabpt(char *str, const char *delim);
char	*my_strcat(char *dest, char const *src);
char	*my_strdup(char const *src);
char	*my_strncpy(char *dest, char const *src, int n);
char	my_strlen(const char *str);

#endif
