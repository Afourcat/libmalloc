/*
** EPITECH PROJECT, 2017
** calloc.c
** File description:
** calloc function
*/

void *calloc(size_t nmen, size_t size)
{
	void *ptr = malloc(nmen * size);

	write(1, "CALLOC\n", 6);
	memset(ptr, 0, nmen * size);
	return ptr;
}
