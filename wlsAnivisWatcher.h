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

class wls_anivis_watcher : public QObject
{
Q_OBJECT
    public:
	    wls_anivis_watcher(void);
	    ~wls_anivis_watcher(void) override;

	    void hook_scene();

	    void node_marked();

    public slots:
	    void on_scene_cleared(); 
	    void on_scene_loaded();
	    void on_time_changed (DzTime time);
	    void on_anivis_value_changed() const;

    private:
	    bool has_anivis_property_;
	    bool hooked_;
	    QString real_property_name_;
	    bool handling_time_change_;
};

