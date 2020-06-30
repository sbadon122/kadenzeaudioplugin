/*
  ==============================================================================

    KAPPresentManager.cpp
    Created: 5 Jun 2020 7:31:42pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#include "KAPPresetManager.h"

#if JUCE_WINDOWS
static const String directorySeperator = "\\";
#elif JUCE_MAC
static const String directorySeperator = "/";

#endif


KAPPresetManager::KAPPresetManager(AudioProcessor* inProcessor)
:mProcessor(inProcessor), mCurrentPresetIsSaved(false), mCurrentPresetName("Untitled")
{
    const String pluginName = (String) mProcessor->getName();
    mPresetDirectory = File::getSpecialLocation(File::userDesktopDirectory).getFullPathName()+directorySeperator+pluginName;
    
    if(!File(mPresetDirectory).exists())
    {
        File(mPresetDirectory).createDirectory();
    }
    
    storeLocalPreset();
}
KAPPresetManager::~KAPPresetManager()
{
    
}
void KAPPresetManager::getXmlForPreset(XmlElement* inElement)
{
    auto& parameters = mProcessor->getParameters();
    
    for(int i = 0; i<parameters.size(); i++)
    {
        AudioProcessorParameterWithID* parameter = (AudioProcessorParameterWithID*)parameters.getUnchecked(i);
        inElement->setAttribute(parameter->paramID, parameter->getValue());
    }
}
void KAPPresetManager::loadPresetForXml(XmlElement* inElement)
{
    mCurrentPresetXml = inElement;
    
    auto& parameters = mProcessor->getParameters();
    
    for(int i = 0; i<parameters.size(); i++)
    {
        const String paramId = mCurrentPresetXml->getAttributeName(i);
        const double value =  mCurrentPresetXml->getDoubleAttribute(paramId);
        
        for(int j =0; j<parameters.size();j++)
        {
            AudioProcessorParameterWithID* parameter = (AudioProcessorParameterWithID*)parameters.getUnchecked(i);
            if(paramId == parameter->paramID)
            {
                parameter->setValueNotifyingHost(value);
            }
        
        }
    }
}


int KAPPresetManager::getNumberOfPresets()
{
    return mLocalPresets.size();
}

String KAPPresetManager::getPresetName(int inPresetIndex)
{
    return mLocalPresets[inPresetIndex].getFileNameWithoutExtension();
}

void KAPPresetManager::createNewPreset()
{
    auto& parameters = mProcessor->getParameters();
    
    for(int i =0; i<parameters.size(); i++)
    {
        AudioProcessorParameterWithID* parameter = (AudioProcessorParameterWithID*)parameters.getUnchecked(i);
        const float defaultValue = parameter->getDefaultValue();
        parameter->setValueNotifyingHost(defaultValue);
    }
    
    mCurrentPresetIsSaved =  false;
    mCurrentPresetName = "Untitled";
    
}

void KAPPresetManager::savePreset()
{
    MemoryBlock destinationData;
    mProcessor->getStateInformation(destinationData);
    
    mCurrentlyLoadedPreset.deleteFile();
    mCurrentlyLoadedPreset.appendData(destinationData.getData(), destinationData.getSize());
    mCurrentPresetIsSaved = true;
}

void KAPPresetManager::saveAsPreset(String inPresetName)
{
    File presetFile =  File(mPresetDirectory + directorySeperator + inPresetName + PRESET_FILE_EXTENSION);
    
    if(!presetFile.exists())
    {
        presetFile.create();
    }
    else {
        presetFile.deleteFile();
    }
    
    MemoryBlock destinationData;
    mProcessor->getStateInformation(destinationData);
    
    presetFile.appendData(destinationData.getData(), destinationData.getSize());
    
    mCurrentPresetIsSaved = true;
    mCurrentPresetName = inPresetName;
    
    storeLocalPreset();
    
}

void KAPPresetManager::loadPreset(int inPresetIndex)
{
    mCurrentlyLoadedPreset = mLocalPresets[inPresetIndex];
    
    MemoryBlock presetBinary;
    
    if(mCurrentlyLoadedPreset.loadFileAsData(presetBinary))
    {
        mCurrentPresetIsSaved = true;
        mCurrentPresetName = getPresetName(inPresetIndex);
        mProcessor->setStateInformation(presetBinary.getData(), (int)presetBinary.getSize());
    }
}

bool KAPPresetManager::getCurrentPresetIsSaved()
{
    return mCurrentPresetIsSaved;
}

String KAPPresetManager::getCurrentPresetName()
{
    return mCurrentPresetName;
}

void KAPPresetManager::storeLocalPreset()
{
    mLocalPresets.clear();
    
    for(DirectoryIterator di (File(mPresetDirectory), false,  "*"+(String)PRESET_FILE_EXTENSION,File::TypesOfFileToFind::findFiles); di.next();)
    {
        File preset = di.getFile();
        mLocalPresets.add(preset);
    }
}
