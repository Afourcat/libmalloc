/*
** EPITECH PROJECT, 2017
** calloc.c
** File description:
** calloc function
*/

#include "alloc.h"

void *calloc(size_t nmemb, size_t size)
{
	write(1, "CALLOC\n", 7);
	void *ptr = malloc(nmemb * size);
	size_t i = 1;

	if (!ptr)
		return NULL;
	while (++i < nmemb)
		
	return ptr;
}
