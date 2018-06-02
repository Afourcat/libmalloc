/*
** EPITECH PROJECT, 2017
** utils.c
** File description:
** utils function for malloc project
*/

#include "alloc.h"

struct data *get_free(struct data **set)
{
	static struct data *free = NULL;

	if (set != NULL)
		free = *set;
	return free;
}

struct data *get_used(struct data **set)
{
	static struct data *used = NULL;

	if (set != NULL)
		used = *set;
	return used;
}

struct data *add_elem(struct data **head, struct data *elem)
{
	if (*head == NULL) {
		write(1, "Adding on null\n", 15);
		*head = elem;
		elem->next = NULL;
		write(1, "\n", 1);
		return *head;
	}
	write(1, "Adding normaly\n", 15);
	elem->next = *head;
	*head = elem;
	write(1, "\n", 1);
	return *head;
}

struct data *get_free_space(struct data **head, size_t size)
{
	struct data *tmp = *head;
	struct data **prev = head;

	while (tmp != NULL) {
		if (tmp->size >= size) {
			write(1, "Free space\n", 11);
			*prev = tmp->next;
			return tmp;
		}
		prev = &tmp->next;
		tmp = tmp->next;
	}
	write(1, "No free space\n", 14);
	return NULL;
}

void my_putchar(char c)
{
	write(1, &c, 1);
}

size_t putnbr(long int nb)
{
	int modulo;

	modulo = 0;
	if (nb <= 9 && nb >= 0)
		my_putchar(nb + '0');
	if (nb > 9) {
		modulo = nb % 10;
		putnbr(nb / 10);
		my_putchar(modulo + '0');
	}
	return 0;
}
