/*
 * In The Name Of God
 * ========================================
 * [] File Name : main.c
 *
 * [] Creation Date : 27-02-2015
 *
 * [] Last Modified : Fri 27 Feb 2015 11:55:40 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <stdio.h>

#include "cache.h"

int main(int argc, char *argv[])
{
	struct cache *cache = cache_new(1, 2);
	cache_find(cache, 0);
	cache_find(cache, 0);
	cache_find(cache, 1);
	cache_find(cache, 0);
	cache_find(cache, 1);
}
