/*
  ==============================================================================

    KAPHelperFunctions.h
    Created: 4 Jun 2020 6:49:46pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#pragma once
#include "JuceHeader.h"
#include "KAPInterfaceDefines.h"

inline void paintComponentLabel(Graphics& g, Component* inComponent)
{
    const int x = inComponent->getX() - (inComponent->getWidth() * 0.25f);
    const int y = inComponent->getY() + (inComponent->getHeight());
    const int w = inComponent->getWidth() * 1.5f;
    const int h = 20;
    const float cornerSize = 3.0f;
    
    g.setColour(KAPColour_3);
    g.fillRoundedRectangle(x,y,w,h,cornerSize);

    
    const String label = inComponent->getName();
    g.setColour(KAPColour_1);
    g.setFont(font_1);
    g.drawFittedText(label, x, y, w, h, Justification::centred, 1);
    
}
