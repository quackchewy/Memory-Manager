/* Ying Kit Chui, Alex Chiang
 * CSE 374 HW 6
 * 5/12/2018
 *
 * print_heap.c
 *
 * */

#include <inttypes.h>
#include <stdio.h>
#include "mem.h"
#include "mem_impl.h"

extern MemNode* freeRoot;
extern int nodeSize;

void print_heap(FILE* f) {
    MemNode* freeNode = freeRoot;
    while(freeNode != NULL) {
        fprintf(f, "%p, %#010x, %lu, used=%d\n", freeNode + nodeSize, 
                freeNode->numBytes, freeNode->numBytes, freeNode->used);
        freeNode = freeNode->next;
    }
}
