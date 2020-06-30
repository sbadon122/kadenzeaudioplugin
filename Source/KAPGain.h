/*
  ==============================================================================

    KAPGain.h
    Created: 30 May 2020 7:33:39pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#pragma once

class KAPGain
{
public:
    KAPGain();
    ~KAPGain();
    
    void process(float* inAudio, float inGain, float* outAudio, int inNumSamplesToRender);
    
    float getMeterLevel();
private:
    
    float mOutputSmoothed;
};
