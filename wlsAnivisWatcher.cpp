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

#include "wlsAnivisWatcher.h"
#include "anivisaction.h"
#include "dznode.h"
#include "dzboolproperty.h"

wlsAnivisWatcher::wlsAnivisWatcher(void)
{
	mHasSome = false;
	mHooked = false;
	mRealPropertyName = "Visible";
	mHandlingTimeChange = false;

}

void wlsAnivisWatcher::markedAnode()
{
	mHasSome = true;
}

void wlsAnivisWatcher::hookTheScene()
{
	if (mHooked)
		return;
	connect( dzScene, SIGNAL( sceneCleared() ), this, SLOT( onSceneCleared() ) );
	connect( dzScene, SIGNAL( sceneLoaded() ), this, SLOT( onSceneLoaded() ) );
	connect( dzScene, SIGNAL( timeChanged(DzTime ) ), this, SLOT( onTimeChanged(DzTime ) ) );

	mHooked = true;
}


wlsAnivisWatcher::~wlsAnivisWatcher(void)
{
}

void wlsAnivisWatcher::onSceneCleared()
{
	mHasSome = false;
}

void wlsAnivisWatcher::onSceneLoaded()
{
		mHasSome = false;
		DzNodeListIterator nli = dzScene->nodeListIterator();
		while (nli.hasNext()) 
		{
			DzNode *node = nli.next();
			DzProperty * aProp = node->findProperty(DzAniVisAction::PropertyName);
			if (aProp) 
			{
				mHasSome = true;
				connect(aProp, SIGNAL (currentValueChanged() ), this, SLOT(onAnivisValueChanged()));
			}
		}
		onTimeChanged(dzScene->getTime());
}

void wlsAnivisWatcher::onTimeChanged(DzTime time)
{
	if (mHasSome) 
	{
		mHandlingTimeChange = true;
		DzBoolProperty *prop;
		DzBoolProperty *realprop;
		DzNodeListIterator nli = dzScene->nodeListIterator();
		while (nli.hasNext()) 
		{
			DzNode *node = nli.next();
			prop = (DzBoolProperty *)node->findProperty(DzAniVisAction::PropertyName);
			if (prop) 
			{
				bool mVis = prop->getBoolValue(time);
				realprop = (DzBoolProperty *)node->findProperty(mRealPropertyName);
				realprop->setBoolValue(mVis);
			}
		}
	}
	mHandlingTimeChange = false;
}


void wlsAnivisWatcher::onAnivisValueChanged() 
{
	if (mHandlingTimeChange) return;
	QObject *oSender = sender();
	DzBoolProperty *bppSender = dynamic_cast<DzBoolProperty*>(oSender);
	if (bppSender == NULL) return;
	DzElement *ele = bppSender->getOwner();
	if (ele == NULL) return;
	DzProperty *baseProp = ele->findProperty("Visible");
	if (baseProp == NULL) return;
	DzBoolProperty *bppBase = dynamic_cast<DzBoolProperty*>(baseProp);
	if (bppBase == NULL) return;
	bppBase->setBoolValue(bppSender->getBoolValue());
}
