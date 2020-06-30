/*
  ==============================================================================

    KAPPresentManager.h
    Created: 5 Jun 2020 7:31:42pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"

#define PRESET_FILE_EXTENSION ".kpf"

class KAPPresetManager {
public:
    KAPPresetManager(AudioProcessor* inProcessor);
    ~KAPPresetManager();
    void getXmlForPreset(XmlElement* inElement);
    void loadPresetForXml(XmlElement* inElement);
    
    int getNumberOfPresets();
    
    String getPresetName(int inPresetIndex);
    
    void createNewPreset();
    
    void savePreset();
    
    void saveAsPreset(String inPresetName);
    
    void loadPreset(int inPresetIndex);
    
    bool getCurrentPresetIsSaved();
    
    String getCurrentPresetName();
    
    
private:
    
    void storeLocalPreset();
    
    bool mCurrentPresetIsSaved;
    
    File mCurrentlyLoadedPreset;
    
    Array<File> mLocalPresets;
    
    String mCurrentPresetName;
    
    String mPresetDirectory;
    
    XmlElement* mCurrentPresetXml;
    AudioProcessor* mProcessor;
};
