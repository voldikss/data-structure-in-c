.PHONY: run clean
run: stack.dat
	@gcc test_stack.c stack.c -o a.out && ./a.out < ./stack.dat
clean:
	rm -f *.o
	rm -f *.out
