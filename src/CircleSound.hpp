//
//  CircleSound.hpp
//  oFClappingMusic
//
//  Created by keita miyano on 2025/01/27.
//

#pragma once

#include "ofMain.h"
#include <stdio.h>

class CircleSound {
public:
    vector<bool> circleExists;
    float width = ofGetWidth();
    float margin;
    float padding;
    float radius;
    int numCircles;
    float speed = 0;
    float startX;
    
    CircleSound(float radius, float padding, vector<bool> circleExists) {
        this->radius = radius;
        this->padding = padding;
        this->circleExists = circleExists;
        this->numCircles = (int)circleExists.size();
        this->margin = (width - 2. * radius * numCircles - padding * 2.) / (numCircles + 1);
        this->startX = padding + margin;
    }
    
    void update(float speed) {
        this->speed = speed;
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
        startX += speed;
        
        float centerY = ofGetHeight() / 2;             // 縦方向の中央

        // 横一列に円を描画
        for (int i = 0; i < numCircles; i++) {
            if (circleExists[i]) {
                float x = startX + i * (2 * radius) + (i+1)*margin; // 各円のX座標
                x = formatX(x);
                ofSetColor(0, 0, 0);
                ofDrawCircle(x, centerY, radius);
            }
        }
    }
};