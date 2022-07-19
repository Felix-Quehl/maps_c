#ifndef HEADER_SETTINGS
#define HEADER_SETTINGS

const int ARG_COUNT;
const int ARG_INDEX_CACHE;
const int ARG_INDEX_URL;
const int ARG_INDEX_Z;
const int ARG_INDEX_Y;
const int ARG_INDEX_X;

typedef enum SETTINGS_STATUS
{
    SETTINGS_ERROR = 0,
    SETTINGS_OKAY = 1
} Settings_Status;

struct Settings
{
    int z;
    double lat_start;
    double long_start;
    int y_length;
    int x_length;
    char *url;
    char *cache;
};

Settings_Status load_settings(int argument_count, char **arguments, struct Settings *settings);

#endif
