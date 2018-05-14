/*
** EPITECH PROJECT, 2018
** my_getnbrn.c
** File description:
** Returns a string as a number
*/

#include "my.h"

int	my_getnbrn(char const *str, int n)
{
	int	sum = 0;
	int	i = 0;
	char	sign = 0;

	sum = 0;
	while (str[i] == '-' || str[i] == '+') {
		sign = str[i];
		str++;
	}
	while (str[i] != '\0' && (i < n) && str[i] >= '0' && str[i] <= '9') {
		if (sum > 214748364)
			return (0);
		if (sign == '+' && sum == 214748364 && str[i] > 7)
			return (0);
		if (sign == '-' && sum == 214748364 && str[i] > 8)
			return (0);
		sum = (sum * 10 + (str[i] - '0'));
		i++;
	}
	return ((sign == '-' ? (- sum) : (sum)));
}
