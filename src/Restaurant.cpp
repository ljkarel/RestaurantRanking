#include "Restaurant.h"

Restaurant::Restaurant(std::string name, DataValues* dataValues) {
    this->name = name;
    this->dataValues = dataValues;
}

Restaurant::~Restaurant() {
    delete dataValues;
    delete rankingMetrics;
}

std::string Restaurant::getName() {
    return name;
}

DataValues* Restaurant::getDataValues() {
    return dataValues;
}

void Restaurant::setRankingMetrics(RankingMetrics* rankingMetrics) {
    this->rankingMetrics = rankingMetrics;
}

RankingMetrics* Restaurant::getRankingMetrics() {
    return rankingMetrics;
}

void Restaurant::setPerformanceScore(float performanceScore) {
    this->performanceScore = performanceScore;
}

float Restaurant::getPerformanceScore() {
    return performanceScore;
}
