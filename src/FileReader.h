#ifndef FILE_READER_H
#define FILE_READER_H

#include <string>
#include <vector>
#include "Restaurant.h"

/// @brief This class represents a file reader, used for reading in data from a file.
class FileReader {
 public:
    /// @brief Constructs a new FileReader object.
    /// @param filename The filename of the data file (if one is passed via command line).
    FileReader(std::string filename);

    /// @brief Reads the file, obtaining the filename through user input, then creates restaurant data structures.
    /// @return A vector of Restaurant objects with their raw data populated.
    std::vector<Restaurant*> readFile();
 private:
    /// @brief The filename of the data file (if one is passed via command line).
    std::string filename;
};

#endif