/*
** EPITECH PROJECT, 2017
** free.c
** File description:
** free functions
*/

#include "alloc.h"

void free(void *ptr)
{
#ifdef DEBUG
	write(1, "FREE\n", 5);
#endif
	struct data *free = get_free(NULL);
	struct data *used = get_used(NULL);
	struct data **prev = &used;
	struct data *tmp = used;
	bool finded = false;

	if (!ptr) {
#ifdef DEBUG
		write(1, "Null free\n", 10);
#endif
		return;
	}
	while (tmp) {
		if (tmp + 1 == ptr) {
#ifdef DEBUG
			write(1, "Valid free !\n", 13);
#endif
			*prev = tmp->next;
			add_elem(&free, tmp);
			finded = true;
			break;
		}
#ifdef DEBUG
		write(1, "!\n", 2);
#endif
		prev = &tmp->next;
		tmp = tmp->next;
	}
	if (!finded)
#ifdef DEBUG
		write(1, "Invalid free !\n", 15);
#endif
	get_free(&free);
	get_used(&used);
}
