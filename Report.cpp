#include "Report.h"
#include "LapAnalyzer.h" // xompareLaps uses findLapIndex
#include <iostream>
#include <iomanip>

void printLaps(const std::vector<LapInfo>& laps, int best) {
    if (laps.empty()) {
        std::cout << "No laps detected.\n";
        return;
    }

    std::cout << std::fixed << std::setprecision(3);
    std::cout << "\n--- Times per lap ---\n";

    for (size_t i = 0; i < laps.size(); ++i) {
        double diff = laps[i].time_s - laps[best].time_s;

        std::cout << "Lap " << laps[i].number << ": "
                  << laps[i].time_s <<" s (+" << diff << " s)";
        
        if (static_cast<int>(i) == best) {
            std::cout << " --- BEST";
        }
        std::cout << "\n";
    }
}

void printSpeedStats (const std::vector<LapInfo>& laps) {
    if (laps.empty()) return;

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "\n--- Speed per lap ---\n";
    std::cout << std::setw(6)   << "Lap"
              << std::setw(10)  << "Avg"
              << std::setw(10)  << "Max"
              << std::setw(10)  << "Min" << "\n";

    for (const LapInfo& lap : laps) {
        std::cout << std::setw(6) << lap.number
                  << std::setw(10) << lap.avgSpeed
                  << std::setw(10) << lap.maxSpeed
                  << std::setw(10) << lap.minSpeed << "\n";
    }
}

void compareLaps(const std::vector<LapInfo>& laps, int numA, int numB) {
    int ia = findLapIndex(laps, numA);
    int ib = findLapIndex(laps, numB);

    if (ia == -1 || ib == -1) {
        std::cout << "\nOne of the laps was not found.\n";
        return;
    }

    const LapInfo& a = laps[ia];
    const LapInfo& b = laps[ib];

    std::cout << "\n--- Lap " << a.number << " vs Lap " << b.number << " ---\n";

    std::cout << std::fixed << std::setprecision(3) << std::showpos;
    std::cout << "Time delta: " << (b.time_s - a.time_s) << " s\n";

    std::cout << std::setprecision(1);
    std::cout << "Avg speed delta: " << (b.avgSpeed - a.avgSpeed) << " km/h\n";
    std::cout << "Max speed delta: " << (b.maxSpeed - a.maxSpeed) << " km/h\n";
    std::cout << "Min speed delta: " << (b.minSpeed - a.minSpeed) << " km/h\n";

    std::cout << std::noshowpos;
}