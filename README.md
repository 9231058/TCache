# TCache
## Introduction
TCache is simple cache simulator can customized
with use of function pointers callbacks and it can simulate
multi layer caching.  
My personal motivation to write this project was that I want to use OOD in C which is COOL.  
This project written originally as Homework problem of computer architecture
course in Amirkabir university.
## Function Callbacks
### Reporting Function
```c
/*
 * On Replace function callback
*/
void set_on_replace_function(void (*new_replace)(uint64_t tag, uint64_t index));

void use_on_replace_function(uint64_t tag, uint64_t index);
```
```c
/*
 * On Hit function callback
*/
void set_on_hit_function(void (*new_hit)(uint64_t tag, uint64_t index));

void use_on_hit_function(uint64_t tag, uint64_t index);
```
```c
/*
 * On Miss function callback
*/
void set_on_miss_function(void (*new_miss)(uint64_t tag, uint64_t index));

void use_on_miss_function(uint64_t tag, uint64_t index);
```
### Cache Behavioral Functions
```c
/*
 * Replacing function callback
*/
void set_replace_function(void (*new_replace)(
	struct set *set, uint64_t tag, uint64_t index));

void use_replace_function(struct set *set, uint64_t tag, uint64_t index);
```
```c
/*
 * Set block size function callback
*/
void set_block_size(uint64_t block_size);

void use_block_size(uint64_t * address);
```


