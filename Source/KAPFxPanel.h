/*
  ==============================================================================

    KAPFxPanel.h
    Created: 31 May 2020 11:21:03pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#pragma once

#include "KAPPanelBase.h"
#include "KAPParameterSlider.h"

enum KAPFxPanelStyle {
  kKAPFxPanelStyle_Delay,
  kKAPFxPanelStyle_Chorus,
  kKAPFxPanelStyle_TotalNumStyles
};

class KAPFxPanel
: public KAPPanelBase,
public ComboBox::Listener
{
public:
    KAPFxPanel(KadenzeAudioPluginAudioProcessor* inProcessor);
    ~KAPFxPanel();
    
    void setFxPanelStyle(KAPFxPanelStyle inStyle);
    void paint(Graphics& g) override;
    void comboBoxChanged(ComboBox* comboBoxThatHasChanged) override;
private:
    KAPFxPanelStyle mStyle;
    OwnedArray<KAPParameterSlider> mSliders;
};
