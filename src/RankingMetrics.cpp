#include "RankingMetrics.h"

RankingMetrics::RankingMetrics(float netSales, float averageTransactionValue, float beveragesPerTransaction, float cashDifference, float speedOfServiceAverage, float discountPercentOfSales) {
    this->netSales = netSales;
    this->averageTransactionValue = averageTransactionValue;
    this->beveragesPerTransaction = beveragesPerTransaction;
    this->cashDifference = cashDifference;
    this->speedOfServiceAverage = speedOfServiceAverage;
    this->discountPercentOfSales = discountPercentOfSales;
}

float RankingMetrics::getNetSales() {
    return netSales;
}

float RankingMetrics::getAverageTransactionValue() {
    return averageTransactionValue;
}

float RankingMetrics::getBeveragesPerTransaction() {
    return beveragesPerTransaction;
}

float RankingMetrics::getCashDifference() {
    return cashDifference;
}

float RankingMetrics::getSpeedOfServiceAverage() {
    return speedOfServiceAverage;
}

float RankingMetrics::getDiscountPercentOfSales() {
    return discountPercentOfSales;
}