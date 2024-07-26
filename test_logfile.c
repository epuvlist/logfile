#include <stdio.h>
#include "logfile.h"

/* This program tests the ability of the logfile.c program
   to truncate the log file when it reaches the length limit.
   logfile.c is best compiled with the -DDEBUG option to see the 
   full effect of the test. */

int main() {

    // test
    char my_log[] = "nedlog.log";
    char numberstring[4];

    /* Write 8 lines to the log file, but limit it to 5 lines,
       to check that the truncation works */
    for(int counter=1; counter<8; counter++) {
        sprintf(numberstring, "%d", counter);
        update_log(my_log, numberstring, 5);
    }
    return 0;
}
