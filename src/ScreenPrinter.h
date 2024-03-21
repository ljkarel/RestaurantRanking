#ifndef SCREEN_PRINTER_H
#define SCREEN_PRINTER_H

#include <vector>
#include "Restaurant.h"

/// @brief This class represents a screen printer, used for printing restaurant ranking results to the screen.
class ScreenPrinter {
 public:
    /// @brief Constructs a new ScreenPrinter object.
    /// @param restaurants A vector of restaurant objects, in ranked order.
    ScreenPrinter(std::vector<Restaurant*>& restaurants);

    /// @brief Print the restaurant rankings to the screen (stdout).
    void printResults();
 private:
    /// @brief A vector of restaurant objects, in ranked order.
    std::vector<Restaurant*>& restaurants;
};

#endif