/*
** EPITECH PROJECT, 2018
** pokem
** File description:
** pokemon
*/

#ifndef POKEMON_H_
#define POKEMON_H_

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <dirent.h>
#include <time.h>

typedef struct s_poke_two
{
	char *name;
	int attack;
	int defense;
	int speed;
	int health;
} poke_two_t;

typedef struct s_poke_one
{
	char *name;
	int attack;
	int defense;
	int speed;
	int health;
} poke_one_t;

typedef struct s_entities
{
	char *name_one;
	char *name_two;
	poke_two_t *poke_two;
	poke_one_t *poke_one;
}pokemon_t;

/*INIT*/
pokemon_t *init_pokemon(char **av);
void search_pokeplayers(char **pokefile, int y, pokemon_t *poke);
void print_pokefile(char **pokefile, int y);
void read_pokemons_dir(pokemon_t *poke);

char **str_to_word_array(char *buf, char a, int lines, int len);

int my_str_compare(char *src, char *to_compare);
void free_pokemon(pokemon_t *poke);

/*fight*/
int rand_number(int n);
int poke_one_attack(pokemon_t *poke);
int poke_two_attack(pokemon_t *poke);

/*algo_fight_pokemon.c*/
int victory_condition(pokemon_t *poke);
void fight_first_poke_one(pokemon_t *poke);
void fight_first_poke_two(pokemon_t *poke);
int block_while_infinity_fight(pokemon_t *poke);
int fight(pokemon_t *poke);

#endif /* !POKEMON_H_ */
