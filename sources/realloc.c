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
	struct data *info = NULL;

	if (!ptr)
		return void_etoile;
	if (!void_etoile)
		return NULL;
	info = (struct data *) ptr - 1;
	putnbr(info->size);
	write(1, "\n", 1);
	memcpy(void_etoile, ptr, (info)->size);
	free(ptr);
	return void_etoile;
}
