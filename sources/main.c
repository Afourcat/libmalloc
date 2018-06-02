/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** test file
*/

#include <string.h>
#include <stdlib.h>

int main(void)
{
	char *allo = malloc(sizeof(char) * (strlen("Salut ca va ?") + 10));
	char *test = malloc(10);

	free(allo);
	free(test);
	return 0;
}
