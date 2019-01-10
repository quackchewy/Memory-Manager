/* Ying Kit Chui, Alex Chiang
 * CSE 374 HW 6
 * 5/12/2018
 *
 * test.c
 *
 * */

#include <stdlib.h>
#include "mem.h"

extern MemNode* freeRoot;

int main(int argc, char** argv) {
    freeRoot = (MemNode*) 0xABCDEF;
    printf("entered test\n");
    getmem(1000);
    //printf("%p\n", freeRoot);
    return EXIT_SUCCESS;
}
