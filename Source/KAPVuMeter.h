/*
  ==============================================================================

    KAPVuMeter.h
    Created: 16 Jun 2020 7:25:38pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#pragma once


#include "JuceHeader.h"
#include "PluginProcessor.h"

class KAPVuMeter : public Component, public Timer
{
public:
    KAPVuMeter(KadenzeAudioPluginAudioProcessor* inProcessor);
    ~KAPVuMeter();
    
    void paint(Graphics& g) override;
    
    void timerCallback() override;
    
    void setParameterID(int inParameterID);
    
private:
    int mParameterID;
    KadenzeAudioPluginAudioProcessor* mProcessor;
    
    float mCh0Level;
    float mCh1Level;
};
