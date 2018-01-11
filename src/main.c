/*
** EPITECH PROJECT, 2017
** CPE
** File description:
** BSQ
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../includes/structure.h"
#include "../includes/my.h"
#include "../lib/my/my.h"

int	main(int argc, char **argv)
{
	struct stat size_s;
	char *buff;
	off_t size = 0;
	map_t map;
	int i = 0;

	stat(argv[1], &size_s);
	size = size_s.st_size;
	buff = malloc(sizeof(char) * size);
	read_map(argv[1], buff, size);
	nb_lign(&map, buff);
	nb_col(&map, buff);
	map.arr_2d = copy_buffer_to_array(map.col, map.lign, buff);
	map = parsing_map(map);
	map.pos_y--;
	map.pos_x--;
	display_BSQ(&map);
	return (0);
}

void	read_map(char const *filepath, char *buff, int size)
{
	int fd;
	int readed = 0;

	fd = open(filepath, O_RDONLY);
	readed = read(fd, buff, size);
	if (fd == -1) {
		exit (84);
	}
	close(fd);
}
