#pragma once

struct Sample {
    double  time_s;
    int     lap;
    double  speed_kmh;
};

struct LapInfo {
    int     number; // number of lap
    double  time_s; // time in seconds
    double  avgSpeed; // average speed (km/h)
    double  maxSpeed; // top speed (km/h)
    double  minSpeed; // lowest speed (km/h)
};