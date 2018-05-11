/*
** EPITECH PROJECT, 2018
** t_fsys.c
** File description:
** Unistesting file for file descriptor
*/

#include <criterion/criterion.h>
#include "cr_redirect.h"
#include "fsys.h"

Test(fsys, att1, .init=redirect_all_std)
{
	fs_open_file("./tests/file_rdo");
	cr_assert_stdout_eq_str("SUCCESS\n");
}

Test(fsys, att2, .init=redirect_all_std)
{
	fs_open_file("./tests/file_nordo");
	cr_assert_stdout_eq_str("FAILURE\n");
}
