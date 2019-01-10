bench: bench.o mem_utils.o getmem.o freemem.o get_mem_stats.o print_heap.o
	gcc -Wall -std=c11 -g -o bench bench.o mem_utils.o getmem.o freemem.o get_mem_stats.o print_heap.o

bench.o: bench.c mem.h
	gcc -Wall -std=c11 -g -c bench.c

mem_utils.o: mem_utils.c mem_impl.h
	gcc -Wall -std=c11 -g -c mem_utils.c

getmem.o: getmem.c mem.h mem_utils.c mem_impl.h
	gcc -Wall -std=c11 -g -c getmem.c

freemem.o: freemem.c mem.h mem_utils.c mem_impl.h
	gcc -Wall -std=c11 -g -c freemem.c

get_mem_stats.o: get_mem_stats.c mem.h mem_utils.c mem_impl.h
	gcc -Wall -std=c11 -g -c get_mem_stats.c

print_heap.o: print_heap.c mem.h mem_utils.c mem_impl.h
	gcc -Wall -std=c11 -g -c print_heap.c

clean: 
	rm -f *.o *~ bench
