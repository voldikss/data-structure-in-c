.PHONY: run clean
run: list.dat
	@gcc test_list.c list.c -o a.out && ./a.out < ./list.dat
clean:
	rm -f *.o
	rm -f *.out
