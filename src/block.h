/*
 * In The Name Of God
 * ========================================
 * [] File Name : block.h
 *
 * [] Creation Date : 27-02-2015
 *
 * [] Last Modified : Fri 27 Feb 2015 09:39:47 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#ifndef BLOCK_H
#define BLOCK_H

#include <stdint.h>

/*
 * Cache block structure
 * 64      0
 * +-------+
 * |  tag  |
 * +-------+
*/
struct block {
	uint64_t tag;
	struct block *next;
};

struct block *block_new(uint64_t tag, uint64_t index);
void block_delete(struct block *block);

#endif
