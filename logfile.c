#include <stdio.h>
#include <stdlib.h>  // for EXIT_SUCCESS and EXIT_FAILURE
#include "logfile.h" // can use <logfile.h> when production code moved to /usr/local/include

// Support for text log file

static void print_err() {
    fprintf(stderr, "Error reading or writing log file - not updated\n");
}

int update_log(const char *log_file_name, const char *new_entry, const int limit) {
    /* Save the log file, adding new_entry string to the end.
       Truncate by removing lines at the beginning of the file
       if the line limit has been exceeded.
       Returns 0 on success, 1 if an error encountered.*/

    const char swap_file_name[] = "~swap";  // swap file name
    FILE *swap_file;
    FILE *log_file;
    char buf[128];                    // temporary read-in buffer
    unsigned int line_count = 0;

    // Open the log file
    log_file = fopen(log_file_name, "r");
    if(log_file == NULL) {
        // File does not exist yet, so create a new one
#ifdef DEBUG
        puts("Log file not found, tearing you a new one");
#endif
        log_file = fopen(log_file_name, "w");
        if(log_file == NULL)
            // Error opening the file, return error
            return EXIT_FAILURE;
        // Write the sole new entry and close
        fprintf(log_file, "%s\n", new_entry);
        fclose(log_file);
        return EXIT_SUCCESS;
    }

    // Count the lines in the file
    while(fgets(buf, 128, log_file)) 
        line_count++;
    fclose(log_file);

#ifdef DEBUG
        printf("Line count: %d\n", line_count);
#endif
    if (line_count < limit) {
        // Append the new entry 
        log_file = fopen(log_file_name, "a");
        if(log_file == NULL) {
            print_err();
            return EXIT_FAILURE;
        }
        fprintf(log_file, "%s\n", new_entry);
        fclose(log_file);
        return EXIT_SUCCESS;
    }
    else {
        // Truncate to the required limit by removing earlier lines
#ifdef DEBUG
        puts("Truncation required");
#endif
        // Open the original log file and the swap file
        log_file = fopen(log_file_name, "r");
        swap_file = fopen(swap_file_name, "w");

        // Discard earlier lines that are not wanted because of the line limit
        for(int i = 0; i<(line_count-limit)+1; i++)
            fgets(buf, 128, log_file);

        // Copy all remaining lines to swap file
        while(fgets(buf, 128, log_file))
            fputs(buf, swap_file);

        // Append the new entry
        fprintf(swap_file, "%s\n", new_entry);

	// Wrap up
	fclose(swap_file);
        fclose(log_file);

        // Copy swap file to log file
        if(remove(log_file_name) != 0) {
            print_err();
            return EXIT_FAILURE;
        } else if(rename(swap_file_name, log_file_name) != 0) {
            print_err();
            return EXIT_FAILURE;
        }

        // Successful file operations
        return EXIT_SUCCESS;
    }
}
