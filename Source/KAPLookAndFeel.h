/*
 ==============================================================================
 
 KAPLookAndFeel.h
 Created: 9 Jun 2020 7:43:57pm
 Author:  Sebastian Badon
 
 ==============================================================================
 */

#pragma once

#include "JuceHeader.h"
#include "KAPInterfaceDefines.h"

class KAPLookAndFeel :
public LookAndFeel_V4
{
public:
    KAPLookAndFeel()
    {
        //Store image assets
        mSliderImage = ImageCache::getFromMemory(BinaryData::kadenze_knob_png, BinaryData::kadenze_knob_pngSize);
        
        //ComboBox colours
        setColour(ComboBox::backgroundColourId, KAPColour_3);
        setColour(ComboBox::outlineColourId, KAPColour_2);
        setColour(ComboBox::arrowColourId, KAPColour_1);
        setColour(ComboBox::textColourId, KAPColour_1);
        
        //Button text colours
        setColour(TextButton::buttonColourId, KAPColour_1);
        setColour(TextButton::textColourOnId, KAPColour_1);
        setColour(TextButton::textColourOffId, KAPColour_1);
    }
    virtual ~KAPLookAndFeel()
    {
        
    }
    
    Font getTextButtonFont (TextButton&, int buttonHeight) override
    {
        return font_1;
    }
    
    void drawButtonBackground (Graphics& g,
                               Button& button,
                               const Colour& backgroundColour,
                               bool isMouseOverButton,
                               bool isButtonDown) override
    {
        Colour fillColour;
        
        if(isButtonDown)
        {
            fillColour = KAPColour_6;
        }
        else if(isMouseOverButton)
        {
            fillColour = KAPColour_3;
        }
        else {
            fillColour = KAPColour_5;
        }
        
        const float cornerSize = 6.0f;
        const juce::Rectangle<float> bounds = button.getLocalBounds().toFloat().reduced(0.5f, 0.5f);
        
        g.setColour(fillColour);
        g.fillRoundedRectangle(bounds.reduced(1), cornerSize);
        
        
    }
    
    Font getLabelFont(Label& label) override
    {
        return font_1;
    }
    
    void drawPopupMenuItem (Graphics& g, const Rectangle<int>& area,
                            const bool isSeparator, const bool isActive,
                            const bool isHighlighted, const bool isTicked,
                            const bool hasSubMenu, const String& text,
                            const String& shortcutKeyText,
                            const Drawable* icon, const Colour* const textColourToUse) override
    {
        juce::Rectangle<int> r (area);
        
        Colour fillColour = (isHighlighted) ? KAPColour_5 : KAPColour_4;
        g.setColour(fillColour);
        
        g.fillRect(r.getX(), r.getY(), r.getWidth(), r.getHeight()-1);
        
        Colour textColour = isTicked ? KAPColour_7 : KAPColour_1;
        g.setColour(textColour);
        g.setFont(font_1);
        
        r.setLeft(10);
        r.setY(1);
        
        g.drawFittedText(text, r, Justification::left,1);
    }
    
    void drawComboBox (Graphics& g, int width, int height, bool isButtonDown,
                       int buttonX, int buttonY, int buttonW, int buttonH,
                       ComboBox& box) override
    {
        const float cornerSize = 3.0f;
        const juce::Rectangle<int> boxBounds (0,0,width, height);
        
        g.setColour(KAPColour_3);
        g.fillRoundedRectangle(boxBounds.toFloat(), cornerSize);
        
        juce::Rectangle<int> arrow (width - 30, 0, 20, height);
        
        Path path;
        
        path.startNewSubPath(arrow.getX()+3.0f, arrow.getCentreY()-2.0f);
        path.lineTo(arrow.toFloat().getCentreX(),arrow.toFloat().getCentreY()+3.0f);
        path.lineTo(arrow.toFloat().getRight() - 3.0f,arrow.toFloat().getCentreY()-2.0f);
        
        Colour arrowColour = box.findColour(ComboBox::arrowColourId).withAlpha(box.isEnabled() ? 0.9f : 0.2f);
        g.setColour(arrowColour);
        g.strokePath(path, PathStrokeType(2.0f));
        
    }
    
    void drawRotarySlider (Graphics& g, int x, int y, int width, int height,
                           float sliderPosProportional, float rotaryStartAngle,
                           float rotaryEndAngle, Slider&) override
    {
        const int numFrames = mSliderImage.getHeight() / mSliderImage.getWidth();
        const int frameIndex = (int)std::ceil(sliderPosProportional * (numFrames - 1));
        
        const float radius = jmin(width*0.5, height *0.5);
        const float centreX = x + width *0.5f;
        const float centreY = y + height* 0.5f;
        const float rx = centreX - radius;
        const float ry = centreY - radius;
        
        g.drawImage(mSliderImage,
                    rx,
                    ry,
                    2*radius,
                    2*radius,
                    0,
                    frameIndex*mSliderImage.getWidth(),mSliderImage.getWidth(),mSliderImage.getWidth());
    }
    
    
    
private:
    
    Image mSliderImage;
};
