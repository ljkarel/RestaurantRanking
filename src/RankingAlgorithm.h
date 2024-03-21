#ifndef RANKING_ALGORITHM_H
#define RANKING_ALGORITHM_H

#include <vector>
#include "Restaurant.h"

/// @brief This class represents the ranking algorithm, used for computing ranking metrics and ranking the restaurants.
class RankingAlgorithm {
 public:
    /// @brief Constructs a new RankingAlgorithm object.
    /// @param restaurants A vector of restaurants to be ranked (sorted).
    RankingAlgorithm(std::vector<Restaurant*>& restaurants);

    /// @brief Sort the restaurants according to their performance score.
    void rankRestaurants();
 private:
    /// @brief Computes the ranking metrics for each restaurant. Keeps track of the min and max values for each metric.
    void computeRankingMetrics();

    /// @brief Computes the performance score for each restaurant, based on their metrics and the min and max values.
    void computePerformanceScore();

    /// @brief A vector of restaurants to be ranked (sorted).
    std::vector<Restaurant*>& restaurants;

    /// @brief The minimum and maximum values for each ranking metric, used by helper functions.
    std::vector<std::pair<float, float>> minMaxValues;

};

#endif