//
//  SoundTimingLine.hpp
//  oFClappingMusic
//
//  Created by keita miyano on 2025/01/27.
//

#pragma once

#include "ofMain.h"

class SoundTimingLine {
public:
    float width = ofGetWidth();
    float padding;
    float speed;
    float x = padding;
    SoundTimingLine(float padding) {
        this->padding = padding;
        this->x = padding;
    }
    
    void update(float speed) {
        this->speed = speed;
        
        x = formatX(x + speed);
    }
    
    float formatX(float x) {
        if (x < padding) {
            x += (width - padding * 2.);
        }
        else if (x > width - padding) {
            x -= (width - padding * 2.);
        }
        return x;
    }
    
    void draw() {
        ofSetColor(0);
        ofSetLineWidth(3);
        ofDrawLine(x, padding, x, ofGetHeight()-padding);
    }
};
