/*
 * In The Name Of God
 * ========================================
 * [] File Name : set.c
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

#include "cache_ctl.h"

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

	base = set->head;
	for (i = 0; i < set->k_way; i++) {
		if (base->valid && base->tag == tag) {
			use_on_hit_function(tag, index);
			base->access++;
			return;
		}
		base = base->next;
	}

	use_on_miss_function(tag, index);

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

	use_on_replace_function(tag, index);

	use_replace_function(set, tag, index);
}

void set_print(struct set *set)
{
	int i;
	struct block *base;

	base = set->head;
	for (i = 0; i < set->k_way; i++) {
		printf("\t");
		block_print(base);
		base = base->next;
	}
}

void set_delete(struct set *set)
{
}
