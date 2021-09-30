.PHONY: all
all: hello mutex_example

.PHONY: hello
hello: main.cpp
	g++ -o hello main.cpp

.PHONY: mutex_example
mutex_example: mutex_example.cpp
	g++ -lpthread mutex_example.cpp ../include/mutex.cpp ../include/mutex.h -o mutex_example

.PHONY: clean
clean:
	rm -f hello
	rm -f mutex_example
