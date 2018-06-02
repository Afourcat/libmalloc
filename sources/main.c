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
	size_t size_1 = 100000;
	size_t size_2 = 200000;
	size_t size_3 = 300000;
	size_t size_4 = 400000;
	char *test1 = malloc(size_1);
	char *test2 = malloc(size_2);
	char *test3 = malloc(size_3);
	char *test4 = malloc(size_4);

	memset(test1, 0, size_1);
	memset(test2, 0, size_2);
	memset(test3, 0, size_3);
	memset(test4, 0, size_4);
	free(test4);
	test4 = malloc(1000);
	memset(test4, 0, 1000);
	test4 = realloc(test4, 1200);
	memset(test4, 0, 1200);
	free(test4);
	test4 = calloc(120, 1);
	memset(test4, 0, 120);
	free(test4);
	test4 = realloc(test4, 1200);
	test4 = realloc(test4, 1400);
	test4 = realloc(test4, 1600);
	memset(test4, 0, 1600);
	free(test4);
	return 0;
}
