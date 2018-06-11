/*
** EPITECH PROJECT, 2017
** calloc.c
** File description:
** calloc function
*/

#include "alloc.h"

void *calloc(size_t nmemb, size_t size)
{
#ifdef DEBUG
	write(1, "CALLOC\n", 7);
#endif
	size_t bytes = nmemb * size;
	void *ptr = malloc(bytes);

	if (!ptr)
		return NULL;
	return memset(ptr, 0, bytes);
}