/*
** EPITECH PROJECT, 2017
** realloc.c
** File description:
** realloc
*/

#include "alloc.h"

void *realloc(void *ptr, size_t size)
{
	write(1, "REALLOC\n", 8);
	void *etoile = malloc(size);

	memmove(etoile, ptr, size);
	return etoile;
}
