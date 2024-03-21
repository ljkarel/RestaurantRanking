#include "ScreenPrinter.h"

#include <iostream>

ScreenPrinter::ScreenPrinter(std::vector<Restaurant*>& restaurants) : restaurants(restaurants) {}

void ScreenPrinter::printResults() {
    std::cout << "|      Restaurant      |   Score   |  Ranking  |" << std::endl;
    std::cout << "|======================|===========|===========|" << std::endl;
    int rank = 1;

    // write the restaurant, score, and ranking for each restaurant
    for (int i = 0; i < restaurants.size(); i++) {
        Restaurant* restaurant = restaurants.at(i);

        // if n restaurants tie, give them the same ranking and start the next rank value n ahead
        if (i > 0 && restaurant->getPerformanceScore() != restaurants.at(i - 1)->getPerformanceScore()) {
            rank = i + 1;
        }
        char line[128];
        snprintf(line, sizeof(line), "| %-20.20s | %-9f | %-9d |", restaurant->getName().c_str(), restaurant->getPerformanceScore(), rank);
        std::cout << line << std::endl;
    }
}