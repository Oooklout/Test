#pragma once
// Test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include "Fileutils.h"
#include "CtlDefs.h"


void run(int argc, char** argv)
{
	if (argc < 2)
	{
		std::cout << "Not enough Arguments" << std::endl;
		std::cout << "Usage: JobFilePathName" << std::endl;
		return;
	}

	const std::string JobFilePath = argv[1];
	std::cout << JobFilePath << std::endl;
	
	std::cout << "Timestamp: "<< exeDate << std::endl; // test announce compiled-at-NOW-timestamp

	// Note: Zero-based: even item numbers are keys; odd nos are values
	std::vector<std::string> vecOfStr;
	size_t total = getFileContent(JobFilePath, vecOfStr);
	if (total != 0)
	{
		// PrettyPrint the vector contents as key:value pairs for fun
		std::cout << std::endl << "List of Items, paired " << std::endl;

		bool evenItem = false;
		for (std::string& word : vecOfStr)
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

// illustrate DEFINEs indexing job control file vector
	// Tested same as Template4 verbatim OK
	std::cout << vecOfStr[(NAME-1)] << std::endl;	//	
	std::cout << vecOfStr[NAME] << std::endl;	//
	std::cout << vecOfStr[VERSION-1] << std::endl;	// 3
	std::cout << vecOfStr[VERSION] << std::endl;	// 3
	std::cout << vecOfStr[TIMESTAMP-1] << std::endl;	// 5
	std::cout << vecOfStr[TIMESTAMP] << std::endl;	// 5
	std::cout << vecOfStr[JOBNAME-1] << std::endl;	// 7
	std::cout << vecOfStr[JOBNAME] << std::endl;	// 7
	std::cout << vecOfStr[INPUTLIST-1] << std::endl;	// 9
	std::cout << vecOfStr[INPUTLIST] << std::endl;	// 9
	std::cout << vecOfStr[INPUTTYPE-1] << std::endl;	// 11
	std::cout << vecOfStr[INPUTTYPE] << std::endl;	// 11
	std::cout << vecOfStr[INPUTPATH-1] << std::endl;	// 
	std::cout << vecOfStr[INPUTPATH] << std::endl;	// 13
	std::cout << vecOfStr[OUTPUTPATH-1] << std::endl;	// 
	std::cout << vecOfStr[OUTPUTPATH] << std::endl;	// 15
	std::cout << vecOfStr[OUTPUTTYPE-1] << std::endl;	// 
	std::cout << vecOfStr[OUTPUTTYPE] << std::endl;	// 17
	std::cout << vecOfStr[LOGPATH-1] << std::endl;	// 
	std::cout << vecOfStr[LOGPATH] << std::endl;	// 19
	std::cout << vecOfStr[BBOXXMLPATH-1] << std::endl;	// 
	std::cout << vecOfStr[BBOXXMLPATH] << std::endl;	// 21
	std::cout << vecOfStr[SETTINGSXMLPATH-1] << std::endl;	// 
	std::cout << vecOfStr[SETTINGSXMLPATH] << std::endl;	// 23
	std::cout << vecOfStr[SEEDPOINTS-1] << std::endl;	//
	std::cout << vecOfStr[SEEDPOINTS] << std::endl;	// 25
	std::cout << vecOfStr[SAVESETTINGS-1] << std::endl;
	std::cout << vecOfStr[SAVESETTINGS] << std::endl;	// 27
	std::cout << vecOfStr[ITEMS-1] << std::endl;	// 
	std::cout << vecOfStr[ITEMS] << std::endl;	// 29
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