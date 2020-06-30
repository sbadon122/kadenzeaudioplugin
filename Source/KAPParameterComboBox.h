/*
  ==============================================================================

    KAPParameterComboBox.h
    Created: 3 Jun 2020 5:49:58pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"

class KAPParameterComboBox
: public ComboBox
{
public:
    KAPParameterComboBox(AudioProcessorValueTreeState& stateToControl, const String& parameterID);
    ~KAPParameterComboBox();
private:
    ScopedPointer<AudioProcessorValueTreeState::ComboBoxAttachment> mAttachment;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KAPParameterComboBox);
};
