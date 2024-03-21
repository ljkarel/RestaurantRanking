#include "RankingAlgorithm.h"

#include <cmath>
#include <utility>
#include <limits>
#include <algorithm>

RankingAlgorithm::RankingAlgorithm(std::vector<Restaurant*>& restaurants) : restaurants(restaurants) {}

float normalize(float value, float min, float max, bool higherIsBetter) {
    // calculate the normalized value using the min and max
    float normalized_value = (value - min) / (max - min);
    if (higherIsBetter) {  // if for this metric higher is better, do nothing
        return normalized_value;
    } else {  // otherwise, take 1 - normalized_value (so 0 becomes 1 and 1 becomes 0)
        return 1 - normalized_value;
    }
}

void RankingAlgorithm::computeRankingMetrics() {
    // create a pair of the minimum and maximum values for each metric
    // start with the highest minumum (infinity) and the lowest maximum (0, since all metrics are positive)
    std::pair<float, float> p = std::make_pair(std::numeric_limits<double>::infinity(), 0);
    minMaxValues = std::vector<std::pair<float, float>>(6, p);
    
    // netSales, averageTransactionValue, beveragesPerTransaction, cashDifference, 
    // speedOfServiceAverage, and discountPercentOfSales, respectively
    std::vector<float> values(6, 0);

    // for each restaurant, use its data to compute its performance metrics
    for (int i = 0; i < restaurants.size(); i++) {
        Restaurant* restaurant = restaurants.at(i);
        DataValues* dataValues = restaurant->getDataValues();
        values.at(0) = (dataValues->getNetSales());
        values.at(1) = (dataValues->getNetSales() / dataValues->getTransactionCount());
        values.at(2) = ((float) dataValues->getBeverageCount() / dataValues->getTransactionCount());
        values.at(3) = (std::abs(dataValues->getCashDifference()));
        values.at(4) = ((float) dataValues->getSpeedOfService() / dataValues->getTransactionCount());
        values.at(5) = (dataValues->getDiscountTotal() / dataValues->getNetSales());
        restaurant->setRankingMetrics(new RankingMetrics(values.at(0), values.at(1), values.at(2), 
            values.at(3), values.at(4), values.at(5)));

        // check to see if this restaurant's metrics are the worst or best for each metric
        // if so, update the minumum or maximum for that metric
        for (int j = 0; j < values.size(); j++) {
            float value = values.at(j);
            if (value < minMaxValues.at(j).first) {
                minMaxValues.at(j).first = value;
            }
            if (value > minMaxValues.at(j).second) {
                minMaxValues.at(j).second = value;
            }
        }
    }
}

void RankingAlgorithm::computePerformanceScore() {
    // for each restaurant, use its calculated metrics and the min/max for each metric to calculate a performance score
    for (int i = 0; i < restaurants.size(); i++) {
        Restaurant* restaurant = restaurants.at(i);
        RankingMetrics* rankingMetrics = restaurant->getRankingMetrics();
        float performanceScore = 0;
        performanceScore += normalize(rankingMetrics->getNetSales(), minMaxValues.at(0).first, minMaxValues.at(0).second, true);
        performanceScore += normalize(rankingMetrics->getAverageTransactionValue(), minMaxValues.at(1).first, minMaxValues.at(1).second, true);
        performanceScore += normalize(rankingMetrics->getBeveragesPerTransaction(), minMaxValues.at(2).first, minMaxValues.at(2).second, true);
        performanceScore += normalize(rankingMetrics->getCashDifference(), minMaxValues.at(3).first, minMaxValues.at(3).second, false);
        performanceScore += normalize(rankingMetrics->getSpeedOfServiceAverage(), minMaxValues.at(4).first, minMaxValues.at(4).second, false);
        performanceScore += normalize(rankingMetrics->getDiscountPercentOfSales(), minMaxValues.at(5).first, minMaxValues.at(5).second, false);
        performanceScore /= 6;  // average the normalized value of all of the metrics
        restaurant->setPerformanceScore(performanceScore);
    }
}

void RankingAlgorithm::rankRestaurants() {
    computeRankingMetrics();  // compute performance metrics
    computePerformanceScore();  // use performance metrics to compute each restaurant's performance score (from 0 to 1)

    // sort restaurants in descending order of performance score
    // ties are not guaranteed to be ordered either way, though ties will be denoted by equivalent rankings and scores
    std::sort(restaurants.begin(), restaurants.end(),
        [](Restaurant* left, Restaurant* right) {
            return left->getPerformanceScore() > right->getPerformanceScore();
        }
    );
}


