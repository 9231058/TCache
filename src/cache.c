/*
 * In The Name Of God
 * ========================================
 * [] File Name : cache.c
 *
 * [] Creation Date : 27-02-2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2015 Parham Alvani.
*/
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#include "cache.h"
#include "common.h"
#include "cache_ctl.h"
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
	ulog("Address: %lu", address);
	use_block_size(&address);

	int i = 0;
	uint64_t set_n = address % c->sets;
	uint64_t tag = address / c->sets;
	struct set *set = c->head;

	for (i = 0; i < set_n; i++)
		set = set->next;
	set_find(set, tag, set_n);
}

void cache_print(struct cache *c)
{
	uint64_t i;
	struct set *set = c->head;

	for (i = 0; i < c->sets; i++) {
		printf("set #%16lx:", i);
		set_print(set);
		printf("\n");
		set = set->next;
	}
}
