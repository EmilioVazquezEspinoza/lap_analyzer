# Lap Analyzer

A C++ command-line tool that reads lap telemetry from a CSV file and
reports lap times, speed statistics, and lap-to-lap comparisons.

## Features
- Reads telemetry samples (time, lap, speed) from CSV
- Computes lap times and highlights the best lap
- Average, max and min speed per lap
- Compares any two laps (time and speed deltas)
- Exports results to CSV

## Build and run
    g++ -std=c++17 -Wall main.cpp CsvIO.cpp LapAnalyzer.cpp Report.cpp -o lap_analyzer
    ./lap_analyzer

## Input format
    time_s,lap,speed_kmh
    0.0,1,60.0
    12.0,1,112.5

## Example output
Samples read: 16

--- Times per lap ---
Lap 1: 61.200 s (+1.000 s)
Lap 2: 60.600 s (+0.400 s)
Lap 3: 60.200 s (+0.000 s) --- BEST
Average lap time: 60.667 s

--- Speed per lap ---
   Lap       Avg       Max       Min
     1      96.7     130.8      60.0
     2      99.6     134.2      62.4
     3     101.6     136.5      63.1
Highest top speed: lap 3 (136.5 km/h)

Compare which laps? (two numbers): 1 2

--- Lap 1 vs Lap 2 ---
Time delta: -0.600 s
Avg speed delta: +2.9 km/h
Max speed delta: +3.4 km/h
Min speed delta: +2.4 km/h

Results saved to results.csv

## Project structure
- `Types.h`: data structures
- `CsvIO`: CSV reading and exporting
- `LapAnalyzer`: lap calculations
- `Report`: console output
- `main.cpp`: program flow

## Notes
The included `data.csv` is synthetic sample data. Next steps: real GPS
telemetry, lap detection by finish-line crossing, G-force analysis.