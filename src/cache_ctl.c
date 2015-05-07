/*
 * In The Name Of God
 * ========================================
 * [] File Name : cache_ctl.c
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

#include "set.h"
#include "cache_ctl.h"

static void (*replace)(struct set *set, uint64_t tag, uint64_t index);
static void (*on_replace)(uint64_t tag, uint64_t index);
static void (*on_miss)(uint64_t tag, uint64_t index);
static void (*on_hit)(uint64_t tag, uint64_t index);
static uint64_t block;

void set_replace_function(void (*new_replace)(struct set *set,
			uint64_t tag, uint64_t index))
{
	replace = new_replace;
}

void use_replace_function(struct set *set, uint64_t tag, uint64_t index)
{
	replace(set, tag, index);
}

void set_block_size(uint64_t block_size)
{
	block = block_size;
}

void use_block_size(uint64_t *address)
{
	if (block)
		*address /= block;
}

void set_on_replace_function(void (*new_replace)(uint64_t tag, uint64_t index))
{
	on_replace = new_replace;
}
void use_on_replace_function(uint64_t tag, uint64_t index)
{
	on_replace(tag, index);
}

void set_on_hit_function(void (*new_hit)(uint64_t tag, uint64_t index))
{
	on_hit = new_hit;
}
void use_on_hit_function(uint64_t tag, uint64_t index)
{
	on_hit(tag, index);
}

void set_on_miss_function(void (*new_miss)(uint64_t tag, uint64_t index))
{
	on_miss = new_miss;
}
void use_on_miss_function(uint64_t tag, uint64_t index)
{
	on_miss(tag, index);
}
