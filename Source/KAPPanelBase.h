/*
  ==============================================================================

    KAPPanelBase.h
    Created: 31 May 2020 11:19:34pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"
#include "PluginProcessor.h"
#include "KAPInterfaceDefines.h"

class KAPPanelBase
:   public Component
{
public:
    KAPPanelBase(KadenzeAudioPluginAudioProcessor* inProcessor);
    ~KAPPanelBase();
    void paint(Graphics& g);
    
    void mouseEnter (const MouseEvent& event) override;
    void mouseExit (const MouseEvent& event) override;
    
protected:
    KadenzeAudioPluginAudioProcessor* mProcessor;
};
