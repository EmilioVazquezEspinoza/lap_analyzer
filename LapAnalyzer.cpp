#include "LapAnalyzer.h"

std::vector<LapInfo> computeLaps(const std::vector<Sample>& samples) {
    std::vector<LapInfo> laps;
    if (samples.empty()) return laps;
    
    double  lapStart    = samples[0].time_s;
    double  sum         = samples[0].speed_kmh;
    double  maxV        = samples[0].speed_kmh;
    double  minV        = samples[0].speed_kmh;
    int     count       = 1;

    for (size_t i = 1; i < samples.size(); i++) {
        if (samples[i].lap != samples[i - 1].lap) {
            // The lap ended: close it with what we accumulated
            LapInfo info;
            info.number     = samples[i - 1].lap;
            info.time_s     = samples[i].time_s - lapStart;
            info.avgSpeed   = sum / count;
            info.maxSpeed   = maxV;
            info.minSpeed   = minV;
            laps.push_back(info);

            // Start the next lap with the current sample
            lapStart    = samples[i].time_s;
            sum         = samples[i].speed_kmh;
            maxV        = samples[i].speed_kmh;
            minV        = samples[i].speed_kmh;
            count       = 1;
        } else {
            // Same lap: keep accumulating
            double v = samples[i].speed_kmh;
            sum += v;
            count ++;
            if (v > maxV) maxV = v;
            if (v < minV) minV = v;
        }
    }
    return laps;
}

int findBestLap(const std::vector<LapInfo>& laps) {
    if (laps.empty()) return -1;

    int best = 0;
    for (size_t i = 1; i < laps.size(); i++) {
        if (laps[i].time_s < laps[best].time_s) {
            best = static_cast<int>(i);
        }
    }
    return best;
}
int findTopSpeedLap(const std::vector<LapInfo>& laps) {
    if (laps.empty()) return -1;

    int top = 0;
    for (size_t i =1; i < laps.size(); i++) {
        if (laps[i].maxSpeed > laps[top].maxSpeed) {
            top = static_cast<int>(i);
        }
    }
    return top;
}

double averageLapTime(const std::vector<LapInfo>& laps) {
    if (laps.empty()) return 0;

    double total = 0;
    for (const LapInfo& lap : laps) {
        total += lap.time_s;
    }
    return total / laps.size();
}

int findLapIndex(const std::vector<LapInfo>& laps, int number) {
    for (size_t i = 0; i < laps.size(); i++) {
        if (laps[i].number == number) {
            return static_cast<int>(i);
        }
    }
    return -1;
}