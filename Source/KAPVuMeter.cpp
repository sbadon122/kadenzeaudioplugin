/*
  ==============================================================================

    KAPVuMeter.cpp
    Created: 16 Jun 2020 7:25:38pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#include "KAPVuMeter.h"
#include "KAPInterfaceDefines.h"
#include "KAPParameters.h"
#include "KAPAudioHelpers.h"

KAPVuMeter::KAPVuMeter(KadenzeAudioPluginAudioProcessor* inProcessor)
:mParameterID(-1), mProcessor(inProcessor), mCh0Level(0), mCh1Level(0)
{
    
}
KAPVuMeter::~KAPVuMeter()
{
    
}

void KAPVuMeter::paint(Graphics& g)
{
    const int meter_width = getWidth() / 3;
    
    g.setColour(KAPColour_6);
    g.fillRect(0,0,meter_width,getHeight());
    g.fillRect(meter_width*2,0, meter_width, getHeight());
    
    int ch0fill = getHeight() - getHeight()*mCh0Level;
    int ch1fill = getHeight() - getHeight()*mCh1Level;
    
    if (ch0fill < 0) {
        ch0fill = 0;
    }
    
    if (ch1fill < 0) {
        ch1fill = 0;
    }
    
    g.setColour(KAPColour_7);
    g.fillRect(0, ch0fill, meter_width,getHeight());
    g.fillRect(meter_width*2,ch1fill, meter_width, getHeight());
}

void KAPVuMeter::timerCallback()
{
    float updatedCh0Level = 0.0f;
    float updatedCh1Level = 0.0f;
    
    switch (mParameterID) {
        case(kParameter_InputGain):{
            updatedCh0Level = mProcessor->getInputGainMeterLevel(0);
            updatedCh1Level = mProcessor->getInputGainMeterLevel(1);
        }break;
        case(kParameter_OutputGain): {
            updatedCh0Level = mProcessor->getOutputGainMeterLevel(0);
            updatedCh1Level = mProcessor->getOutputGainMeterLevel(1);
        }break;
    }
    
    if(updatedCh0Level >  mCh0Level)
    {
        mCh0Level = updatedCh0Level;
    }
    else {
        mCh0Level = kMeterSmoothingCoeff*(mCh0Level-updatedCh0Level) + updatedCh0Level;
    }
    
    if(updatedCh1Level >  mCh1Level)
     {
         mCh1Level = updatedCh1Level;
     }
     else {
        mCh1Level = kMeterSmoothingCoeff*(mCh1Level-updatedCh1Level) + updatedCh1Level;
     }
    
    mCh0Level = kap_denormalize(mCh0Level);
    mCh1Level = kap_denormalize(mCh1Level);
    
    if(mCh0Level && mCh1Level)
    {
        repaint();
    }
}

void KAPVuMeter::setParameterID(int inParameterID)
{
    mParameterID = inParameterID;
    startTimerHz(15);
}
