/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "pokemon.h"

void arguments(int ac)
{
	char *wrong = "Wrong Arguments.\n";

	if (ac != 3) {
		write(2, wrong, strlen(wrong));
		exit (84);
	}
}

int main(int ac, char **av)
{
	pokemon_t *poke;

	arguments(ac);
	poke = init_pokemon(av);
	srand(time(NULL));
	read_pokemons_dir(poke);
	fight(poke);
	free_pokemon(poke);
	return (0);
}