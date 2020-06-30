/*
  ==============================================================================

    KAPAudioHelpers.h
    Created: 30 May 2020 7:32:46pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"
#define kParameterSmoothingCoeff_Generic 0.04
#define kParameterSmoothingCoeff_Fine 0.002
#define kMeterSmoothingCoeff 0.2f

const static int maxBufferDelaySize = 192000;

static inline float dbToNormalizeGain(float inGain)
{
    float inValueDb = Decibels::gainToDecibels(inGain + 0.00001f);
    inValueDb = (inValueDb + 96.0f) /96.0f;
    
    return inValueDb;
}

inline float kap_linear_interpolation(float v0, float v1, float t)
{
    return (1 - t) * v0 + t * v1;
}

inline double tanh_clip(double x)
{
    return x * ( 27 + x * x ) / ( 29 + 9 * x * x );
}

inline float kap_denormalize(float inValue)
{
    float absValue = fabs(inValue);
    
    if(absValue < 1e-15)
    {
        return 0;
    }
    return inValue;
}
