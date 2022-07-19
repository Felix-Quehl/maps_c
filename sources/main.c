#include <stdio.h>
#include <curl/curl.h>
#include <unistd.h>

#include "download.h"
#include "settings.h"
#include "logging.h"
#include "osm.h"

const int TILE_SIDE_LENGTH = 255;
const int IMAGE_WIDTH = 2480;
const int IMAGE_HEIGHT = 3508;

int main(int argument_count, char **arguments)
{
    struct Settings settings;
    Settings_Status settings_status = load_settings(argument_count, arguments, &settings);
    if (settings_status == SETTINGS_OKAY)
    {
        log_info("arguments are okay");

        int x_start_index = long2tilex(settings.long_start, settings.z);
        int y_start_index = lat2tiley(settings.lat_start, settings.z);

        for (int x_offset = 0; x_offset < settings.x_length; x_offset++)
        {
            for (int y_offset = 0; y_offset < settings.y_length; y_offset++)
            {
                int x = x_start_index + x_offset;
                int y = y_start_index + y_offset;
                char url[1024];
                char filename[1024];

                sprintf(url, "%s/%d/%d/%d.png", settings.url, settings.z, x, y);
                sprintf(filename, "%s/%d_%d_%d.png", settings.cache, settings.z, x, y);

                printf("PROCESSING %s", url);
                if (access(filename, F_OK) == 0)
                {
                    printf(" FOUND");
                }
                else
                {

                    int retry = 5;
                    do
                    {
                        printf(" .");
                        int success = download(url, filename);
                        if (success)
                        {
                            printf(" LOADED");
                            retry = 0;
                        }
                        else
                        {
                            sleep(retry++);
                        }
                    } while (retry);
                }
                printf("\n");
            }
        }
    }
    else
    {
        log_error("please check the arguments");
    }
    log_info("all done");
    return 0;
}
