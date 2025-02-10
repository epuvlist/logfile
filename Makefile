CC = gcc
PROG = logfile
OPTS = -Wall

all: $(PROG).a test_logfile

$(PROG).a: $(PROG).o
	ar rcs $(PROG).a $(PROG).o

$(PROG).o: $(PROG).c
	$(CC) $(OPTS) -c $(PROG).c -o$(PROG).o

test_logfile: test_logfile.c $(PROG).a
    # Do not specify the .a library suffix, the compiler doesn't require it
	$(CC) $(OPTS) test_logfile.c -l$(PROG) -otest_logfile

clean:
	rm test_logfile *.o $(PROG).a
