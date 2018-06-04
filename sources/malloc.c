/*
** EPITECH PROJECT, 2017
** malloc.c
** File description:
** malloc function
*/

#include "alloc.h"

void *alloc(size_t size, struct data **free, struct data **used)
{
	struct data *new = get_free_space(free, size);

	if (new) {
#ifdef DEBUG
		write(1, "Not pushing break.\n", 20);
#endif
		new->size = size;
		return (void *) (add_elem(used, new) + 1);
	} else {
#ifdef DEBUG
		write(1, "Push break.\n", 12);
#endif
		new = sbrk(0);
		sbrk(size + sizeof(struct data));
		new->size = size;
		return (void *) (add_elem(used, new) + 1);
	}
	return 0;
}

void *malloc(size_t size)
{
#ifdef DEBUG
	write(1, "MALLOC\n", 7);
	putnbr(ALIGN(size));
	write(1, "\n", 1);
#endif
	void *ptr = sbrk(0);
	struct data *free = get_free(NULL);
	struct data *used = get_used(NULL);

	if (ptr == (void *) -1)
		return NULL;
	ptr = alloc(ALIGN(size), &free, &used);
	get_free(&free);
	get_used(&used);
	return ptr;
}
