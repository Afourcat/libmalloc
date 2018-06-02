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
	void *void_etoile = malloc(size);
	
	if (!void_etoile)
		return NULL;
	memcpy(void_etoile, ptr, size);
	free(ptr);
	return void_etoile;
}
