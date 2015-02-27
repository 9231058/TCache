/*
 * In The Name Of God
 * ========================================
 * [] File Name : main.c
 *
 * [] Creation Date : 27-02-2015
 *
 * [] Last Modified : Sat 28 Feb 2015 12:35:30 AM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <stdio.h>

#include "lru.h"
#include "cache.h"
#include "cache_ctl.h"

int main(int argc, char *argv[])
{
	set_replace_function(lru);

	struct cache *cache;

	cache = cache_new(1, 2);
	cache_find(cache, 0);
	cache_find(cache, 0);
	cache_find(cache, 1);
	cache_find(cache, 0);
	cache_find(cache, 1);
	cache_find(cache, 2);
	cache_find(cache, 2);
}
