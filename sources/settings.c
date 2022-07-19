#include <stdlib.h>
#include "settings.h"

const int ARG_COUNT = 8;
const int ARG_INDEX_CACHE = 1;
const int ARG_INDEX_URL = 2;
const int ARG_INDEX_Z = 3;

const int ARG_INDEX_LAT_START = 4;
const int ARG_INDEX_LONG_START = 5;
const int ARG_INDEX_X_LENGTH = 6;
const int ARG_INDEX_Y_LENGTH = 7;

Settings_Status load_settings(int argument_count, char **arguments, struct Settings *settings)
{
    if (argument_count == ARG_COUNT)
    {
        settings->cache = arguments[ARG_INDEX_CACHE];
        settings->url = arguments[ARG_INDEX_URL];
        settings->z = atoi(arguments[ARG_INDEX_Z]);
        settings->long_start = strtod(arguments[ARG_INDEX_LONG_START], NULL);
        settings->lat_start = strtod(arguments[ARG_INDEX_LAT_START], NULL);
        settings->x_length = atoi(arguments[ARG_INDEX_X_LENGTH]);
        settings->y_length = atoi(arguments[ARG_INDEX_Y_LENGTH]);
        return SETTINGS_OKAY;
    }
    else
    {
        return SETTINGS_ERROR;
    }
}