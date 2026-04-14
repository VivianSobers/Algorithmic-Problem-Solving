CC = gcc
CFLAGS = -Wall -g

all: dap

dap: dap.c
	$(CC) $(CFLAGS) -o dap dap.c

test1:
	./dap tests/test1.txt

test2:
	./dap tests/test2.txt

test3:
	./dap tests/test3.txt

test4:
	./dap tests/test4.txt

test5:
	./dap tests/test5.txt

test: test1 test2 test3 test4 test5

clean:
	rm -f dap