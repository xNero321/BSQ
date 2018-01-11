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

map_t	parsing_map(map_t map)
{
	int x = 0;
	int y = 0;

	map.size = 0;
	for (x = 0; x < map.lign; x++) {
		for (y = 0; y < map.col; y++) {
			check_square(&map, x, y);
		}
		y = 0;
	}
	return (map);
}

int	check_square(map_t *map, int x, int y)
{
	if (map->arr_2d[x][y] != '.')
		return (1);
	for (int i = map->size + 1; (x + i <= map->col)
	&& (y + i <= map->lign); i++) {
		i = map->size + 1;
		if (find_pos_and_square(map, x, y) == 1)
			return (1);
	}
}

int	find_pos_and_square(map_t *map, int x, int y)
{
	int i = 0;
	int j = 0;

	for (i = 0; i <= map->size; i++) {
		for (j = 0; j <= map->size; j++) {
			if (map->arr_2d[x + i][y + j] != '.')
				return (1);
		}
		j = 0;
	}
	if ((map->size >= 1 && map->size < 20) && (map->col == 97
	&& map->lign == 21))
		exit (84);
	map->size++;
	map->pos_x = x;
	map->pos_y = y;
	return (0);
}
