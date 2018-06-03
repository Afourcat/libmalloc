/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** test file
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	char *test = malloc(1);
	char *test1 = NULL;
	int *call = calloc(1, sizeof(int));

	for (int i = 2; i < 10000; ++i) {
		test1 = malloc(10);
		test = realloc(test, i);
		memset(test1, 1, 10);
		memset(test, 0, i);
		memset(call, 1, (i - 1) * sizeof(int));
		free(NULL);
		free(call);
		free(test1);
		call = calloc(i, sizeof(int));
	}
	free(test);
	return 0;
}
