#pragma once
#include "Fileutils.h"

/*
 * Iterate through all the lines in file and
 * put them in given vector
 */
size_t getFileContent(std::string fileName, std::vector<std::string> & vecOfStrs)
{
	// Open the File
	std::ifstream infile(fileName.c_str());

	// Check if object is valid
	if (!infile)
	{
		throw std::runtime_error("Cannot open Control File");
	}

	std::string str;
	auto total=0;
	// Read the next line from File until it reaches the end.
	while (std::getline(infile, str))
	{
		// Line contains string of length > 0 then save it in vector
		if (str.size() > 0)
		{
			vecOfStrs.push_back(str);
			total++; 
		}
	}

	if (vecOfStrs.empty()) 
	{
		throw std::runtime_error("No Items found in File");
	}
	//Close The File
	infile.close();
	return (total);
}

