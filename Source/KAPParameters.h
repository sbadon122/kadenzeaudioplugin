/*
  ==============================================================================

    KAPParameters.h
    Created: 3 Jun 2020 7:59:29am
    Author:  Sebastian Badon

  ==============================================================================
*/

#pragma once

enum KAPParameter
{
    kParameter_InputGain = 0,
    kParameter_DelayTime,
    kParameter_DelayFeedback,
    kParameter_DelayWetDry,
    kParameter_DelayType,
    kParameter_OutputGain,
    kParameter_ModulationRate,
    kParameter_ModulationDepth,
    kParameter_TotalNumParameters,
};

static String KAPParameterID [kParameter_TotalNumParameters] =
{
    "InputGain",
    "DelayTime",
    "DelayFeedback",
    "DelayWetDry",
    "DelayType",
    "OutputGain",
    "Modulation Rate",
    "Modulation Depth",
    
};

static String KAPParameterLabel [kParameter_TotalNumParameters] =
{
    "Input Gain",
    "Delay Time",
    "Delay Feedback",
    "Delay WetDry",
    "Delay Type",
    "Output Gain",
    "Modulation Rate",
    "Modulation Depth",
    
};

static double KAPParameterDefaultValue [kParameter_TotalNumParameters] =
{
    0.5,
    0.5,
    0.5,
    0.5,
    0.5,
    0.5,
    0.5,
    0.5,
    
};

