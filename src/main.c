/*
 * In The Name Of God
 * ========================================
 * [] File Name : main.c
 *
 * [] Creation Date : 27-02-2015
 *
 * [] Last Modified : Sat Feb 28 20:24:09 2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <stdio.h>
#include <stdint.h>

#include "lru.h"
#include "fifo.h"
#include "cache.h"
#include "cache_ctl.h"

int main(int argc, char *argv[])
{
	set_replace_function(fifo);
	set_block_size(2);

	struct cache *cache;

	cache = cache_new(1, 16);

	int i = 0;
	for (i = 0; i < 25; i++) {
		uint64_t address;
		scanf("%llu", &address);
		cache_find(cache, address);
	}
	cache_print(cache);
}
