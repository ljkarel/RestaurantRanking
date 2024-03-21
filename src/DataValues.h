#ifndef DATA_VALUES_H
#define DATA_VALUES_H

/// @brief This class represents the raw data for a restaurant obtained from a CSV file.
class DataValues {
 public:
    /// @brief Constructs a new DataValues object.
    /// @param netSales The restaurant's total sales.
    /// @param transactionCount The restaurant's transaction count.
    /// @param cashDifference The restaurant's cash difference.
    /// @param beverageCount The restaurant's number of beverages sold.
    /// @param speedOfService The restaurant's total service time.
    /// @param discountTotal The restaurant's discount total.
    DataValues(float netSales, int transactionCount, float cashDifference, int beverageCount, int speedOfService, float discountTotal);

    /// @brief Gets the restaurant's total sales.
    /// @return The restaurant's total sales.
    float getNetSales();

    /// @brief Gets the restaurant's transaction count.
    /// @return The restaurant's transaction count.
    int getTransactionCount();

    /// @brief Gets the restaurant's cash difference.
    /// @return The restaurant's cash difference.
    float getCashDifference();

    /// @brief Gets the restaurant's number of beverages sold.
    /// @return The restaurant's number of beverages sold.
    int getBeverageCount();

    /// @brief Gets the restaurant's total service time.
    /// @return The restaurant's total service time.
    int getSpeedOfService();

    /// @brief Gets the restaurant's discount total.
    /// @return The restaurant's discount total.
    float getDiscountTotal();

 private:
    /// @brief The restaurant's total sales for the day, not including sales tax. 
    float netSales;

    /// @brief The total number of guest transactions that were processed in the restaurant that day.
    int transactionCount;

    /// @brief How much extra or missing cash from the registers at the end of the day.
    float cashDifference;

    /// @brief The number of beverages the restaurant sold.
    int beverageCount;

    /// @brief The total time that customers spent waiting on orders, in seconds.
    int speedOfService;

    /// @brief The total value of discounts taken off of the purchase price for the day.
    float discountTotal;
};

#endif