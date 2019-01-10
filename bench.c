/* Ying Kit Chui, Alex Chiang
 * CSE 374 HW 6
 * 5/12/2018
 *
 * bench.c
 *
 * */

#include <stdlib.h>
#include "mem.h"

#define FILENAME "fish sticks"

int main(int argc, char** argv) {
    getmem(159);

    getmem(12);

    getmem(19990);

    getmem(1585);

    getmem(15600);
    
    FILE* file = fopen(FILENAME, "w");
    print_heap(file);
    fclose(file);
    return EXIT_SUCCESS;
}
