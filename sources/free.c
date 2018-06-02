/*
** EPITECH PROJECT, 2017
** free.c
** File description:
** free functions
*/

#include "alloc.h"

void free(void *ptr)
{
	write(1, "FREE\n", 5);
	struct data *free = get_free(NULL);
	struct data *used = get_used(NULL);
	struct data **prev = &used;
	struct data *tmp = used;
	bool finded = false;

	while (tmp) {
		if (tmp + sizeof(struct data) == ptr) {
			write(1, "Valid free !\n", 13);
			*prev = tmp->next;
			add_elem(&free, tmp);
			finded = true;
			break;
		}
		write(1, "!\n", 2);
		prev = &tmp->next;
		tmp = tmp->next;
	}
	if (!finded)
		write(1, "Invalid free !\n", 15);
	get_free(&free);
	get_used(&used);
}
