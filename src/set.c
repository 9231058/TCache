/*
 * In The Name Of God
 * ========================================
 * [] File Name : set.c
 *
 * [] Creation Date : 27-02-2015
 *
 * [] Last Modified : Sat 28 Feb 2015 01:01:52 AM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#include "cache_ctl.h"
#include "block.h"
#include "common.h"
#include "set.h"

struct set *set_new(uint64_t k_way)
{
	struct set *new = malloc(sizeof(struct set));
	int i = 0;

	new->k_way = k_way;
	new->next = NULL;

	struct block *base;
	struct block *block;

	for (i = 0; i < k_way; i++) {
		if (!i) {
			base = block_new();
			block = base;
		} else {
			block->next = block_new();
			block = block->next;
		}
	}
	new->head = base;
	return new;
}

void set_find(struct set *set, uint64_t tag, uint64_t index)
{
	int i = 0;
	struct block *base;

	ulog("============== In set %lld:", index);

	base = set->head;
	for (i = 0; i < set->k_way; i++) {
		if (base->valid && base->tag == tag) {
			ulog("HIT %llu", tag);
			base->access++;
			return;
		}
		base = base->next;
	}

	ulog("MISS %llu", tag);

	base = set->head;
	for (i = 0; i < set->k_way; i++) {
		if (!base->valid) {
			base->tag = tag;
			base->valid = 1;
			base->access = 1;
			return;
		}
		base = base->next;
	}

	ulog("REPLACE %llu", tag);

	use_replace_function(set, tag, index);
}

void set_delete(struct set *set)
{
}
