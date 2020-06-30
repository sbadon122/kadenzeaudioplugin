/*
  ==============================================================================

    KAPTopPanel.h
    Created: 31 May 2020 11:22:09pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#pragma once
#include "KAPPanelBase.h"

class KAPTopPanel
:   public KAPPanelBase,
    public Button::Listener,
    public ComboBox::Listener
{
public:
    KAPTopPanel(KadenzeAudioPluginAudioProcessor* inProcessor);
    ~KAPTopPanel();
    
    void paint(Graphics& g) override;
    
    void buttonClicked(Button* b) override;
    void comboBoxChanged (ComboBox*  comboBoxThatHasChanged) override;
    
private:
    
    void displaySaveAsPopup();
    void updatePresetComboBox();
    
    ScopedPointer<ComboBox> mPresetDisplay;
    ScopedPointer<TextButton> mNewPreset, mSavePreset, mSaveAsPreset;
};
