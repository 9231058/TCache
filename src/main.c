/*
 * In The Name Of God
 * ========================================
 * [] File Name : main.c
 *
 * [] Creation Date : 27-02-2015
 *
 * [] Last Modified : Sun 01 Mar 2015 10:31:45 AM IRST
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

uint64_t cache_size = 32;
uint64_t k_way = 1;
uint64_t block_size = 2;
uint64_t sets; 

static void on_hit(uint64_t tag, uint64_t index)
{
	printf("HIT : %lu\n", tag * sets + index);
}

static void on_miss(uint64_t tag, uint64_t index)
{
	printf("MISS : %lu\n", tag * sets + index);
}

static void on_replace(uint64_t tag, uint64_t index)
{
	printf("REPLACE : %lu\n", tag * sets + index);
}

int main(int argc, char *argv[])
{
	set_replace_function(fifo);	
	set_on_hit_function(on_hit);
	set_on_miss_function(on_miss);
	set_on_replace_function(on_replace);
	set_block_size(block_size);

	sets = (cache_size / block_size) / k_way;

	struct cache *cache;

	cache = cache_new(k_way, sets);

	int i = 0;
	for (i = 0; i < 25; i++) {
		uint64_t address;
		scanf("%lu", &address);
		cache_find(cache, address);
	}
	cache_print(cache);
}
