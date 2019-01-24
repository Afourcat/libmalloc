/*
** EPITECH PROJECT, 2017
** free.c
** File description:
** free functions
*/

#include "alloc.h"

extern pthread_mutex_t mutex;

struct data *split_bloc(struct data *tmp, size_t size)
{
#ifdef DEBUG
	write(1, "Split\n", 6);
#endif
	size_t new_tmp_size = ALIGN(tmp->size - size - sizeof(struct data));
	size_t address = (size_t)(tmp);
	address += ALIGN(new_tmp_size + sizeof(struct data));
	struct data *new = (struct data *) address;

	new->next = NULL;
	tmp->size = new_tmp_size;
	return new;
}

// TODO: Optimize
struct data *get_free_space(struct data **head, size_t size)
{
	struct data *tmp = *head;
	struct data **prev = head;

	while (tmp != NULL) {
		if (tmp->size >= size) {
			if (size < ALIGN(tmp->size - size - sizeof(struct data)) + 16) {
				return split_bloc(tmp, size);;
			} else {
				*prev = tmp->next;
			}
			return tmp;
		}
		prev = &tmp->next;
		tmp = tmp->next;
	}
	return NULL;
}

void free(void *ptr)
{
#ifdef DEBUG
	write(1, "FREE\n", 5);
#endif
	pthread_mutex_lock(&mutex);
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
	pthread_mutex_unlock(&mutex);
}
