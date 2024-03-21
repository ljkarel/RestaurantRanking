#include "FileReader.h"

#include <fstream>
#include <iostream>
#include <sstream>

FileReader::FileReader(std::string filename) {
    this->filename = filename;
}

std::vector<Restaurant*> FileReader::readFile() {
    std::ifstream dataFile;
    if (filename == "") {
        // filename is not entered via the command line, prompt user for a filename
        std::cout << "Enter filename of data file, or type \"q\" to exit: ";
        std::cin >> filename;
        if (filename == "q") {
            // allow user to press "q" to exit program
            std::cout << "Exiting ranking program. Have a nice day!" << std::endl;
            return {};
        }
        dataFile.open(filename);
        while (dataFile.fail()) {
            // continue prompting user until valid filename or exit command is received
            std::cout << "File \"" << filename << "\" could not be opened." << std::endl;
            std::cout << "Enter filename of data file, or type \"q\" to exit: ";
            std::cin >> filename;
            if (filename == "q") {
                std::cout << "Exiting ranking program. Have a nice day!" << std::endl;
                return {};
            }
            dataFile.open(filename);
        }
    } else {  // filename entered via the command line
        dataFile.open(filename);
        if (dataFile.fail()) {  // if file cannot be opened, exit program
            std::cout << "File \"" << filename << "\" could not be opened." << std::endl;
            std::cout << "Exiting ranking program. Have a nice day!" << std::endl;
            return {};
        }
    }

    // information to be read from the file for each restaurant
    std::string name;
    float netSales;
    int transactionCount;
    float cashDifference;
    int beverageCount;
    int speedOfServiceTotal;
    float discountTotal;

    std::vector<Restaurant*> restaurants;

    // read in each line
    std::string line;
    std::getline(dataFile, line, '\n');  // consume first line of headers
    while(!dataFile.eof()) {
        std::string input;  
        std::getline(dataFile, line, '\n');  // get single line from file
        std::istringstream linestream(line);  // turn line into stream
        std::getline(linestream, name, ',');  // get the restaurant name
        std::getline(linestream, input, ','); 
        if (input.empty()) {  // if there is no additional input (happens with blank lines), we are done
            break;
        }
        netSales = stof(input);  // read in each piece of data for the restaurant
        std::getline(linestream, input, ',');
        transactionCount = stoi(input);
        std::getline(linestream, input, ',');
        cashDifference = stof(input);
        std::getline(linestream, input, ',');
        beverageCount = stoi(input);
        std::getline(linestream, input, ',');
        speedOfServiceTotal = stoi(input);
        std::getline(linestream, input, ',');
        discountTotal = stof(input);

        // create a new restaurant with its initial data, and add it to the list of restaurants
        restaurants.push_back(new Restaurant(name, new DataValues(netSales, transactionCount, cashDifference, beverageCount, speedOfServiceTotal, discountTotal)));
    }

    // return the list of restaurants
    return restaurants;
}