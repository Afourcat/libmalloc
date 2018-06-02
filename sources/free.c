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

	if (!ptr) {
		write(1, "Null free\n", 10);
		return;
	}
	while (tmp) {
		write(1, "\ntmp : ", 7);
		putnbr(tmp + 1);
		write(1, "\nptr : ", 7);
		putnbr(ptr);
		write(1, "\n", 1);
		if (tmp + 1 == ptr) {
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
