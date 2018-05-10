/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "pokemon.h"

char *send_item_name(char **pokefile, int y)
{
	char *item = malloc(sizeof(char) * 100);
	int j = 0;
	int i = 0;

	while (pokefile[y][i] != ';' && pokefile[y][i] != '\0') {
		item[j] = pokefile[y][i];
		i++;
		j++;
	}
	i++;
	item[j] = '\0';
	return (item);
}

int send_item_stats(char **pokefile, int y, int ptr)
{
	char *item = malloc(sizeof(char) * 100);
	int j = 0;
	int number = 0;
	int i = 0;

	while (j != ptr) {
		if (pokefile[y][i] == ';')
			j += 1;
		i++;
	}
	j = 0;
	while (pokefile[y][i] != ';' && pokefile[y][i] != '\0') {
		item[j] = pokefile[y][i];
		i++;
		j++;
	}
	item[j] = '\0';
	number = atoi(item);
	free(item);
	return (number);
}

void player_one(pokemon_t *poke, char **pokefi, int y)
{
	while (pokefi[y][0] == '#')
		y++;
	poke->poke_one->name = send_item_name(pokefi, y);
	poke->poke_one->attack = send_item_stats(pokefi, y, 1);
	poke->poke_one->defense = send_item_stats(pokefi, y, 2);
	poke->poke_one->speed = send_item_stats(pokefi, y, 3);
	poke->poke_one->health = send_item_stats(pokefi, y, 4);
}

void player_two(pokemon_t *poke, char **pokefi, int y)
{
	while (pokefi[y][0] == '#')
		y++;
	poke->poke_two->name = send_item_name(pokefi, y);
	poke->poke_two->attack = send_item_stats(pokefi, y, 1);
	poke->poke_two->defense = send_item_stats(pokefi, y, 2);
	poke->poke_two->speed = send_item_stats(pokefi, y, 3);
	poke->poke_two->health = send_item_stats(pokefi, y, 4);
}

void search_pokeplayers(char **pokefile, int y, pokemon_t *poke)
{
	char *name = malloc(sizeof(char) * 100);
	int i = 0;

	while (pokefile[y][0] == '#')
		y++;
	while (pokefile[y][i] != ';') {
		name[i] = pokefile[y][i];
		i++;
	}
	name[i] = '\0';
	if (my_str_compare(name, poke->name_one) == 0)
		player_one(poke, pokefile, y);
	if (my_str_compare(name, poke->name_two) == 0)
		player_two(poke, pokefile, y);
	if (pokefile[y + 1] != NULL)
		search_pokeplayers(pokefile, y + 1, poke);
	free(name);
}