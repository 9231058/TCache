/*
 * In The Name Of God
 * ========================================
 * [] File Name : cache.c
 *
 * [] Creation Date : 27-02-2015
 *
 * [] Last Modified : Fri 27 Feb 2015 09:17:16 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <stdint.h>
#include <stdlib.h>

#include "cache.h"
#include "block.h"

struct cache *cache_new(uint64_t k_way, uint64_t sets)
{
	struct cache *new = malloc(sizeof(struct cache));
	
	new->head = block_new(0, 0);
	new->size = 0;
	new->sets = sets;
	new->k_way = k_way;
	new->on_replace = NULL;
	new->on_miss = NULL;
	new->on_hit = NULL;
	return new;
}

void cache_find(struct cache *c,
		uint64_t tag, uint64_t index)
{
	int i = 0;
	struct block *b;

	b = c->head;
	for (i = 0; i < c->size; i++) {
		if (b->tag == tag && b->index == index) {
			if (c->on_hit)
				c->on_hit(tag, index);
		}
		if (b->tag != tag && b->index == index) {
			b->tag = tag;
			if (c->on_replace)
				c->on_replace(tag, index);
		}
	}
}
