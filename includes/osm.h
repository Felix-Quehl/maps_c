#ifndef HEADER_OSM
#define HEADER_OSM

#define M_PI 3.14159265358979323846

int long2tilex(double lon, int z);
int lat2tiley(double lat, int z);
double tilex2long(int x, int z);
double tiley2lat(int y, int z);

#endif
