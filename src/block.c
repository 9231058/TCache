/*
 * In The Name Of God
 * ========================================
 * [] File Name : block.c
 *
 * [] Creation Date : 27-02-2015
 *
 * [] Last Modified : Fri 27 Feb 2015 10:06:45 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <stdint.h>
#include <stdlib.h>

#include "block.h"

struct block *block_new(void)
{
	struct block *new = malloc(sizeof(struct block));
	
	new->valid = 0;
	new->access = 0;
	new->next = NULL;
	return new;
}

void block_delete(struct block *block)
{
	free(block);
}
