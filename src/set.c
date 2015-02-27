/*
 * In The Name Of God
 * ========================================
 * [] File Name : set.c
 *
 * [] Creation Date : 27-02-2015
 *
 * [] Last Modified : Fri 27 Feb 2015 10:10:55 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <stdint.h>
#include <stdlib.h>

#include "block.h"
#include "set.h"

struct set *set_new(uint64_t k_way)
{
	struct set *new = malloc(sizeof(struct set));
	int i = 0;

	new->k_way = k_way;
	new->next = NULL;

	struct block *base;
	struct block *block;

	for (i = 0; i < k_way; i++) {
		if (!i) {
			base = block_new();
			block = base;
		} else {
			block->next = block_new();
			block = block->next;
		}
	}
	new->head = base;
	return new;
}

void set_find(struct set *set, uint64_t tag, uint64_t index)
{

}

void set_delete(struct set *set)
{
}
