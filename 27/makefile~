CFLAGS=-Wall -g

run: compile
	./$(main) $(arg)
compile: clean
	gcc $(main).c -o $(main)
clean:
	rm -f $(main)
