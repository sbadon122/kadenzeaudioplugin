/*
  ==============================================================================

    KAPCenterPanel.cpp
    Created: 31 May 2020 11:20:05pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#include "KAPCenterPanel.h"


KAPCenterPanel::KAPCenterPanel(KadenzeAudioPluginAudioProcessor* inProcessor)
: KAPPanelBase(inProcessor)
{
    setSize(CENTER_PANEL_WIDTH,CENTER_PANEL_HEIGHT);
    mMenuBar = new  KAPCenterPanelMenuBar(inProcessor);
    mMenuBar->setTopLeftPosition(0, 0);
    addAndMakeVisible(mMenuBar);
    
    mFxPanel =  new KAPFxPanel(inProcessor);
    mFxPanel ->setTopLeftPosition(0, CENTER_PANEL_MENU_BAR_HEIGHT);
    addAndMakeVisible(mFxPanel);
    
    mMenuBar->addFxTypeComboBoxListener(mFxPanel);
}

KAPCenterPanel::~KAPCenterPanel()
{
    mMenuBar->removeFxTypeComboBoxListener(mFxPanel);
}

