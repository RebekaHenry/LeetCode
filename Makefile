LDFLAGS = -g -Wall -pthread -std=c11

all: clean
	gcc -o reverse reverse.c $(LDFLAGS)

clean:
	rm -rf reverse