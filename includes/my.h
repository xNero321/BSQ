/*
** EPITECH PROJECT, 2017
** Graph programming
** File description:
** Prototypess
*/

#ifndef LIST_FUNCTION_INCLUDED
#define LIST_FUNCTION_INCLUDED

void	read_map(char const *filepath, char *buff, int size);
void	nb_col(map_t *map, char *buff);
int	my_getnbr(char *nbr);
void	nb_lign(map_t *map, char *buff);
char	**copy_buffer_to_array(int col, int lign, char *buff);
void 	display_BSQ(map_t *map);
map_t	parsing_map(map_t map);
int	check_square(map_t *map, int x, int y);
int	find_pos_and_square(map_t *map, int x, int y);


#endif /*LIST_FUNCTION_INCLUDED*/
