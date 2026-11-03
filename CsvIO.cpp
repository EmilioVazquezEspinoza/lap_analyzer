#include "CsvIO.h"
#include <fstream>
#include <sstream>
#include <iomanip>

std::vector<Sample> readSamples (const std::string& path) {
    std::vector<Sample> samples;
    std::ifstream file(path); 
    if (!file.is_open()) {
        return samples; // return empty list
    }

    std::string line;
    std::getline(file, line); // skips header

    while (std::getline(file, line)) {
        if (line.empty()) continue;

        std::stringstream ss(line);
        std::string cell;
        Sample s;

        std:: getline(ss, cell, ','); s.time_s    = std:: stod(cell);
        std:: getline(ss, cell, ','); s.lap       = std:: stoi(cell);
        std:: getline(ss, cell, ','); s.speed_kmh = std:: stod(cell);

        samples.push_back(s);
    }
    return samples;
}

bool exportLapsCsv(const std::vector<LapInfo>& laps, const std::string& path) {
    std::ofstream out(path);
    if (!out.is_open()) {
        return false;
    }

    out << "lap,time_s,avg_kmh,max_kmh,min_kmh\n"; // header
    out << std::fixed << std::setprecision(3);

    for (const LapInfo& lap : laps) {
        out << lap.number   << ","
            << lap.time_s   << ","
            << lap.avgSpeed << ","
            << lap.maxSpeed << ","
            << lap.minSpeed << "\n";
    }
    return true;
}