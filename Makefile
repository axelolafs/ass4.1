.PHONY: all
all: hello mutex_example

.PHONY: hello
hello: src/main.cpp
	g++ -o hello src/main.cpp

.PHONY: mutex_example
mutex_example: src/mutex_example.cpp
	g++ -I include -l pthread src/mutex_example.cpp include/*.cpp include/*.h -o mutex_example

.PHONY: clean
clean:
	rm -f hello
	rm -f mutex_example
