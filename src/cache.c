/*
 * In The Name Of God
 * ========================================
 * [] File Name : cache.c
 *
 * [] Creation Date : 27-02-2015
 *
 * [] Last Modified : Fri 27 Feb 2015 09:44:27 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <stdint.h>
#include <stdlib.h>

#include "cache.h"
#include "set.h"

struct cache *cache_new(uint64_t k_way, uint64_t sets)
{
	struct cache *new;
	int i = 0;
	
	new = malloc(sizeof(struct cache));
	new->sets = sets;
	
	
	for (i = 0; i < sets; i++) {
		struct set *set = set_new(k_way);
	}

	return new;
}

void cache_find(struct cache *c, uint64_t address)
{
	int i = 0;
	struct block *b;
}
