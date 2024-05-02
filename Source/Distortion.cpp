/*
  ==============================================================================

    Distortion.cpp
    Created: 2 Apr 2022 4:26:56pm
    Author:  William Holk

  ==============================================================================
*/

#include "Distortion.h"
#include <JuceHeader.h>
#include <cmath>
#include <math.h>
#include <iostream>

float Distortion::processSample(float x){
    
    float ampValues = pow(2, (numBits - 1));
    
    float y = (ceil(ampValues * x)) * (1/ampValues);
    
    return  y;
    
}


void Distortion::setBits(float newBits){
    if(newBits <= 24.f && newBits >= 1.f){
        numBits = newBits;
    }
}

void Distortion::setFs(float newFs){
    Fs = newFs;
}
