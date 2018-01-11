/*
** EPITECH PROJECT, 2017
** my_get_nbr.c
** File description:
** get a number
*/

#include <stdlib.h>

int my_getnbr(char *nbr)
{
	int var = 0;
	int neg = 1;
	int i = 0;

	if (nbr == 0)
		return (0);
	while ((*nbr < 47 || *nbr > 58) && *nbr != 0) {
		nbr++;
		i++;
	}
	if (i > 0 && *(nbr - 1) == 45)
		neg = -1;
	while (*nbr != 0 && *nbr >= '0' && *nbr <= '9') {
		var = var * 10;
		var = var + *nbr - 48;
		nbr++;
	}
	var = var * neg;
	return (var);
}
