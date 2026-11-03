#pragma once
#include <vector>
#include "Types.h"

std::vector<LapInfo> computeLaps(const std::vector<Sample>& samples);
int     findBestLap(const std::vector<LapInfo>& laps);
double  averageLapTime(const std::vector<LapInfo>& laps);
int     findLapIndex(const std::vector<LapInfo>& laps, int number);
int findTopSpeedLap(const std::vector<LapInfo>& laps);