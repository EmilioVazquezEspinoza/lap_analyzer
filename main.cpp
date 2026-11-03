#include <iostream> //interact
#include <vector>
#include "Types.h"
#include "CsvIO.h"
#include "LapAnalyzer.h"
#include "Report.h"

int main() {
    std::vector<Sample> samples = readSamples("data.csv");
    if (samples.empty()) {
        std::cout << "Could not read data.csv or it is empty\n";
        return 1;
    }

    std::vector<LapInfo> laps = computeLaps(samples);
    int best = findBestLap(laps);

    std::cout << "Samples read: " << samples.size() << "\n";
    printLaps(laps, best);
    std::cout << "Average lap time: " << averageLapTime(laps) << " s\n";
    printSpeedStats(laps);

    int top = findTopSpeedLap(laps);
    if(top != -1) {
        std::cout << "Highest top speed: lap " << laps[top].number
                  << " (" << laps[top].maxSpeed << " km/h)\n";
    }

    int a, b;
    std::cout << "\nCompare which laps? (two numbers): ";
    std::cin >> a >> b;
    compareLaps(laps, a, b);
    if(exportLapsCsv(laps, "results.csv")) {
        std::cout << "\nResults saved to results.csv\n";
    } else {
        std::cout << "\nCould not write results.csv\n";
    }
    return 0;
}
