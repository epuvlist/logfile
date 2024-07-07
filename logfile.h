/* logfile.h
   Support for maintaining a text log file */

int update_log(const char *log_file_name, const char *new_entry, const int limit);
    /* Update the log file whose filename is at log_file_name,
       with new text entry at *new_entry, limiting the log file
       to -limit- lines */
