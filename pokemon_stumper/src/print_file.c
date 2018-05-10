/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "pokemon.h"

int my_print(char **buf, int y, int i)
{
	while (buf[y][i] != ';' && buf[y][i] != '\0') {
		printf("%c", buf[y][i]);
		i += 1;
	}
	i += 1;
	return (i);
}

void print_pokefile(char **pokefile, int y)
{
	int i = 0;

	while (pokefile[y][0] == '#')
		y++;
	printf("Pokemon ");
	i = my_print(pokefile, y, i);
	printf(" has ");
	i = my_print(pokefile, y, i);
	printf(" attack, ");
	i = my_print(pokefile, y, i);
	printf(" defense, ");
	i = my_print(pokefile, y, i);
	printf(" speed and ");
	i = my_print(pokefile, y, i);
	printf(" health\n");
	if (pokefile[y + 1] != NULL)
		print_pokefile(pokefile, y + 1);
}