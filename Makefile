CC = gcc
PROG = logfile

logfile.o: logfile.c
	$(CC) -c $(PROG).c

test_logfile: test_logfile.c $(PROG).o
	$(CC) test_logfile.c logfile.o -otest_logfile

clean:
	rm test_logfile *.o
