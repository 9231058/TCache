/*
 * In The Name Of God
 * ========================================
 * [] File Name : cache.h
 *
 * [] Creation Date : 27-02-2015
 *
 * [] Last Modified : Fri 27 Feb 2015 11:37:06 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#ifndef CACHE_H
#define CACHE_H
#include <stdint.h>

#include "set.h"

enum replacement_policy {FIFO, LRU};

/*
 * cache sturcture:
 *
 * +---------+
 * |  cache  |
 * +---------+
 *      |
 * +---------+ +---------+ +---------+
 * |  set #1 |-| block #1|-| block #2|- .....
 * +---------+ +---------+ +---------+
 *      |
 * +---------+ +---------+ +---------+
 * |  set #2 |-| block #1|-| block #2|- .....
 * +---------+ +---------+ +---------+
 *     .
 *     .
 *     .
*/
struct cache {
	struct set *head;
	uint64_t sets;
};

struct cache *cache_new(uint64_t k_way, uint64_t sets);
void cache_find(struct cache *c, uint64_t address);
void cache_delete(struct cache *c);

#endif
