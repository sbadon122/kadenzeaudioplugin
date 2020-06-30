/*
  ==============================================================================

    KAPGainPanel.h
    Created: 31 May 2020 11:21:18pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#pragma once

#include "KAPPanelBase.h"
#include "KAPParameterSlider.h"
#include "KAPVuMeter.h"


class KAPGainPanel
: public KAPPanelBase
{
public:
    KAPGainPanel(KadenzeAudioPluginAudioProcessor* inProcessor);
    ~KAPGainPanel();
    
    void paint(Graphics& g);
    
    void setParameterID(int inParameterID);
private:
    ScopedPointer<KAPVuMeter> mVuMeter;
    ScopedPointer<KAPParameterSlider> mSlider;
};
