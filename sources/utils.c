/*
** EPITECH PROJECT, 2017
** utils.c
** File description:
** utils function for malloc project
*/

#include "alloc.h"

struct data *get_free(struct data *set)
{
	static struct data *free = NULL;

	if (set != NULL)
		free = set;
	return free;
}

struct data *get_used(struct data *set)
{
	static struct data *used = NULL;

	if (set != NULL)
		used = set;
	return used;
}

struct data *add_elem(struct data **head, struct data *elem)
{
	if (*head == NULL) {
		write(1, "NULL\n", 5);
		*head = elem;
		elem->next = NULL;
		return *head;
	}
	write(1, "NOT NULL\n", 9);
	elem->next = *head;
	*head = elem;
	return *head;
}

struct data *get_free_space(struct data **head, size_t size)
{
	struct data *tmp = *head;
	struct data **prev = NULL;

	while (tmp != NULL) {
		if (tmp->size >= size) {
			write(1, "FREE SPACE\n", 11);
			(*prev)->next = tmp->next;
			return tmp;
		}
		prev = &tmp;
		tmp = tmp->next;
	}
	return NULL;
}
