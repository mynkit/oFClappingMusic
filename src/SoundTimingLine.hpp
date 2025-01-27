//
//  SoundTimingLine.hpp
//  oFClappingMusic
//
//  Created by keita miyano on 2025/01/27.
//

#pragma once

#include "ofMain.h"
#include <stdio.h>

class SoundTimingLine {
public:
    float padding;
    SoundTimingLine(float padding) {
        this->padding = padding;
    }
    
    void update() {
        
    }
    
    void draw() {
        ofSetColor(0);
        ofSetLineWidth(5);
        ofDrawLine(padding, padding, padding, ofGetHeight()-padding);
    }
};
