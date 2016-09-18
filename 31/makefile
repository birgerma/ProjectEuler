CFLAGS=-Wall -g -lm

run: compile
	./$(main) $(arg)
compile: clean
	gcc $(main).c -o $(main) -lm
clean:
	rm -f $(main)
