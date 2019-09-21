.PHONY: run clean
run: queue.dat
	@gcc test_queue.c queue.c -o a.out && ./a.out < ./queue.dat
clean:
	rm -f *.o
	rm -f *.out
