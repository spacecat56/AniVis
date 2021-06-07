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
#include "dzsettings.h"
#include "dzpropertysettings.h"
#include "dzpresentation.h"

#include "anivisaction.h"


const QString DzAniVisAction::property_name = "AnimateVisibility";

wlsAnivisWatcher *DzAniVisAction::anivis_watcher_ = nullptr; //new wlsAnivisWatcher();

DzAniVisAction::DzAniVisAction() :
	DzEditAction( "Add AniVis Property", "Add the Animate Visibility to the selected Node(s)" )
{
	// create the watcher
	anivis_watcher_ = new wlsAnivisWatcher();
	anivis_watcher_->hookTheScene();
}

void DzAniVisAction::executeAction()
{
	DzMainWindow *mw = dzApp->getInterface();
	if( !mw )
	{
		return;
	}

	if (!anivis_watcher_) {
        anivis_watcher_ = new wlsAnivisWatcher();
		anivis_watcher_->hookTheScene();
	}

    const QObjectList nodes = dzScene->getSelectedNodeList();

	for (int i = 0; i < nodes.count(); i++) 
	{
        auto node = dynamic_cast<DzNode*>(nodes.at(i));
		if (node->findProperty(property_name) == nullptr)
		{
            auto dz_property = new DzBoolProperty(property_name, true, true, true);
			auto dz_presentation = new DzPresentation();

			dz_property->makePersistent();
			dz_property->setLabel("Animate Visibility");
			dz_property->setPath("Display");			
			dz_presentation->setType("Modifier/Pose");
			dz_presentation->setColorA(*new QColor(255, 255, 125));
			dz_presentation->setColorB(*new QColor(255, 255, 220));
			dz_property->setPresentation(dz_presentation);

			node->addProperty(dz_property);
            anivis_watcher_->markedAnode();
			connect(dz_property, SIGNAL (currentValueChanged() ), anivis_watcher_, SLOT(onAnivisValueChanged()));
		}
	}

}
