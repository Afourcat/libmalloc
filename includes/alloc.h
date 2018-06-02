/*
** EPITECH PROJECT, 2017
** alloc.h
** File description:
** alloc
*/

#ifndef _ALLOC_H_
#	define _ALLOC_H_
#	include <stdlib.h>
#	include <unistd.h>

typedef struct data data_t;

static const size_t SIZE = sizeof(void *);

struct data {
	size_t size;
	struct data *next;
};

struct data *get_free(struct data *set);
struct data *get_used(struct data *set);
struct data *add_elem(struct data **head, struct data *elem);
struct data *get_free_space(struct data **head, size_t size);

#endif /* _ALLOC_H_ */
