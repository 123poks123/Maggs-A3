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
    
    
    
    //creating the attachment to connect my slider to the APVTS
    
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> panAttahcment;
    
    Slider panSlider;
    Label panLabel;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MaggsA3AudioProcessorEditor)
};
