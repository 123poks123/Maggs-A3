/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
MaggsA3AudioProcessor::MaggsA3AudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       ), parameters(*this, nullptr, Identifier("Pan"),
                                     
                                     {
                                         //add that list of parameters that you think the plugin will have
                                         std::make_unique<AudioParameterFloat>("pan" , //parameter ID
                                                                               "Pan" , //Parameter Name
                                                                               -100.0f, //min value
                                                                               100.0f, //Max Value
                                                                               0.0f //Default Value
                                                                               ),
                                         
                                         std::make_unique<AudioParameterBool>("pan squareroot",//parameter ID
                                                                              "Pan SquareRoot", // Parameter Name
                                                                              true), //defualt stat
                                         
                                         std::make_unique<AudioParameterBool>("pan sine",//parameter ID
                                                                              "Pan Sine", // Parameter Name
                                                                              false), //defualt stat
                                         
                                         std::make_unique<AudioParameterBool>("pan linear",//parameter ID
                                                                              "Pan Linear", // Parameter Name
                                                                              false) //defualt stat
                                     }
                            )

#endif
{
     panParameter = parameters.getRawParameterValue("pan");

    panSquareRoot = parameters.getRawParameterValue("pan squareroot");
    panSine = parameters.getRawParameterValue("pan sine");
    panLinear = parameters.getRawParameterValue("pan linear");
    
    
    
}

MaggsA3AudioProcessor::~MaggsA3AudioProcessor()
{
}

//==============================================================================
const String MaggsA3AudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool MaggsA3AudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool MaggsA3AudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool MaggsA3AudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double MaggsA3AudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int MaggsA3AudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int MaggsA3AudioProcessor::getCurrentProgram()
{
    return 0;
}

void MaggsA3AudioProcessor::setCurrentProgram (int index)
{
}

const String MaggsA3AudioProcessor::getProgramName (int index)
{
    return {};
}

void MaggsA3AudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void MaggsA3AudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    
    
}

void MaggsA3AudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool MaggsA3AudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void MaggsA3AudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

  
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    AudioBuffer<float> wetBuffer(getTotalNumInputChannels(), buffer.getNumSamples());
    wetBuffer.makeCopyOf(buffer);
  
    for (int channel = 0; channel < totalNumOutputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);
        auto* wetData = wetBuffer.getWritePointer(channel);
        
        //Implement Pan Fucntion
        //Pan pot / range + 0.5
        auto channelAmplitude = *panParameter /200.0f + 0.5f;
        
       
        
        for(int sample = 0; sample < buffer.getNumSamples(); sample++)
        {
        
        if (channel == 0 && *panSquareRoot ==  1)
        {
            
            //Square Root panning
           channelData[sample] = wetData[sample] * (sqrt(1-channelAmplitude));
            
        }
            else if (channel == 1 && *panSquareRoot == 1)
            {
                //Square Root panning
               channelData[sample] = wetData[sample] * (sqrt(channelAmplitude));
                
            }
            
            else if (channel == 0 && *panSine == 1)
            {
                //Sine panning
                channelData[sample] = wetData[sample] * (sin((1-channelAmplitude)* MathConstants<float>::pi/2));
                
            }
            
            else if (channel == 1 && *panSine == 1)
            {
                //Sine panning
                channelData[sample] = wetData[sample] * (sin(channelAmplitude)* MathConstants<float>::pi/2);
                
            }
            
            else if (channel == 0 && *panLinear == 1)
            {
                //Linear panning
                channelData[sample] = wetData[sample] * (1-channelAmplitude);
                
            }
            
            else if (channel == 1 && *panLinear == 1)
            {
                //Linear panning
                channelData[sample] = wetData[sample] * channelAmplitude;
                
            }

        }
    }
}

//==============================================================================
bool MaggsA3AudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* MaggsA3AudioProcessor::createEditor()
{
    return new MaggsA3AudioProcessorEditor (*this, parameters);
}

//==============================================================================
void MaggsA3AudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
    
    auto state = parameters.copyState();
    std::unique_ptr<XmlElement> xml(state.createXml());
    copyXmlToBinary(*xml, destData);
}

void MaggsA3AudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
    
    std::unique_ptr<XmlElement> xmlState (getXmlFromBinary(data, sizeInBytes));
    
    if(xmlState.get() != nullptr)
    {
        if(xmlState->hasTagName(parameters.state.getType()))
        {
            parameters.replaceState(ValueTree::fromXml(*xmlState));
        }
    }
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new MaggsA3AudioProcessor();
}
