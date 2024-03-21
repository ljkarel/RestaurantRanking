#ifndef RANKING_METRICS_H
#define RANKING_METRICS_H

/// @brief This class represents the performance metrics calculated from raw rata, used for ranking.
class RankingMetrics{
 public:
    /// @brief Constructs a new RankingMetrics object.
    /// @param netSales The restaurant's total sales.
    /// @param averageTransactionValue The restaurant's average transaction value.
    /// @param beveragesPerTransaction The restaurant's average beverages per transaction.
    /// @param cashDifference The restaurant's cash difference (from 0).
    /// @param speedOfServiceAverage The restaurant's average service speed (in seconds).
    /// @param discountPercentOfSales The restaurant's ratio of discounts to total sales.
    RankingMetrics(float netSales, float averageTransactionValue, float beveragesPerTransaction, float cashDifference, float speedOfServiceAverage, float discountPercentOfSales);
    
    /// @brief Gets the restaurant's total sales.
    /// @return The restaurant's total sales.
    float getNetSales();

    /// @brief Gets the restaurant's average transaction value.
    /// @return The restaurant's average transaction value.
    float getAverageTransactionValue();

    /// @brief Gets the restaurant's average beverages per transaction.
    /// @return The restaurant's average beverages per transaction.
    float getBeveragesPerTransaction();

    /// @brief Gets the restaurant's cash difference (from 0).
    /// @return The restaurant's cash difference (from 0).
    float getCashDifference();

    /// @brief Gets the restaurant's average service speed (in seconds).
    /// @return The restaurant's average service speed (in seconds).
    float getSpeedOfServiceAverage();

    /// @brief Gets the restaurant's ratio of discounts to total sales.
    /// @return The restaurant's ratio of discounts to total sales.
    float getDiscountPercentOfSales();

 private:
    /// @brief The restaurant's total sales for the day, not including sales tax.
    float netSales; 

    /// @brief The restaurant's average transaction value.
    float averageTransactionValue;

    /// @brief The restaurant's average beverages per transaction.
    float beveragesPerTransaction;

    /// @brief The restaurant's cash difference (from 0).
    float cashDifference;

    /// @brief The restaurant's average service speed (in seconds).
    float speedOfServiceAverage;

    /// @brief The restaurant's ratio of discounts to total sales.
    float discountPercentOfSales;
};

#endif