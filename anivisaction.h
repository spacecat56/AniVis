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

#ifndef ANAVIS_PLUGIN_ACTION_H
#define ANAVIS_PLUGIN_ACTION_H

#include "dzaction.h"
#include "wlsAnivisWatcher.h"

//plugin adds a new action class derived from DzEditAction so it is
//added to the edit menu when first loaded.
class DzAniVisAction : public DzEditAction {
	Q_OBJECT
public:

	static const QString property_name;

	DzAniVisAction();

protected:
    void	executeAction() override;

private:
	static wlsAnivisWatcher *anivis_watcher_;
};

#endif 