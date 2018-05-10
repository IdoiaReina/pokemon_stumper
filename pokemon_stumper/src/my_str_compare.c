/*
** EPITECH PROJECT, 2018
** lib
** File description:
** str_compare
*/

int my_str_compare(char *src, char *to_compare)
{
	int i = 0;

	while (src[i] != '\0') {
		if (src[i] == to_compare[i])
			i++;
		else if (src[i] == (to_compare[i] + 32))
			i++;
		else if (src[i] == (to_compare[i] - 32))
			i++;
		else
			return (1);
	}
	return (0);
}
