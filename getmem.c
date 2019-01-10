/* Ying Kit Chui, Alex Chiang
 * CSE 374 HW 6
 * 5/12/2018
 *
 * getmem.c
 *
 * */

#include <inttypes.h>
#include <stdlib.h>
#include "mem.h"
#include "mem_impl.h"

#define MEM_SIZE 16000

extern MemNode* freeRoot;
extern int nodeSize;

void* getmem(uintptr_t size) {
    if (size <= 0) {
        return NULL;
    }

    if (size % 16 != 0) {
        size = ((size / 16) + 1) * 16;
    }

    //printf("initial node size is %lu\n", sizeof(MemNode));
    // Maybe extern this nodeSize variable?
    if (sizeof(MemNode) % 16 == 0) {
        nodeSize = sizeof(MemNode);
    } else {
        nodeSize = ((sizeof(MemNode) / 16) + 1) * 16;
    }

    printf("size after conversion is %lu\n", size);
    //printf("node size after conversion is %d\n", nodeSize);

    // Creates the entire allotted memory when there is none.
    if (freeRoot == NULL) {
        printf("root is null\n");
        //16000 + size in case size is greater than 16000
        freeRoot = (MemNode*) malloc(MEM_SIZE + size);

        // freeRoot is not a part of the allocated 16k
        // it is the pointer to the node before the 16k
        freeRoot->numBytes = MEM_SIZE + size - nodeSize;
        freeRoot->next = NULL;
        //freeRoot->used = 0;
    }

    MemNode* freeNode = freeRoot;

    int allocated = 0;
    int reachedEnd = 0;
    while (freeNode != NULL && allocated == 0 && reachedEnd == 0) { 
        // if the current node has enough bytes to make
        // the requested node 
        if (freeNode->numBytes >= size + nodeSize && freeNode->used == 0) {
            MemNode* remainder = (uintptr_t) freeNode + size + nodeSize;
            remainder->numBytes = freeNode->numBytes - size - nodeSize;
            remainder->next = freeNode->next;
            //remainder->used = 0;

            // at this point the freeNode is no longer "free"
            freeNode->numBytes = size;
            freeNode->next = remainder;
            freeNode->used = 1;
            allocated = 1;
        }
        // current node does not have enough bytes and has a next node
        else if (freeNode->next != NULL) {
            freeNode = freeNode->next;
        // if next node is null then you have reached the end
        } else {
            reachedEnd = 1;
        }
    }

    // case when you go thru whole heap and there is still no node large enough,
    // at this point, your freeNode is NULL at the end of the allocated chunk
    // and allocated should be 0 if we still haven't found space.
    if (allocated == 0) {
        printf("had to add a new chunk of mem\n");
        // points at front of new chunk
        freeNode->next = (MemNode*) malloc(MEM_SIZE + size);
        freeNode = freeNode->next;
        freeNode->numBytes = size;
        freeNode->used = 1;
        
        MemNode* remainder = (uintptr_t) freeNode + size + nodeSize;
        remainder->numBytes = MEM_SIZE - 2 * nodeSize;
        remainder->next = NULL;
        //remainder->used = 0;

        freeNode->next = remainder;
    }

    printf("getmem returns %p\n", freeNode + nodeSize);
    printf("numBytes is %lu\n", freeNode->numBytes);
    printf("next node is %p\n", freeNode->next + nodeSize);
    //printf("used status is %i\n\n", freeNode->used);
    
    // Return the address of the node plus the nodeSize
    // to get a pointer to the requested space.
    return freeNode + nodeSize;
}







