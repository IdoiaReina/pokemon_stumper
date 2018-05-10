/*
** EPITECH PROJECT, 2018
** init
** File description:
** init
*/

#include "pokemon.h"

pokemon_t *init_pokemon(char **av)
{
	pokemon_t *obj = (pokemon_t *)malloc(sizeof(pokemon_t));

	if (obj == NULL)
		exit(84);
	obj->poke_one = (poke_one_t *)malloc(sizeof(poke_one_t));
	if (obj->poke_one == NULL)
		exit(84);
	obj->poke_two = (poke_two_t *)malloc(sizeof(poke_two_t));
	if (obj->poke_two == NULL)
		exit(84);
	obj->name_one = av[1];
	obj->name_two = av[2];
	return (obj);
}

void free_pokemon(pokemon_t *poke)
{
	free(poke->poke_one->name);
	free(poke->poke_two->name);
	free(poke->poke_one);
	free(poke->poke_two);
	free(poke);
}