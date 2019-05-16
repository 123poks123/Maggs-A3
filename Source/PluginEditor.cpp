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
: AudioProcessorEditor (&p), processor (p), valueTreeState(vts), panSqareRootButton("Pan Sqrt", Colours::skyblue, Colours::turquoise , Colours::limegreen), panSineButton("Pan Sine", Colours::skyblue, Colours::turquoise ,Colours::limegreen),  panLinearButton("Pan Linear", Colours::skyblue, Colours::turquoise , Colours::limegreen)

{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setOpaque(true);
    setResizable(true, true);
    setResizeLimits(500, 350, 1280, 1080);
    
    
    panSlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    
    panSlider.setTextValueSuffix("Pan");
    panSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 100, 20);
    panSlider.setColour(Slider::ColourIds::rotarySliderFillColourId, Colours::blueviolet);
    panSlider.setNumDecimalPlacesToDisplay(1.0f);
    //panLabel.setText("Pan", dontSendNotification);
    //panLabel.attachToComponent(&panSlider, false);
    panAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment (valueTreeState, "pan" , panSlider));
    
    
    //Make Shape for button
    
    Path shape;
    shape.addEllipse(31, 31, 31, 31);
    
    
    
    //Initialize Buttons / make them toggleable to see this you need to make the on colours different so you can see when they are on.
    
    //PanSqrt
    
    panSqareRootButton.setRadioGroupId(1);
    panSqareRootButton.setClickingTogglesState(true);
    panSqareRootButton.shouldUseOnColours(true);
    panSqareRootButton.setOnColours(Colours::limegreen, Colours::darkgreen, Colours::skyblue);
    panSqareRootButton.setShape(shape, true, true, true);
    panSquareRootAttachment.reset(new AudioProcessorValueTreeState::ButtonAttachment(valueTreeState, "pan squareroot", panSqareRootButton));
    
    
    
    
    
    // Pan sine
    
    panSineButton.setRadioGroupId(1);
    panSineButton.setClickingTogglesState(true);
    panSineButton.shouldUseOnColours(true);
    panSineButton.setOnColours(Colours::limegreen, Colours::darkgreen, Colours::skyblue);
    panSineButton.setShape(shape, true, true, true);
    panSineAttachment.reset(new AudioProcessorValueTreeState::ButtonAttachment(valueTreeState, "pan sine", panSineButton));
    //Pan Linear
    
    panLinearButton.setRadioGroupId(1);
    panLinearButton.setClickingTogglesState(true);
    panLinearButton.shouldUseOnColours(true);
    panLinearButton.setOnColours(Colours::limegreen, Colours::darkgreen, Colours::skyblue);
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
    
    g.setColour(Colours::blueviolet);
    g.drawRect(3, 5, (getWidth()-5), 50);
    g.fillRect(6, 8, (getWidth()-11), 44);
    
    
    g.setColour(Colours::ghostwhite);
    g.setFont (Font("Calibri", 38.0f, Font::italic));
    g.drawFittedText("Panagram", 10 , 12, getWidth(), 50, Justification::centredTop, 1);
    
   
    
    
    g.setColour(Colours::blueviolet);
    g.drawRect(3, 73, 134, 44);
    g.fillRect(5, 75, 130, 40);
    
    g.setColour (Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Pan", getLocalBounds(), Justification::centred, 1);
   
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
    
    panLinearButton.setBounds(5, 75, 40, 40);
    panSineButton.setBounds(50, 75, 40, 40);
    panSqareRootButton.setBounds(95, 75, 40, 40);
}
    


