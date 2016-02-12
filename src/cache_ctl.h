/*
 * In The Name Of God
 * ========================================
 * [] File Name : cache_ctl.h
 *
 * [] Creation Date : 28-02-2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2015 Parham Alvani.
*/
#ifndef CACHE_CTL_H
#define CACHE_CTL_H

#include <stdint.h>

#include "set.h"

/*
 * Replacing function callback
*/
void set_replace_function(void (*new_replace)(
	struct set *set, uint64_t tag, uint64_t index));

void use_replace_function(struct set *set, uint64_t tag, uint64_t index);

/*
 * On Replace function callback
*/
void set_on_replace_function(void (*new_replace)(uint64_t tag, uint64_t index));

void use_on_replace_function(uint64_t tag, uint64_t index);

/*
 * On Hit function callback
*/
void set_on_hit_function(void (*new_hit)(uint64_t tag, uint64_t index));

void use_on_hit_function(uint64_t tag, uint64_t index);

/*
 * On Miss function callback
*/
void set_on_miss_function(void (*new_miss)(uint64_t tag, uint64_t index));

void use_on_miss_function(uint64_t tag, uint64_t index);

/*
 * Set block size function callback
*/
void set_block_size(uint64_t block_size);

void use_block_size(uint64_t * address);

#endif
