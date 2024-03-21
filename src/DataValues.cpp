#include "DataValues.h"

DataValues::DataValues(float netSales, int transactionCount, float cashDifference, int beverageCount, int speedOfService, float discountTotal) {
    this->netSales = netSales;
    this->transactionCount = transactionCount;
    this->cashDifference = cashDifference;
    this->beverageCount = beverageCount;
    this->speedOfService = speedOfService;
    this->discountTotal = discountTotal;
}

float DataValues::getNetSales() {
    return netSales;
}

int DataValues::getTransactionCount() {
    return transactionCount;
}

float DataValues::getCashDifference() {
    return cashDifference;
}

int DataValues::getBeverageCount() {
    return beverageCount;
}

int DataValues::getSpeedOfService() {
    return speedOfService;
}

float DataValues::getDiscountTotal() {
    return discountTotal;
}