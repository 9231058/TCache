/*
 * In The Name Of God
 * ========================================
 * [] File Name : block.c
 *
 * [] Creation Date : 27-02-2015
 *
 * [] Last Modified : Fri 27 Feb 2015 09:39:53 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <stdint.h>
#include <stdlib.h>

#include "block.h"

struct block *block_new(uint64_t tag, uint64_t set)
{
	struct block *new = malloc(sizeof(struct block));
	new->tag = tag;
	new->next = NULL;
	return new;
}

void block_delete(struct block *block)
{
	free(block);
}
