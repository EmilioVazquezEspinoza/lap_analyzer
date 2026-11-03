#pragma once
#include <string>
#include <vector>
#include "Types.h"

std::vector<Sample> readSamples (const std::string& path);
bool exportLapsCsv(const std::vector<LapInfo>& laps, const std::string& path);