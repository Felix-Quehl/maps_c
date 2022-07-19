#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <curl/curl.h>

#include "download.h"

static size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
    size_t written = fwrite(ptr, size, nmemb, (FILE *)stream);
    return written;
}

int download(char *url, char *outfilename)
{
    CURLcode code;
    CURL *curl_handle;
    FILE *pagefile;
    curl_global_init(CURL_GLOBAL_ALL);
    curl_handle = curl_easy_init();
    curl_easy_setopt(curl_handle, CURLOPT_TIMEOUT, 5);
    curl_easy_setopt(curl_handle, CURLOPT_USERAGENT, "tiles2png");
    curl_easy_setopt(curl_handle, CURLOPT_URL, url);
    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_data);
    pagefile = fopen(outfilename, "wb");
    if (pagefile)
    {
        curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, pagefile);
        code = curl_easy_perform(curl_handle);
        fclose(pagefile);
    }
    else
    {
        code = CURLE_FAILED_INIT;
    }
    curl_easy_cleanup(curl_handle);
    curl_global_cleanup();
    return code == CURLE_OK;
}