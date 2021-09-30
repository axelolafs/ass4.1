.PHONY: all
all: hello

.PHONY: hello
hello: hello.cpp
	g++ -o hello hello.cpp

.PHONY: install
install:
	mkdir -p bin
	cp -p hello bin

.PHONY: clean
clean:
	rm -f hello
