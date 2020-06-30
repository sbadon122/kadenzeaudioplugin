/*
  ==============================================================================

    KAPGainPanel.cpp
    Created: 31 May 2020 11:21:18pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#include "KAPGainPanel.h"
#include "KAPParameters.h"
#include "KAPHelperFunctions.h"

KAPGainPanel::KAPGainPanel(KadenzeAudioPluginAudioProcessor* inProcessor)
: KAPPanelBase(inProcessor)
{
    const int meter_width = 64;
    setSize(GAIN_PANEL_WIDTH,GAIN_PANEL_HEIGHT);
    mVuMeter = new KAPVuMeter(mProcessor);
    mVuMeter->setBounds(getWidth() * 0.5 - meter_width* 0.5, getHeight() * 0.6f - meter_width* 0.5, meter_width, getHeight()* 0.45);
    addAndMakeVisible(mVuMeter);
    
}

KAPGainPanel::~KAPGainPanel()
{
    
}

void KAPGainPanel::paint(Graphics& g)
{
    KAPPanelBase::paint(g);
    if(mSlider)
    {
        paintComponentLabel(g, mSlider);
    }
}

void KAPGainPanel::setParameterID(int inParameterID)
{
    mSlider = new KAPParameterSlider(mProcessor->parameters, KAPParameterID[inParameterID], KAPParameterLabel[inParameterID]);
    const int slider_size = 54;
    
    mSlider->setBounds((getWidth() * 0.5) - (slider_size*0.5), (getHeight() * 0.25) - (slider_size*0.5), slider_size, slider_size);
    
    addAndMakeVisible(mSlider);
    mVuMeter->setParameterID(inParameterID);
}

