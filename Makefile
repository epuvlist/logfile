CC = gcc
PROG = logfile
OPTS = -Wall

all: $(PROG).o test_logfile

$(PROG).o: $(PROG).c
	$(CC) $(OPTS) -c $(PROG).c -o$(PROG).o

test_logfile: test_logfile.c $(PROG).o
	$(CC) $(OPTS) test_logfile.c logfile.o -otest_logfile

clean:
	rm test_logfile *.o
