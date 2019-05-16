/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class MaggsA3AudioProcessorEditor  : public AudioProcessorEditor
{
public:
    MaggsA3AudioProcessorEditor (MaggsA3AudioProcessor&, AudioProcessorValueTreeState&);
    ~MaggsA3AudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

    
private:
    
    MaggsA3AudioProcessor& processor;
    
    AudioProcessorValueTreeState& valueTreeState;
    
    //void buttonValueChanged(Button * shapeButton) override;
    
    //creating the attachment to connect my slider to the APVTS
    
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> panAttachment;
    
    //button Attacthments
    std::unique_ptr<AudioProcessorValueTreeState::ButtonAttachment> panSquareRootAttachment;
    std::unique_ptr<AudioProcessorValueTreeState::ButtonAttachment> panSineAttachment;
    std::unique_ptr<AudioProcessorValueTreeState::ButtonAttachment> panLinearAttachment;
    
    
    Slider panSlider;
    Label panLabel;
    ShapeButton panSqareRootButton;
    ShapeButton panSineButton;
    ShapeButton panLinearButton;
    
    
    

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MaggsA3AudioProcessorEditor)
};
