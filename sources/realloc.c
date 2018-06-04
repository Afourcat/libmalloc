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
	struct data *info = NULL;
	void *void_etoile = NULL;

	if (!ptr) {
		void_etoile = malloc(size);
		return void_etoile;
	}
	if (((struct data *) ptr - 1)->size > ALIGN(size))
		return ptr;
	void_etoile = malloc(size);
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
