/*
  ==============================================================================

    KAPParameterSlider.cpp
    Created: 3 Jun 2020 5:49:29pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#include "KAPParameterSlider.h"


KAPParameterSlider::KAPParameterSlider(AudioProcessorValueTreeState& stateToControl, const String& parameterID, const String& parameterLabel)
: juce::Slider(parameterLabel)
{
    setSliderStyle(SliderStyle::RotaryHorizontalVerticalDrag);
    setTextBoxStyle(Slider::TextEntryBoxPosition::TextBoxBelow, false, 0, 0);
    
    setRange(0.0f, 1.0f, 0.001f);
    
    mAttachment =
    new AudioProcessorValueTreeState::SliderAttachment(stateToControl, parameterID, *this);
}
KAPParameterSlider::~KAPParameterSlider()
{
    
}
