/*
 * In The Name Of God
 * ========================================
 * [] File Name : block.c
 *
 * [] Creation Date : 27-02-2015
 *
 * [] Last Modified : Sun 01 Mar 2015 10:25:15 AM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

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

void block_print(struct block *block)
{
	if (block->valid)
		printf("%16lx", block->tag);
	else
		printf("       --       ");
}
