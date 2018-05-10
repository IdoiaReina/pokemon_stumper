/*
** EPITECH PROJECT, 2017
** fight_pokemon.c
** File description:
** attacks pokemons
*/

#include <time.h>
#include <stdbool.h>
#include "pokemon.h"

int	rand_number(int n)
{
	int random = 0;

	random = (rand() % (n));
	return (random);
}

int	poke_one_attack(pokemon_t *poke)
{
	int	attacks	= rand_number(poke->poke_one->attack);
	int	blocks	= poke->poke_two->defense;
	int	loses	= (attacks - poke->poke_two->defense);
	int 	health	= poke->poke_two->health;

	if (attacks <= poke->poke_two->defense)
		loses = 0;
	poke->poke_two->health = (poke->poke_two->health - loses);
	if (poke->poke_two->health <= 0)
		health = 0;
	printf("%s attacks for %d damage\n", poke->poke_one->name, attacks);
	printf("%s blocks %d damage\n", poke->poke_two->name, blocks);
	printf("%s loses %d health (%d left)\n",
	poke->poke_two->name, loses, health);
	victory_condition(poke);
	return (0);
}

int	poke_two_attack(pokemon_t *poke)
{
	int	attacks	= rand_number(poke->poke_two->attack);
	int	blocks	= poke->poke_one->defense;
	int	loses	= (attacks - poke->poke_one->defense);
	int 	health	= poke->poke_one->health;

	if (attacks <= poke->poke_one->defense)
		loses = 0;
	poke->poke_one->health = (poke->poke_one->health - loses);
	if (poke->poke_one->health <= 0)
		health = 0;
	printf("%s attacks for %d damage\n", poke->poke_two->name, attacks);
	printf("%s blocks %d damage\n", poke->poke_one->name, blocks);
	printf("%s loses %d health (%d left)\n",
	poke->poke_one->name, loses, health);
	victory_condition(poke);
	return (0);
}
