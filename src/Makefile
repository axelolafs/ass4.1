.PHONY: all
all: hello

.PHONY: hello
hello: main.cpp
	g++ -o hello main.cpp

.PHONY: install
install:
	mkdir -p bin
	cp -p hello bin

.PHONY: clean
clean:
	rm -f hello
