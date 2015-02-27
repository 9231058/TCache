/*
 * In The Name Of God
 * ========================================
 * [] File Name : set.h
 *
 * [] Creation Date : 27-02-2015
 *
 * [] Last Modified : Fri 27 Feb 2015 09:57:11 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#ifndef SET_H
#define SET_H
#include <stdint.h>

#include "block.h"

struct set {
	uint64_t k_way;
	struct set *next;
	struct block *head;
};

struct set *set_new(uint64_t k_way);
void set_find(struct set *set, uint64_t tag, uint64_t index);
void set_delete(struct set *set);

#endif
