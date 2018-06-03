/*
** EPITECH PROJECT, 2017
** realloc.c
** File description:
** realloc
*/

#include "alloc.h"

void *realloc(void *ptr, size_t size)
{
#ifdef DEBUG
	write(1, "REALLOC\n", 8);
#endif
	void *void_etoile = malloc(size);
	struct data *info = NULL;

	if (!ptr)
		return void_etoile;
	if (!void_etoile)
		return NULL;
	info = (struct data *) ptr - 1;
#ifdef DEBUG
	putnbr(info->size);
	write(1, "\n", 1);
#endif
	memcpy(void_etoile, ptr, (info)->size);
	free(ptr);
	return void_etoile;
}
