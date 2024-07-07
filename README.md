# logfile
Support for a program to log its activity to a log file.

Comprises a header and object file that currently contain only one function:

`int update_log(const char *log_file_name, const char *new_entry, const int limit)`
    
Adds the string pointed to by `new_entry` to the end of log file named at `log_file_name`. The log file is created if it doesn't yet exist. The log file is truncated by removing lines at the beginning of the file if the line limit has been exceeded.

Returns 0 on success, 1 if an error encountered.
