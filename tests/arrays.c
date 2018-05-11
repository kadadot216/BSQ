/*
** EPITECH PROJECT, 2018
** arrays.c
** File description:
** Test file for array functions
*/

#include <criterion/criterion.h>
#include "cr_redirect.h"
#include "my.h"
#include "array.h"

Test(array_1d, test1, .init=redirect_all_std)
{
	char	my_array[] = "Hello";
	char	*output = "H\ne\nl\nl\no\n";

	array_1d_print_chars(my_array);
	cr_assert_stdout_eq_str(output, "");
}

Test(array_1i, test1, .init=redirect_all_std)
{
	int	my_array[] = {1, 2, 3, 4, 5};
	char	*output = "1\n2\n3\n4\n5\n";

	array_1d_print_ints(my_array, 5);
	cr_assert_stdout_eq_str(output, "");
}

Test(array_1dsum, test1)
{
	int	my_array[] = {1, 2, 3, 4, 5};
	int	sum = 15;

	cr_assert_eq(sum, array_1d_sum(my_array, 5));
}

Test(array_2dsum, test1)
{
	int	my_array[3][5] = {{1, 2, 3, 4, 5}, {1, 2, 3, 4, 5},
		{1, 2, 3, 4, 5}};
	int	cmp = 45;
	int	sum = 0;
	int	*pt[3];

	pt[0] = my_array[2];
	pt[1] = my_array[1];
	pt[2] = my_array[2];
	sum = array_2d_sum(pt, 3, 5);
	cr_assert_eq(cmp, sum);
}

Test(array_2dhowmany, test1)
{
	int	my_array[3][5] = {{1, 2, 3, 4, 5}, {1, 2, 3, 4, 5},
		{1, 2, 3, 4, 5}};
	int	*pt[3];

	pt[0] = my_array[2];
	pt[1] = my_array[1];
	pt[2] = my_array[2];
	cr_assert_eq(array_2d_how_many(pt, 3, 5, 3), 3);
}
