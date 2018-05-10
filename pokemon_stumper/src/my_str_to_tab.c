/*
** EPITECH PROJECT, 2018
** str to work array
** File description:
** same
*/

#include <stdio.h>
#include <stdlib.h>

char **complete_tab_blank(char **tab, int y, int lines)
{
	int i = 0;

	for (i = y; i < lines; i++) {
		tab[i] = NULL;
	}
	return (tab);
}

char **str_to_word_array(char *buf, char a, int lines, int len)
{
	int x = 0;
	int y = 0;
	int i = 0;
	char **tab = malloc(sizeof(char *) * lines);

	while (buf[i] != '\0') {
		x = 0;
		tab[y] = malloc(sizeof(char) * len);
		while (buf[i] != '\0' && buf[i] != a) {
			tab[y][x] = buf[i];
			x += 1;
			i += 1;
		}
		if (buf[i] != '\0')
			i += 1;
		tab[y][x] = '\0';
		y += 1;
	}
	tab = complete_tab_blank(tab, y, lines);
	return (tab);
}