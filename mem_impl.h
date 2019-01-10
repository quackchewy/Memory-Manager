/* Ying Kit Chui, Alex Chiang
 * CSE 374 HW 6
 * 5/12/2018
 *
 * mem_impl.h
 *
 * */

// Checks that the blocks are in ascending order by address; 
// that block sizes are positive numbers and larger than the minimum
// block size; that blocks do not contain addresses that overlap with
// other blocks; and that any blocks that are touching are combined.
// The program will terminate when any of these tests fail.
void check_heap();

int nodeSize;
