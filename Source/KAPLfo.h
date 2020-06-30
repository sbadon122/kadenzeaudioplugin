/*
  ==============================================================================

    KAPLfo.h
    Created: 30 May 2020 7:33:32pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#pragma once
#include "KAPAudioHelpers.h"
class KAPLfo {
public:
    KAPLfo();
    ~KAPLfo();
    
    void reset();
    void setSampleRate(double inSampleRate);
    void process(float inRate, float inDepth, int inNumSamples);
    float* getBuffer();
private:
    double mSampleRate;
    float mPhase;
    float mBuffer[maxBufferDelaySize];
};
