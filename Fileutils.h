#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

/*
 * It will iterate through all the lines in given file and
 * put them in the given vector
 */
size_t getFileContent(std::string fileName, std::vector<std::string>& vecOfStrs);

// Utility to return a compiled-at-NOW timestamp string 
const std::string exeDate = std::string(__DATE__) + " - " + std::string(__TIME__);
