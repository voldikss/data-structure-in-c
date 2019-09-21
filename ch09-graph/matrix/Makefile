.PHONY: run clean
run: a.out graph.dat
	./a.out < graph.dat
a.out:
	gcc main.c graph.c topsort.c -o a.out
clean:
	rm -f *.o
	rm -f *.out
