/*
 * In The Name Of God
 * ========================================
 * [] File Name : lru.c
 *
 * [] Creation Date : 28-02-2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2015 Parham Alvani.
*/
#include <stdint.h>

void lru(struct set *set, uint64_t tag, uint64_t index)
{
	struct block *base;
	int i;
	uint64_t min_val = -1;
	uint64_t min_inx;

	base = set->head;
	for (i = 0; i < set->k_way; i++) {
		if (min_val > base->access) {
			min_val = base->access;
			min_inx = i;
		}
		base = base->next;
	}

	base = set->head;
	for (i = 0; i < min_inx; i++)
		base = base->next;

	base->tag = tag;
	base->access = 1;
	base->valid = 1;
}
