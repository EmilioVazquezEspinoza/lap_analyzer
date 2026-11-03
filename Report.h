#pragma once
#include <vector>
#include "Types.h"

void printLaps(const std::vector<LapInfo>& laps, int best);
void printSpeedStats (const std::vector<LapInfo>& laps);
void compareLaps(const std::vector<LapInfo>& laps, int numA, int numB);