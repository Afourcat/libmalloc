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
	char *test1 = malloc(100);
	free(test1);
	test1 = malloc(10);
	memset(test1, 0, 10);
	test1 = malloc(40);
	memset(test1, 0, 40);
	test1 = malloc(10000);
	memset(test1, 0, 10000);
	return 0;
}
