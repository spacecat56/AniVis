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

#include "dzplugin.h"
#include "dzapp.h"

#include "version.h"
#include "anivisaction.h"

DZ_PLUGIN_DEFINITION( "AniVis - Animate Node Visiblity" );

DZ_PLUGIN_AUTHOR( "West Leitrim Software" );

DZ_PLUGIN_VERSION( ANAVIS_MAJOR, ANAVIS_MINOR, ANAVIS_REV, ANAVIS_BUILD );

DZ_PLUGIN_DESCRIPTION( QString(
					  "<a href=\"%1/AniVis/index.htm\">Documentation</a><br><br>"
					  "This plugin fills a hole in use of the DAZ Studio timeline "
					  "by making it possible to animate the visibility of a node. "
					  ).arg( dzApp->getDocumentationPath() ) );

DZ_PLUGIN_CLASS_GUID( DzAniVisAction, 309CD52D-FC6E-4434-A60E-FC99EFB44080 );

