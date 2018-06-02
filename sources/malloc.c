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
		write(1, "NEW\n", 4);
		new->size = size;
		return (void *) (add_elem(used, new) + sizeof(struct data));
	} else {
		write(1, "PUSH\n", 5);
		new = sbrk(0);
		sbrk(size + sizeof(struct data));
		new->size = size;
		return (void *) (add_elem(used, new) + sizeof(struct data));
	}
	return 0;
}

void *malloc(size_t size)
{
	void *ptr = sbrk(0);
	struct data *free = get_free(NULL);
	struct data *used = get_used(NULL);

	write(1, "MALLOC\n", 7);
	if (ptr == (void *) -1)
		return NULL;
	ptr = alloc(size, &free, &used);
	get_free(free);
	get_used(used);
	return ptr;
}
