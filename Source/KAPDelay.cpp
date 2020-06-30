/*
  ==============================================================================

    KAPDelay.cpp
    Created: 30 May 2020 7:33:57pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#include "KAPDelay.h"
#include "JuceHeader.h"
#include "KAPAudioHelpers.h"

KAPDelay::KAPDelay()
: mSampleRate(-1),
  mFeedbackSample(0.0),
  mTimeSmoothed(0.0f),
  mDelayIndex(0)
{
    
}
KAPDelay::~KAPDelay()
{
    
}
void KAPDelay::setSampleRate(double inSampleRate)
{
    mSampleRate = inSampleRate;
}
void KAPDelay::reset()
{
    mTimeSmoothed = 0.0f;
    zeromem(mBuffer, (sizeof(double) * maxBufferDelaySize));
}
void KAPDelay::process(float* inAudio,
             float inTime,
             float inFeedback,
             float inWetDry,
             float inType,
             float* inModulationBuffer,
             float* outAudio,
             int inNumSamplesToRender)
{
    const float wet = inWetDry;
    const float dry = 1.0f - inWetDry;
    const float feedbackMapped = jmap(inFeedback, 0.0f, 1.0f, 0.0f, 1.2f);

    
    for(int i = 0; i<inNumSamplesToRender; i++)
    {
       
        if((int)inType == kKAPDelayType_Delay) {
            mTimeSmoothed = mTimeSmoothed - kParameterSmoothingCoeff_Fine * (mTimeSmoothed-inTime);
        }
        else {
              const double delayTimeModulation = (0.003 + (0.002 * inModulationBuffer[i]));
            mTimeSmoothed = mTimeSmoothed - kParameterSmoothingCoeff_Fine * (mTimeSmoothed-delayTimeModulation);
        }
        
        
        const double delayTimeInSamples =  (mTimeSmoothed * mSampleRate);
        const double sample = getInterpolatedSample(delayTimeInSamples);
        
        
        mBuffer[mDelayIndex] = tanh_clip(inAudio[i] + (mFeedbackSample * feedbackMapped));
        
        mFeedbackSample = sample;
        
        outAudio[i] = inAudio[i]*dry + sample*wet;
        mDelayIndex++;
        
        if(mDelayIndex >= maxBufferDelaySize)
        {
            mDelayIndex -= maxBufferDelaySize;
        }

    }
}

double KAPDelay::getInterpolatedSample(float inDelayTimeInSamples)
{
    double readPosition = (double)mDelayIndex - inDelayTimeInSamples;
    
    if(readPosition < 0.0)
    {
        readPosition += maxBufferDelaySize;
    }
    
    int index_y0 = (int)readPosition - 1;
    if(index_y0 <= 0)
    {
        index_y0 += maxBufferDelaySize;
    }
    
    int index_y1 = (int)readPosition;
    if(index_y1 > maxBufferDelaySize)
    {
        index_y1 -= maxBufferDelaySize;
    }
    
    const float sample_y0 = mBuffer [index_y0];
    const float sample_y1 = mBuffer [index_y1];
    const float t = readPosition - (int)readPosition;
    
    double outSample = kap_linear_interpolation(sample_y0, sample_y1, t);
    
    return outSample;
}
