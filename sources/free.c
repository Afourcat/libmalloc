/*
** EPITECH PROJECT, 2017
** free.c
** File description:
** free functions
*/

#include "alloc.h"

void free(void *ptr)
{
	struct data *free = get_free(NULL);
	struct data *used = get_used(NULL);
	struct data *tmp = used;
	struct data **prev = NULL;

	write(1, "FREE\n", 5);
	while (tmp != NULL) {
		if (tmp == ptr) {
			write(1, "FIND\n", 5);
			(*prev)->next = tmp->next;
			add_elem(&free, tmp);
		}
		write(1, "NOT FIND\n", 9);
		*prev = tmp;
		tmp = tmp->next;
	}
	get_free(free);
	get_used(used);
}
