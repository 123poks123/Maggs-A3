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
: AudioProcessorEditor (&p), processor (p), valueTreeState(vts), panSqareRootButton("Pan Sqrt", Colours::ivory, Colours::lightslategrey, Colours::darkslategrey), panSineButton("Pan Sine", Colours::ivory, Colours::lightslategrey, Colours::darkslategrey),  panLinearButton("Pan Linear", Colours::ivory, Colours::lightslategrey, Colours::darkslategrey)

{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setOpaque(true);
    setResizable(false, false);
    setResizeLimits(720, 480, 720, 480);
    
    bgImage = ImageCache::getFromMemory(BinaryData::photo14644573120353d7d0e0c058e_jpeg, BinaryData::photo14644573120353d7d0e0c058e_jpegSize);
    
    
    panSlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    
    panSlider.setTextValueSuffix("Pan");
    panSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 100, 20);
    panSlider.setColour(Slider::ColourIds::rotarySliderFillColourId, Colours::ivory);
    panSlider.setNumDecimalPlacesToDisplay(1.0f);
    //panLabel.setText("Pan", dontSendNotification);
    //panLabel.attachToComponent(&panSlider, false);
    panAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment (valueTreeState, "pan" , panSlider));
    
    
    //Make Shape for button
    
    Path shape;
    shape.addEllipse(0, 0, 50, 50);
    
    
    
    //Initialize Buttons / make them toggleable to see this you need to make the on colours different so you can see when they are on.
    
    //PanSqrt
    
    panSqareRootButton.setRadioGroupId(1);
    panSqareRootButton.setClickingTogglesState(true);
    panSqareRootButton.shouldUseOnColours(true);
    panSqareRootButton.setOnColours(Colours::darkslategrey, Colours::ivory, Colours::lightslategrey);
    panSqareRootButton.setShape(shape, true, true, true);
    panSquareRootAttachment.reset(new AudioProcessorValueTreeState::ButtonAttachment(valueTreeState, "pan squareroot", panSqareRootButton));
    
    // Pan sine
    
    panSineButton.setRadioGroupId(1);
    panSineButton.setClickingTogglesState(true);
    panSineButton.shouldUseOnColours(true);
    panSineButton.setOnColours(Colours::darkslategrey, Colours::ivory, Colours::lightslategrey);
    panSineButton.setShape(shape, true, true, true);
    panSineAttachment.reset(new AudioProcessorValueTreeState::ButtonAttachment(valueTreeState, "pan sine", panSineButton));
    //Pan Linear
    
    panLinearButton.setRadioGroupId(1);
    panLinearButton.setClickingTogglesState(true);
    panLinearButton.shouldUseOnColours(true);
    panLinearButton.setOnColours(Colours::darkslategrey, Colours::ivory, Colours::lightslategrey);
    panLinearButton.setShape(shape, true, true, true);
    panLinearAttachment.reset(new AudioProcessorValueTreeState::ButtonAttachment(valueTreeState, "pan linear", panLinearButton));
    
    addAndMakeVisible(panSqareRootButton);
    addAndMakeVisible(panSineButton);
    addAndMakeVisible(panLinearButton);
    addAndMakeVisible(panSlider);
    
}

MaggsA3AudioProcessorEditor::~MaggsA3AudioProcessorEditor()
{
}

//==============================================================================
void MaggsA3AudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll(Colours::black);
    
    g.drawImageWithin(bgImage, 0, 0, getWidth(), getHeight(), RectanglePlacement::fillDestination);
    
    g.setColour(Colours::black);
    g.setOpacity(0.50f);
    g.drawRect(230, 5, (getWidth()/2.5), getHeight()/7.5);
    g.fillRect(233, 8, (getWidth()/2.5-6), getHeight()/7.5-6);
    
    g.setColour(Colours::black);
    g.setOpacity(0.50f);
    g.drawRect(250, 116, (getWidth()/3.3), getHeight()/1.95);
    g.fillRect(253, 119, (getWidth()/3.3-6), getHeight()/1.95-6);
    
    
    
    g.setColour(Colours::ghostwhite);
    g.setFont (Font("Herculanum", 45.0f, Font::italic));
    g.drawFittedText("Panagram", 15 , 12, getWidth(), 50, Justification::centredTop, 1);
    
   
    //button backing
    
    g.setColour(Colours::black);
    g.setOpacity(0.50f);
    g.drawRect(9, 116, (getWidth()/3.85), (getHeight()/1.95));
    g.fillRect(12, 119, (getWidth()/3.85-6), (getHeight()/1.95-6));
    
    
    g.setColour (Colours::ghostwhite);
    g.setFont (Font("Herculanum", 25.0f, Font::italic));
    g.drawFittedText ("Pan", getLocalBounds(), Justification::centred, 1);
    
   
    
    g.setColour (Colours::ghostwhite);
    g.setFont (Font("Herculanum", 25.0f, Font::italic));
    g.drawFittedText("Linear", 100, 120, 80, 80, Justification::left, 1);
    
    g.setColour (Colours::ghostwhite);
    g.setFont (Font("Herculanum", 25.0f, Font::italic));
    g.drawFittedText("Sine", 100, 200, 80, 80, Justification::left, 1);
    
    g.setColour (Colours::ghostwhite);
    g.setFont (Font("Herculanum", 25.0f, Font::italic));
    g.drawFittedText("Square", 100, 275, 80, 80, Justification::left, 1);
    
    g.setColour (Colours::ghostwhite);
    g.setFont (Font("Herculanum", 25.0f, Font::italic));
    g.drawFittedText("-Root", 100, 295, 80, 80, Justification::left, 1);
   
}

void MaggsA3AudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    auto r = getLocalBounds();
    
    auto padding = getWidth() * 0.05;
    auto sliderHeight = getHeight() * 0.25;
    auto sides = getWidth() * 0.25;
    
    auto bottomSection = r.removeFromBottom(sliderHeight);
    auto topSection = r.removeFromTop(sliderHeight);
    
    auto leftSide = r.removeFromLeft(sides);
    auto rightSide = r.removeFromRight(sides);
    
    
   
    panSlider.setBounds(r);
    
    auto spacing = leftSide.getHeight()/3;
    
    panLinearButton.setBounds(15.5, 130, 50, 50);
    panSineButton.setBounds(15.5, 210, 50, 50);
    panSqareRootButton.setBounds(15.5, 290, 50, 50);
}
    


