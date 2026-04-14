CC = gcc
CFLAGS = -Wall -g -std=c99

all: frac_greedy dp01

frac_greedy: frac_greedy.c knapsack.h
	$(CC) $(CFLAGS) -o frac_greedy frac_greedy.c

dp01: dp01.c knapsack.h
	$(CC) $(CFLAGS) -o dp01 dp01.c

test1:
	./frac_greedy tests/test1.txt
	./dp01 tests/test1.txt

test2:
	./frac_greedy tests/test2.txt
	./dp01 tests/test2.txt

test3:
	./frac_greedy tests/test3.txt
	./dp01 tests/test3.txt

test4:
	./frac_greedy tests/test4.txt
	./dp01 tests/test4.txt

test5:
	./frac_greedy tests/test5.txt
	./dp01 tests/test5.txt

test6:
	./frac_greedy tests/test6.txt
	./dp01 tests/test6.txt

test: test1 test2 test3 test4 test5 test6

clean:
	rm -f frac_greedy dp01