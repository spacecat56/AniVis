/**********************************************************************
	Copyright (C) 2015, 2017 by West Leitrim Software. 
	All Rights Reserved.
	
	This source code and software provided under the terms of the 
	Mozilla Public License Version 2.0 (MPL) a copy of which is 
	provided with it.
	
	Without limitation or modification of the license, note that 
	key terms of the license are approximately:
	
	(1) free to use for personal and commercial purposes
	(2) you must publish source to any derivative you distribute
	(3) there is ABSOLUTELY NO WARRANTY

**********************************************************************/

#ifndef VERSION_H
#define VERSION_H

#include "dzversion.h"

// Version number for AniVis
#define ANAVIS_MAJOR	1
#define ANAVIS_MINOR	0
#define ANAVIS_REV		0
#define ANAVIS_BUILD	1

#define ANAVIS_VERSION	DZ_MAKE_VERSION( ANAVIS_MAJOR, ANAVIS_MINOR, ANAVIS_REV, ANAVIS_BUILD )

#endif 
