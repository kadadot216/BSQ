/*
** EPITECH PROJECT, 2018
** redirect.c
** File description:
** Redirect file
*/

#include "cr_redirect.h"

void	redirect_all_std(void)
{
	cr_redirect_stdout();
	cr_redirect_stderr();
}
