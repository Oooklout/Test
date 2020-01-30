#pragma once
// Test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "Fileutils.h"
#include "CtrlFileDefs.h"

void run(int argc, char** argv)
{
	if (argc < 2)
	{
		std::cout << "Not enough Arguments" << std::endl;
		std::cout << "Usage: JobFilePathName" << std::endl;
		return;
	}

/*
We get the VecOfStr loaded with the key:value pairs. 
We only want the even-numbered items. 
These offsets are used as indexes: vec[NAME] returns the Value string. 
std::string InputList = vecOfStr[INPUTLIST];
*/



	std::string JobFilePath = argv[1];
	std::vector<std::string> Ctl;
	size_t total = getFileContent(JobFilePath, Ctl);
	if (std::stoi(Ctl[ITEMS]) != total) { return; }
	
	std::cout << JobFilePath << std::endl;
	
	std::cout << exeDate << std::endl; // announce compiled-at-NOW-timestamp

	// Note: even-numbered items are keys; odd nos are values
	std::vector<std::string> vecOfStr;
	total = getFileContent(Ctl[INPUTLIST], vecOfStr);
	if (total != 0)
	{
		// PrettyPrint the vector contents as key:value pairs for fun
		std::cout << std::endl << "List of Items, paired " << std::endl;

		bool evenItem = false;
		for (auto word : vecOfStr)
		{
			std::cout << word;
			if (evenItem)
			{
				std::cout << std::endl;
			}else{
				std::cout << " : ";
			}
			evenItem = !evenItem;
		}
		if ((total % 2) == 1)   // shouldn't get an odd number of items
		{
			std::cout << std::endl;
			throw std::runtime_error("CtrlFile: Odd no of items");
		}
		if (std::stoi(vecOfStr.back()) != total)	// last in list is item_count
		{
			throw std::runtime_error("CtrlFileLoad: Incorrect Item count");
		}else{
			std::cout << "All items received" << std::endl;
		}
	}else{
		return;
	}
}

int main(int argc, char** argv)
{
#if defined( WIN32 ) && defined( _DEBUG )
	_CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);
	// _CrtSetBreakAlloc( 0 );
#endif

	try
	{
		run(argc, argv);
		return EXIT_SUCCESS;
	}
	catch (const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	catch (...)
	{
		std::cerr << "unknown error" << std::endl;
		return EXIT_FAILURE;
	}
}