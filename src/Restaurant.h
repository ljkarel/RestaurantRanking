#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <string>
#include "DataValues.h"
#include "RankingMetrics.h"

/// @brief This class represents a restaurant and its corresponding data and metrics.
class Restaurant {
 public:
    /// @brief Constructs a new Restaurant object.
    /// @param name The name of the restaurant.
    /// @param dataValues The raw data of the restaurant.
    Restaurant(std::string name, DataValues* dataValues);

    /// @brief Destructs an existing Restaurant object, and its data and metric objects.
    ~Restaurant();

    /// @brief Gets the name of the restaurant.
    /// @return The name of the restaurant.
    std::string getName();

    /// @brief Gets the raw data values of the restaurant.
    /// @return The raw data values of the restaurant.
    DataValues* getDataValues();

    /// @brief Sets the calculated performance metrics for the restaurant.
    /// @param rankingMetrics The calculated performance metrics for the restaurant.
    void setRankingMetrics(RankingMetrics* rankingMetrics);

    /// @brief Gets the calculcated performance metrics for the restaurant.
    /// @return The calculated performance metrics for the restaurant.
    RankingMetrics* getRankingMetrics();

    /// @brief Sets the performance score of the restaurant.
    /// @param performanceScore The performance score of the restaurant.
    void setPerformanceScore(float performanceScore);

    /// @brief Gets the performance score of the restaurant.
    /// @return The performance score of the restaurant.
    float getPerformanceScore();

 private:
    /// @brief The name of the restaurant.
    std::string name;

    /// @brief The raw data values of the restaurant.
    DataValues* dataValues;

    /// @brief The calculated performance metrics for the restaurant.
    RankingMetrics* rankingMetrics;

    /// @brief The performance score (between 0 and 1) for the restaurant.
    float performanceScore;
};

#endif