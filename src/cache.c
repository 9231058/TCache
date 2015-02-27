/*
 * In The Name Of God
 * ========================================
 * [] File Name : cache.c
 *
 * [] Creation Date : 27-02-2015
 *
 * [] Last Modified : Fri 27 Feb 2015 09:57:37 PM IRST
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
	
	struct set *base;
	struct set *set;

	for (i = 0; i < sets; i++) {
		if (!i) {
			base = set_new(k_way);
			set = base;
		} else {
			set->next = set_new(k_way);
			set = set->next;
		}
	}
	new->head = base;
	return new;
}

void cache_find(struct cache *c, uint64_t address)
{
	int i = 0;
	uint64_t set_n = address % c->sets;
	uint64_t tag = address / c->sets;
	struct set *set = c->head;

	for (i = 0; i < set_n; i++)
		set = set->next;
	set_find(set, tag, set_n);	
}
