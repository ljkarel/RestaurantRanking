#ifndef RANKING_MANAGER_H
#define RANKING_MANAGER_H

#include <string>
#include <vector>
#include "FileReader.h"
#include "RankingAlgorithm.h"
#include "ScreenPrinter.h"
#include "Restaurant.h"

/// @brief This class represents the driver for the ranking program, controlling IO, algorithm, and data objects.
class RankingManager {
 public:
    /// @brief Constructs a new RankingManager object.
    /// @param filename The filename of the data file (if one is passed via command line). 
    RankingManager(std::string filename);

    /// @brief Destructs an existing RankingManager object, and its IO, algorithm, and data objects.
    ~RankingManager();

    /// @brief Runs the ranking program, computing the rankings for restaurants based on performance metrics.
    void computeRankings();

 private:
    /// @brief The filename of the data file (if one is passed via command line).
    std::string filename;

    /// @brief The file reader for reading in data from a file.
    FileReader* fileReader;

    /// @brief The restaurant ranking algorithm for computing performance metrics and ranking the restaurants .
    RankingAlgorithm* rankingAlgorithm;

    /// @brief The screen printer to print results to the screen.
    ScreenPrinter* screenPrinter;

    /// @brief The restaurants being analyzed and ranked.
    std::vector<Restaurant*> restaurants;
};

#endif