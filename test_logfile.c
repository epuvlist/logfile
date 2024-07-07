#include <stdio.h>
#include "logfile.h"

int main() {

    /* test */
    char my_log[] = "nedlog.txt";
    char numberstring[4];

    for(int counter=1; counter<8; counter++) {
        sprintf(numberstring, "%d", counter);
        update_log(my_log, numberstring, 5);
    }
    return 0;
}
