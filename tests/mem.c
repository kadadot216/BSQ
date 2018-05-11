/*
** EPITECH PROJECT, 2018
** mem.c
** File description:
** memory functions test files
*/

#include <criterion/criterion.h>
#include "my.h"
#include "mem.h"

Test(mem_alloc, test1)
{
	char	*a = "String a";
	char	*b = "String b";
	char	*c = mem_alloc(a, b);

	cr_assert_str_eq(c, "String aString b");
}

Test(mem_alloc2darr, test1)
{
	char	**a = mem_alloc_2d_array(4, 4);

	my_memset(a[0], 'a', 3);
	cr_assert_eq(my_strlen(a[0]), 3);
}

Test(mem_array2d_dup, test1)
{
	char	*a[] = {"aaa", "aaa", "aaa", 0};

	char	**b = mem_dup_2d_array(a, 3, 3);

	cr_assert_str_eq(a[0], b[0]);
}
