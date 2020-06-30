/*
  ==============================================================================

    KAPCenterPanel.h
    Created: 31 May 2020 11:20:05pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#pragma once


#include "KAPPanelBase.h"
#include "KAPCenterPanelMenuBar.h"
#include "KAPFxPanel.h"

class KAPCenterPanel
: public KAPPanelBase
{
public:
    KAPCenterPanel(KadenzeAudioPluginAudioProcessor* inProcessor);
    ~KAPCenterPanel();
    

private:
    ScopedPointer<KAPCenterPanelMenuBar> mMenuBar;
    ScopedPointer<KAPFxPanel> mFxPanel;
};
