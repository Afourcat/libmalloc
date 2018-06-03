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
		write(1, "Not pushing break.\n", 20);
		new->size = size;
		new->next = NULL;
		return (void *) (add_elem(used, new) + 1);
	} else {
		write(1, "Push break.\n", 12);
		new = sbrk(0);
		sbrk(size + sizeof(struct data));
		new->size = size;
		return (void *) (add_elem(used, new) + 1);
	}
	return 0;
}

void *malloc(size_t size)
{
	write(1, "MALLOC\n", 7);
	void *ptr = sbrk(0);
	struct data *free = get_free(NULL);
	struct data *used = get_used(NULL);

	if (ptr == (void *) -1)
		return NULL;
	ptr = alloc(size, &free, &used);
	get_free(&free);
	get_used(&used);
	return ptr;
}
