/*
 * In The Name Of God
 * ========================================
 * [] File Name : fifo.c
 *
 * [] Creation Date : 28-02-2015
 *
 * [] Last Modified : Sat Feb 28 13:00:16 2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <stdint.h>

#include "set.h"
#include "fifo.h"


void fifo(struct set *set, uint64_t tag, uint64_t index)
{
	struct block *base;
	int i;

	base = set->head;
	for (i = 0; i < set->k_way; i++) {
		if (base->next) {
			base->tag = base->next->tag;
			base->access = base->next->access;
			base->valid = base->next->valid;
		} else {
			base->tag = tag;
			base->valid = 1;
			base->access = 1;
		}
	}
}
