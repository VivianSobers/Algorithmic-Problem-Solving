CC = gcc
CFLAGS = -Wall -g

all: dap hash

dap: dap.c
	$(CC) $(CFLAGS) -o dap dap.c

hash: hash.c
	$(CC) $(CFLAGS) -o hash hash.c

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

# Experimental comparison
test6:
	@echo "===================================="
	@echo "Large Dataset Performance Comparison"
	@echo "===================================="
	@echo ""
	@echo "▶ DAP Result"
	@/usr/bin/time -f "Elapsed Time: %e seconds" ./dap tests/test6.txt
	@echo ""
	@echo "▶ Hash Result"
	@/usr/bin/time -f "Elapsed Time: %e seconds" ./hash tests/test6.txt

clean:
	rm -f dap hash