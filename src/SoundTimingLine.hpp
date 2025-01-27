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
        
        this->x += speed;
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
        ofSetLineWidth(5);
        float newX = formatX(x);
        ofDrawLine(newX, padding, newX, ofGetHeight()-padding);
    }
};
