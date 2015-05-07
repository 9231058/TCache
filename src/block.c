/*
 * In The Name Of God
 * ========================================
 * [] File Name : block.c
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
