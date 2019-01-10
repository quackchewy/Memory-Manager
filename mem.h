 /* Ying Kit Chui, Alex Chiang
  * CSE 374 HW 6
  * 5/12/2018
  *
  * mem.h
  *
  * */

#include <inttypes.h>
#include <stdio.h>

// Consists of a size field in bytes and a pointer to 
// another MemNode.
typedef struct MemNode {
    uintptr_t numBytes;
    struct MemNode* next;
    int used;
} MemNode;

// Pointer to the beginning of our free list.
MemNode* freeRoot;

// Takes in a size, allocates memory of that size (in multiples of 16 bytes), 
// and returns a pointer to the allocated memory.
void* getmem(uintptr_t size);

// Takes in a pointer and frees up any allocated memory at that pointer.
void freemem(void* p);

// Takes in 3 pointers and stores stats about memory management
// at those pointers: the total amount of memory allocated; the
// total amount of free memory; and the total number of blocks
// in the free list. 
void get_mem_stats(uintptr_t* total_size, 
        uintptr_t* total_free, uintptr_t* n_free_blocks);

// Takes a pointer to an output file and prints the size and address of 
// each block in the free list to that file.
void print_heap(FILE* f);
