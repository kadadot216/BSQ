/*
** EPITECH PROJECT, 2018
** fsys.h
** File description:
** Header file for fsys.c
*/

#ifndef __FSYS_H__
#define __FSYS_H__

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFF_SIZE (4096)

int	fs_open_file(char const *filepath);
void	fs_understand_return_of_read(int fd, char *buffer, int size);

#endif
