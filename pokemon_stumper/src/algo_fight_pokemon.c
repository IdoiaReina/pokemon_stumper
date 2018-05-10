/*
** EPITECH PROJECT, 2017
** algo_fight_pokemon.c
** File description:
** algo for fight two pokemon
*/

#include <stdbool.h>
#include "pokemon.h"

int	victory_condition(pokemon_t *poke)
{
	if (poke->poke_one->health <= 0) {
		printf("%s is KO\n", poke->poke_one->name);
		printf("%s wins the fight!\n", poke->poke_two->name);
		free_pokemon(poke);
		exit (0);
	}
	else if (poke->poke_two->health <= 0) {
		printf("%s is KO\n", poke->poke_two->name);
		printf("%s wins the fight!\n", poke->poke_one->name);
		free_pokemon(poke);
		exit (0);
	}
	return (0);
}

void	fight_first_poke_one(pokemon_t *poke)
{
	while (true) {
		poke_one_attack(poke);
		poke_two_attack(poke);
	}
}

void	fight_first_poke_two(pokemon_t *poke)
{
	while (true) {
		poke_two_attack(poke);
		poke_one_attack(poke);
	}
}

int	block_while_infinity_fight(pokemon_t *poke)
{
	if (poke->poke_one->defense >= poke->poke_two->attack &&
		poke->poke_two->defense >= poke->poke_one->attack) {
		printf("Each pokemon's defense is higher than the other's");
		printf(" attack!\nTheir fight will never end!\n");
		printf("There's no winner!\n");
		free_pokemon(poke);
		exit (0);
	}
	return (0);
}

int	fight(pokemon_t *poke)
{
	block_while_infinity_fight(poke);
	if (poke->poke_one->speed >= poke->poke_two->speed)
		fight_first_poke_one(poke);
	else if (poke->poke_two->speed > poke->poke_one->speed)
		fight_first_poke_two(poke);
	return (0);
}
