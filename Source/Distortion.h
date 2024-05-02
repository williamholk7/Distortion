/*
  ==============================================================================

    Distortion.h
    Created: 9 Apr 2022 4:26:56pm
    Author:  William Holk

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class Distortion {
  
public:
    float processSample(float x);
    
    void setBits(float newBits);
    
    void setFs(float newFs);

private:
    float Fs = 48000.f;
    float numBits = 4.f;
    
};
