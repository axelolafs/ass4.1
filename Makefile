.PHONY: all
all: hello mutex_example

hello: src/main.cpp
	g++ -o hello src/main.cpp

mutex_example: src/mutex_example.o include/increment.o include/decrement.o
	g++ -I include -l pthread src/mutex_example.o include/*.o -o mutex_example

mutex_example.o: src/mutex_example.cpp
	g++ -c src/mutex_example.cpp
	mv mutex_example.o src

decrement.o: include/decrement.cpp include/decrement.h
	g++ -c include/decrement.cpp
	mv decrement.o include

increment.o: include/increment.cpp include/increment.h 
	g++ -c include/increment.cpp
	mv increment.o include

.PHONY: clean
clean:
	rm -f hello
	rm -f mutex_example
	rm -f include/*.o
	rm -f src/*.o
