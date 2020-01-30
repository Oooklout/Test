#pragma once
#include "Fileutils.h"

/*
 * Iterates blind through all the lines in file putting each  
 * in the given vector-of-strings
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

	size_t total=0;
	std::string str;
	// Read the next line from File until it reaches the end.
	while (std::getline(infile, str))
	{
		vecOfStrs.push_back(str);
		total++; 
	}

	if (vecOfStrs.empty()) 
	{
		throw std::runtime_error("No Items found in File");
	}
	//Close The File ( *** ?not needed with std::ifstream? ) 
	infile.close();
	return (total);  // number of items 
}

