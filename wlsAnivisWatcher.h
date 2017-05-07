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
#pragma once
#include "dzscene.h"

class wlsAnivisWatcher : public QObject
{
	Q_OBJECT
public:
	wlsAnivisWatcher(void);
	~wlsAnivisWatcher(void);

	void hookTheScene();

	void markedAnode();

public slots:
	void onSceneCleared(); 
	void onSceneLoaded();
	void onTimeChanged (DzTime time);
	void onAnivisValueChanged();

private:
	bool mHasSome;
	bool mHooked;
	QString mRealPropertyName;
	bool mHandlingTimeChange;
};

