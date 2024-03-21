#include "RankingManager.h"

RankingManager::RankingManager(std::string filename) {
    this->filename = filename;
    fileReader = new FileReader(filename);
    rankingAlgorithm = new RankingAlgorithm(restaurants);
    screenPrinter = new ScreenPrinter(restaurants);
}

RankingManager::~RankingManager() {
    delete fileReader;
    delete rankingAlgorithm;
    delete screenPrinter;
    for (int i = 0; i < restaurants.size(); i++) {
        delete restaurants.at(i);
    }
}

void RankingManager::computeRankings() {
    restaurants = fileReader->readFile(); // read restaurant data from a file
    if (restaurants.size() == 0) { // if the file was unable to be read or there are no restaurants, we are done
        return;
    }
    
    rankingAlgorithm->rankRestaurants(); // run the ranking algorithm to sort the restaurants by performance metrics
    screenPrinter->printResults(); // print out the results of the ranking
}