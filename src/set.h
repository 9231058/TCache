/*
 * In The Name Of God
 * ========================================
 * [] File Name : set.h
 *
 * [] Creation Date : 27-02-2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2015 Parham Alvani.
*/
#ifndef SET_H
#define SET_H

#include <stdint.h>

#include "block.h"

struct set {
	uint64_t k_way;
	struct set *next;
	struct block *head;
};

struct set *set_new(uint64_t k_way);

void set_find(struct set *set, uint64_t tag, uint64_t index);

void set_delete(struct set *set);

void set_print(struct set *set);

#endif
