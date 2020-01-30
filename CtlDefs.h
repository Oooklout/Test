#pragma once
// Job Control File definitions
// Zero-based Offsets as 'keys' into the Job vector (corresp to file line nos).
// The vector item preceding each of these is the key text itself, making
// the textfile friendly, and for labelling debug output as key: value pairs. 
// so cout << JobVec((NAME-1)) << " : " << ControlVec((NAME)) << endl;
// Key="Name"
#define	NAME 1
// Key="Version" 
#define	VERSION 3
// etc...
#define	TIMESTAMP 5
#define	JOBNAME 7
#define	INPUTLIST 9
#define	INPUTTYPE 11
#define	INPUTPATH 13
#define	OUTPUTPATH 15
#define	OUTPUTTYPE 17
#define	LOGPATH 19
#define	BBOXXMLPATH 21
#define	SETTINGSXMLPATH 23
#define	SEEDPOINTS 25
#define	SAVESETTINGS 27
#define	ITEMS 29
// edit this file to align with the template file.
// Additional Items can be added without breaking older EXEs

#ifndef EXE_DATE
// Utility to return a compiled-at-NOW timestamp string
#define EXE_DATE
const std::string exeDate = std::string(__DATE__) + " - " + std::string(__TIME__);
#endif
