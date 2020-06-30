/*
  ==============================================================================

    KAPParameterComboBox.cpp
    Created: 3 Jun 2020 5:49:58pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#include "KAPParameterComboBox.h"


KAPParameterComboBox::KAPParameterComboBox(AudioProcessorValueTreeState& stateToControl, const String& parameterID)
: juce::ComboBox(parameterID)
{
   
    
    mAttachment =
    new AudioProcessorValueTreeState::ComboBoxAttachment(stateToControl, parameterID, *this);
}
KAPParameterComboBox::~KAPParameterComboBox()
{
    
}
