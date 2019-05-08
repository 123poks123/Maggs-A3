/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
MaggsA3AudioProcessorEditor::MaggsA3AudioProcessorEditor (MaggsA3AudioProcessor& p, AudioProcessorValueTreeState& vts)
: AudioProcessorEditor (&p), processor (p), valueTreeState(vts)

{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setOpaque(true);
    setResizable(true, true);
    setResizeLimits(400, 300, 1280, 1080);
    
    
    panSlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    
    panSlider.setTextValueSuffix("Pan");
    panSlider.setColour(Slider::ColourIds::rotarySliderFillColourId, Colours::orange);
    panSlider.setNumDecimalPlacesToDisplay(1.0f);
    panLabel.setText("Pan", dontSendNotification);
    panLabel.attachToComponent(&panSlider, false);
    panAttahcment.reset(new AudioProcessorValueTreeState::SliderAttachment (valueTreeState, "pan" , panSlider));
    
    addAndMakeVisible(panLabel);
    addAndMakeVisible(panSlider);
    
}

MaggsA3AudioProcessorEditor::~MaggsA3AudioProcessorEditor()
{
}

//==============================================================================
void MaggsA3AudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), Justification::centred, 1);
}

void MaggsA3AudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    auto r = getLocalBounds();
    
    auto padding = getWidth() * 0.05;
    auto sliderHeight = getHeight() * 0.25;
    
    auto topSection = r.removeFromTop(sliderHeight);
    
    
    panSlider.setBounds(r.removeFromLeft(getWidth()/2));
}
    



