#include "RankingManager.h"

#include <string>

int main(int argc, char* argv[]) {
    // by default, filename will be empty
    std::string filename = "";
    
    if (argc > 1) {
        // get filename from command line
        filename = argv[1];
    }

    // run the ranking program
    RankingManager rankingProgram(filename);
    rankingProgram.computeRankings();
    return 0;
}