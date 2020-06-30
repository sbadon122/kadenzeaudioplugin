/*
  ==============================================================================

    KAPCenterPanelMenuBar.h
    Created: 31 May 2020 11:20:23pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#pragma once

#include "KAPPanelBase.h"
#include "KAPParameterComboBox.h"

class KAPCenterPanelMenuBar
: public KAPPanelBase
{
public:
    KAPCenterPanelMenuBar(KadenzeAudioPluginAudioProcessor* inProcessor);
    ~KAPCenterPanelMenuBar();
    
    void addFxTypeComboBoxListener(ComboBox::Listener* inListener);
    void removeFxTypeComboBoxListener(ComboBox::Listener* inListener);
private:
    ScopedPointer<KAPParameterComboBox> mFxTypeComboBox;
};
