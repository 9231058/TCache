/*
 * In The Name Of God
 * ========================================
 * [] File Name : cache_ctl.c
 *
 * [] Creation Date : 28-02-2015
 *
 * [] Last Modified : Sat 28 Feb 2015 12:18:47 AM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <stdint.h>

#include "set.h"
#include "cache_ctl.h"

static void (*replace)(struct set *set, uint64_t tag, uint64_t index);

void set_replace_function(void (*new_replace)(struct set *set, uint64_t tag, uint64_t index))
{
	replace = new_replace;
}

void use_replace_function(struct set *set, uint64_t tag, uint64_t index)
{
	replace(set, tag, index);
}
