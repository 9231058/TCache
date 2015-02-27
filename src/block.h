/*
 * In The Name Of God
 * ========================================
 * [] File Name : block.h
 *
 * [] Creation Date : 27-02-2015
 *
 * [] Last Modified : Fri 27 Feb 2015 09:01:58 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#ifndef BLOCK_H
#define BLOCK_H

#include <stdint.h>

/*
 * Cache block structure
 * 127     64      0
 * +-------+-------+
 * | Tag   | index |
 * +-------+-------+
*/
struct block {
	uint64_t tag;
	uint64_t index;
	struct block *next;
};

struct block *block_new(uint64_t tag, uint64_t index);
void block_delete(struct block *block);

#endif
