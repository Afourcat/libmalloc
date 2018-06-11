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
	memset(test1, 0, 100);
	free(test1);
	test1 = malloc(30);
	return 0;
}
