/*
 * In The Name Of God
 * ========================================
 * [] File Name : set.h
 *
 * [] Creation Date : 27-02-2015
 *
 * [] Last Modified : Fri 27 Feb 2015 09:22:16 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#ifndef SET_H
#define SET_H
#include <stdint.h>

#include "block.h"

struct set {

	uint64_t size;
	uint64_t k_way;
	struct set *next;
	struct block *head;
}

struct set *set_new(uint64_t k_way

#endif
