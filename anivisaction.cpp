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

#include <QtGui/QMessageBox>

#include "dzapp.h"
#include "dzmainwindow.h"
#include "dzscene.h"
#include "dznode.h"
#include "dzboolproperty.h"

#include "anivisaction.h"


const QString DzAniVisAction::PropertyName = "AnimateVisibility";
wlsAnivisWatcher *DzAniVisAction::myWatcher = 0; //new wlsAnivisWatcher();

DzAniVisAction::DzAniVisAction() :
	DzEditAction( "Add AniVis Property", "Add the Animate Visibility to the selected Node(s)" )
{
	// create the watcher
	myWatcher = new wlsAnivisWatcher();
	myWatcher->hookTheScene();
}

void DzAniVisAction::executeAction()
{

	DzMainWindow *mw = dzApp->getInterface();
	if( !mw )
	{
		return;
	}

	if (!DzAniVisAction::myWatcher) {
		DzAniVisAction::myWatcher = new wlsAnivisWatcher();
		myWatcher->hookTheScene();
	}

	QObjectList nodes = dzScene->getSelectedNodeList();

	for (int i = 0; i < nodes.count(); i++) 
	{
		DzNode *node = (DzNode *)nodes.at(i);
		if (node->findProperty(PropertyName) == NULL)
		{
			DzBoolProperty *wedge = new DzBoolProperty(PropertyName, true, true, true);
			wedge->makePersistent();
			node->addProperty(wedge);
			DzAniVisAction::myWatcher->markedAnode();
			connect(wedge, SIGNAL (currentValueChanged() ), myWatcher, SLOT(onAnivisValueChanged()));
		}
	}

}
