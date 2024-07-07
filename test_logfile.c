#include <stdio.h>
#include "logfile.h"

int main() {

    // test
    char my_log[] = "nedlog.txt";
    char numberstring[4];

    /* Write 8 lines to the log file, but limit it to 5 lines,
       to check that the truncation works */
    for(int counter=1; counter<8; counter++) {
        sprintf(numberstring, "%d", counter);
        update_log(my_log, numberstring, 5);
    }
    return 0;
}
