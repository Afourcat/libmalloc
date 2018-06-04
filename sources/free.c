/*
** EPITECH PROJECT, 2017
** free.c
** File description:
** free functions
*/

#include "alloc.h"

void slice_memory(struct data **prev, struct data *tmp, size_t size)
{
	long int new_int = (long int)(tmp);
	new_int += sizeof(struct data) + size;
	struct data *new = (struct data *) new_int;

	new->next = tmp->next;
	new->size = ALIGN(tmp->size - size);
	*prev = new;
#ifdef DEBUG
	write(1, "Split block\n", 12);
#endif
}

struct data *get_free_space(struct data **head, size_t size)
{
	struct data *tmp = *head;
	struct data **prev = head;

	while (tmp != NULL) {
		if (tmp->size >= size) {
#ifdef DEBUG
			write(1, "Free space\n", 11);
#endif
	//		if (tmp->size > ALIGN(size + sizeof(struct data) + 10)) {
	//			slice_memory(prev, tmp, size);
	//			tmp->size = size;
	//		} else {
#ifdef DEBUG
				write(1, "Nice size\n", 10);
#endif
			*prev = tmp->next;
		//	}
			return tmp;
		}
		prev = &tmp->next;
		tmp = tmp->next;
	}
#ifdef DEBUG
	write(1, "No free space\n", 14);
#endif
	return NULL;
}

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
	if (!finded) {
#ifdef DEBUG
		write(1, "Invalid free !\n", 15);
#endif
	}
	get_free(&free);
	get_used(&used);
}
