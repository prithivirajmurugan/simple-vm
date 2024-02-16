CC = clang
CFLAGS = -Wall -Wextra -g -std=c11

all: simple

test: simple
	./simple