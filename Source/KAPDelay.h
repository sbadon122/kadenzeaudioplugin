/*
  ==============================================================================

    KAPDelay.h
    Created: 30 May 2020 7:33:57pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#pragma once
#include "KAPAudioHelpers.h"

enum KAPDelayType
{
    kKAPDelayType_Delay = 0,
    kKAPDelayType_Chorus
    
};

class KAPDelay {
public:
    KAPDelay();
    ~KAPDelay();
    void setSampleRate(double inSampleRate);
    void reset();
    void process(float* inAudio,
                 float inTime,
                 float inFeedback,
                 float inWetDry,
                 float inType,
                 float* inModulationBuffer,
                 float* outAudio,
                 int inNumSamplesToRender);
private:
    double getInterpolatedSample(float inDelayTimeInSamples);
    
    double mSampleRate;
    double mBuffer[maxBufferDelaySize];
    double mFeedbackSample;
    
    float mTimeSmoothed;
    int mDelayIndex;
};
