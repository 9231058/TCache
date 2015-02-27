/*
 * In The Name Of God
 * ========================================
 * [] File Name : cache.h
 *
 * [] Creation Date : 27-02-2015
 *
 * [] Last Modified : Fri 27 Feb 2015 09:17:18 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#ifndef CACHE_H
#define CACHE_H
#include <stdint.h>

#include "block.h"

/*
 * cache sturcture, it use @on_replace, @on_miss and @on_hit
 * function pointer inorder to customize behaviour on replace,
 * miss and hit.
*/
struct cache {
	struct block *head;
	uint64_t size;
	uint64_t sets;
	uint64_t k_way;
	void (*on_replace)(uint64_t tag, uint64_t index);
	void (*on_miss)(uint64_t tag, uint64_t index);
	void (*on_hit)(uint64_t tag, uint64_t index);
};

struct cache *cache_new(uint64_t k_way, uint64_t sets);
void cache_find(struct cache *c,
		uint64_t tag, uint64_t index);

#endif
