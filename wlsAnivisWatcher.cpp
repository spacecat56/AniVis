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

wls_anivis_watcher::wls_anivis_watcher(void)
{
	has_anivis_property_ = false;
	hooked_ = false;
	real_property_name_ = "Visible";
	handling_time_change_ = false;
}

void wls_anivis_watcher::node_marked()
{
	has_anivis_property_ = true;
}

void wls_anivis_watcher::hook_scene()
{
	if (hooked_)
		return;
	connect( dzScene, SIGNAL( sceneCleared() ), this, SLOT( onSceneCleared() ) );
	connect( dzScene, SIGNAL( sceneLoaded() ), this, SLOT( onSceneLoaded() ) );
	connect( dzScene, SIGNAL( timeChanged(DzTime ) ), this, SLOT( onTimeChanged(DzTime ) ) );

	hooked_ = true;
}


wls_anivis_watcher::~wls_anivis_watcher(void) = default;

void wls_anivis_watcher::on_scene_cleared()
{
	has_anivis_property_ = false;
}

void wls_anivis_watcher::on_scene_loaded()
{
		has_anivis_property_ = false;
		DzNodeListIterator nli = dzScene->nodeListIterator();
		while (nli.hasNext()) 
		{
			DzNode *node = nli.next();
			DzProperty * dz_property = node->findProperty(DzAniVisAction::property_name);
			if (dz_property) 
			{
				has_anivis_property_ = true;
				connect(dz_property, SIGNAL (currentValueChanged() ), this, SLOT(onAnivisValueChanged()));
			}
		}
		on_time_changed(dzScene->getTime());
}

void wls_anivis_watcher::on_time_changed(const DzTime time)
{
	if (has_anivis_property_) 
	{
		handling_time_change_ = true;
        DzNodeListIterator nli = dzScene->nodeListIterator();

		while (nli.hasNext()) 
		{
			DzNode *node = nli.next();
            const auto dz_anivis_property = dynamic_cast<DzBoolProperty*>(node->findProperty(DzAniVisAction::property_name));
			if (dz_anivis_property) 
			{
                const bool visible = dz_anivis_property->getBoolValue(time);
                auto dz_visibility_property = dynamic_cast<DzBoolProperty*>(node->findProperty(real_property_name_));
				dz_visibility_property->setBoolValue(visible);
			}
		}
	}
	handling_time_change_ = false;
}


void wls_anivis_watcher::on_anivis_value_changed() const
{
	if (handling_time_change_) return;

	QObject *q_sender = sender();
    const auto dz_anivis_property = dynamic_cast<DzBoolProperty*>(q_sender);

    if (dz_anivis_property == nullptr) return;

	DzElement *ele = dz_anivis_property->getOwner();

    if (ele == nullptr) return;
	DzProperty *dz_property = ele->findProperty("Visible");

    if (dz_property == nullptr) return;

    auto dz_visibility_property = dynamic_cast<DzBoolProperty*>(dz_property);

    if (dz_visibility_property == nullptr) return;

    dz_visibility_property->setBoolValue(dz_anivis_property->getBoolValue());
}
