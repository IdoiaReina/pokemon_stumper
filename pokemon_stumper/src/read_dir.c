/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "pokemon.h"

char *str_cpy_path(char *name)
{
	char *path = "pokecfg/";
	unsigned int i = 0;
	unsigned int index = 0;
	char *final_path = malloc(sizeof(char) * 100);

	for (i = 0; i < strlen(path); i++) {
		final_path[i] = path[i];
	}
	for (index = 0; index < strlen(name); index++) {
		final_path[index + i] = name[index];
	}
	final_path[index + i] = '\0';
	return (final_path);
}

void verif_pokefile(char **pokefile, int y)
{
	int i = 0;
	int verif = 0;

	while (pokefile[y][0] == '#')
		y += 1;
	while (pokefile[y][i] != '\0') {
		if (pokefile[y][i] == ';')
			verif += 1;
		i += 1;
	}
	if (pokefile[y + 1] != NULL)
		verif_pokefile(pokefile, y + 1);
	if (verif != 4)
		exit (84);
}

void read_poke_file(char *name, pokemon_t *poke)
{
	char *buf = malloc(sizeof(char) * 10000);
	char *path = str_cpy_path(name);
	int fd = open(path, O_RDONLY);
	char **pokefile = NULL;
	int i = 0;

	if (fd != -1) {
		buf[read(fd, buf, 1000)] = '\0';
		pokefile = str_to_word_array(buf, '\n', 300, 300);
		verif_pokefile(pokefile, 0);
		print_pokefile(pokefile, 0);
		search_pokeplayers(pokefile, 0, poke);
	}
	for (i = 0; i < 300; i++)
		free(pokefile[i]);
	free(pokefile);
	free(path);
	free(buf);
}

void read_pokemons_dir(pokemon_t *poke)
{
	struct dirent *read_dir;
	DIR *dir = NULL;

	if ((dir = opendir("pokecfg")) == NULL)
		exit (84);
	while ((read_dir = readdir(dir)) != NULL) {
		if (read_dir->d_name[0] != '.')
			read_poke_file(read_dir->d_name, poke);
	}
	free (dir);
}