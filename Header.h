#pragma once

// Offsets as 'keys' into the Job vector (corresp to file line nos).
// The vector item preceding each of these is the key text itself, making
// the textfile friendly, and for labelling debug output as key: value pairs. 
// so cout << JobVec((NAME-1)) << " : " << ControlVec((NAME)) << endl;
#define	NAME 2
#define	VERSION 4
#define	TIMESTAMP 6
#define	JOBNAME 8
#define	INPUTLIST 10
#define	INPUTTYPE 12
#define	INPUTPATH 14
#define	OUTPUTPATH 16
#define	OUTPUTTYPE 18
#define	LOGPATH 20
#define	BBOXXMLPATH 22
#define	SETTINGSXMLPATH 24
#define	SEEDPOINTS 26
#define	SAVESETTINGS 28
#define	ITEMS 30
