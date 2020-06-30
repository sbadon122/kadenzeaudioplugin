/*
  ==============================================================================

    KAPPanelBase.cpp
    Created: 31 May 2020 11:19:34pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#include "KAPPanelBase.h"
#include "KAPInterfaceDefines.h"


KAPPanelBase::KAPPanelBase(KadenzeAudioPluginAudioProcessor* inProcessor)
: mProcessor(inProcessor)
{
    
}
KAPPanelBase::~KAPPanelBase()
{
    
}
void KAPPanelBase::paint(Graphics& g)
{
//    if(isMouseOver())
//    {
//        const Colour hoverColour = Colour(Colours::black).withAlpha(0.4f);
//        g.setColour(hoverColour);
//        g.fillAll();
//       
//    }
}

void KAPPanelBase::mouseEnter (const MouseEvent& event)
{
    repaint();
}
void KAPPanelBase::mouseExit (const MouseEvent& event)
{
    repaint();
}
