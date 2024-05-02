/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
DistortionAudioProcessorEditor::DistortionAudioProcessorEditor (DistortionAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (200, 200);
    
//    bitSlider.addListener(this);
    bitSlider.setSliderStyle(Slider::RotaryHorizontalVerticalDrag); // Circular knob
    bitSlider.setBounds(25,25,150,150); // position on GUI
    bitSlider.setRange(1.f,24.f,1.f);
    bitSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 30, 30);
//    bitSlider.setValue(*audioProcessor.bits);
    addAndMakeVisible(bitSlider);
    
    sliderAttachments.emplace_back(new AudioProcessorValueTreeState::SliderAttachment(audioProcessor.state, "bitParameter", bitSlider));
}

DistortionAudioProcessorEditor::~DistortionAudioProcessorEditor()
{
}

//==============================================================================
void DistortionAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Bits",50,-30,100,100,juce::Justification::centred,1 );
}

void DistortionAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}

//void DistortionAudioProcessorEditor::sliderValueChanged(Slider *slider){
//    if(slider == &bitSlider){
//        *audioProcessor.bits = bitSlider.getValue();
//    }
//}
