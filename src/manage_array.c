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

void	nb_lign(map_t *map, char *buff)
{
	char tmp[6];
	int i = 0;

	while (buff[i] != '\n') {
		tmp[i] = buff[i];
		i++;
	}
	map->lign = my_getnbr(tmp);
}

void	nb_col(map_t *map, char *buff)
{
	int i = 0;
	int j = 0;

	while (buff[i] != '\n') {
		i++;
	}
	while (buff[i + 1] != '\n') {
		i++;
		j++;
	}
	map->col = j;
}

char	**copy_buffer_to_array(int col, int lign, char *buff)
{
	int i = 0;
	int j = 0;
	int x = 0;
	int tmp = 0;
	char **map = malloc(sizeof(char*) * lign + 1);

	while (buff[j] != '\n') {
		j++;
	}
	j++;
	tmp = j;
	j = 0;
	for (; i < lign; i++) {
		map[i] = malloc(sizeof(char) * col + 1);
		for (; j <= col; j++) {
				map[i][j] = buff[tmp];
				tmp++;
		}
		j--;
		map[i][j] = '\0';
		j = 0;
	}
	return (map);
}

void 	display_BSQ(map_t *map)
{
	int i = 0;
	int j = 0;

	while (i != map->lign) {
		while (j != map->col) {
			if ((i > map->pos_x && i <= map->pos_x + map->size) &&
			(j > map->pos_y && j <= map->pos_y + map->size))
				while (j <= map->pos_y + map->size) {
					my_putchar('x');
					j++;
				}
			else {
				my_putchar(map->arr_2d[i][j]);
				j++;
			}
		}
		my_putchar('\n');
		j = 0;
		i++;
	}
}
