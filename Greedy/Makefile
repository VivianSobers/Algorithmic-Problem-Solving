CC = gcc
CFLAGS = -Wall -g

all: efs

efs: efs.c
	$(CC) $(CFLAGS) -o efs efs.c

test1:
	./efs tests/test1.txt

test2:
	./efs tests/test2.txt

test3:
	./efs tests/test3.txt

test4:
	./efs tests/test4.txt

test5:
	./efs tests/test5.txt

test: test1 test2 test3 test4 test5

clean:
	rm -f efs