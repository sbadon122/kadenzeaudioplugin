/*
  ==============================================================================

    KAPParameterSlider.h
    Created: 3 Jun 2020 5:49:29pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"

class KAPParameterSlider
: public Slider
{
public:
    KAPParameterSlider(AudioProcessorValueTreeState& stateToControl, const String& parameterID, const String& parameterLabel);
    ~KAPParameterSlider();
private:
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> mAttachment;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KAPParameterSlider);
};
