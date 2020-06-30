/*
  ==============================================================================

    KAPMainPanel.h
    Created: 31 May 2020 11:19:48pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#pragma once
#include "KAPPanelBase.h"
#include "KAPTopPanel.h"
#include "KAPGainPanel.h"
#include "KAPCenterPanel.h"

class KAPMainPanel
:   public KAPPanelBase
{
public:
    KAPMainPanel(KadenzeAudioPluginAudioProcessor* inProcessor);
    ~KAPMainPanel();
private:
    ScopedPointer<KAPTopPanel>  mTopPanel;
    ScopedPointer<KAPGainPanel> mInputGainPanel;
    ScopedPointer<KAPGainPanel> mOutputGainPanel;
    ScopedPointer<KAPCenterPanel> mCenterPanel;
};
