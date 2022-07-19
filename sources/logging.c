#include "stdio.h"
#include "logging.h"

void log_error(char *msg)
{
    printf("ERROR: %s\n", msg);
}

void log_info(char *msg)
{
    printf("INFO: %s\n", msg);
}