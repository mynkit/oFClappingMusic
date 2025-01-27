//
//  CircleSound.hpp
//  oFClappingMusic
//
//  Created by keita miyano on 2025/01/27.
//

#pragma once

#include "ofMain.h"
#include "ofxOsc.h"

#define HOST "localhost"
#define SDPORT 57120

class CircleSound {
public:
    vector<bool> circleExists;
    vector<bool> circlePlayStanby;
    float width = ofGetWidth();
    float margin;
    float padding;
    float radius;
    int numCircles;
    float speed = 0;
    float startX;
    float centerY;
    float * soundTimingLineX;
    
    // OSC
    ofxOscSender sdSender;
    float latency;
    
    CircleSound(float radius, float padding, float centerY, vector<bool> circleExists, float * soundTimingLineX) {
        this->radius = radius;
        this->padding = padding;
        this->circleExists = circleExists;
        this->numCircles = (int)circleExists.size();
        this->circlePlayStanby.resize(numCircles);
        for (int i=0; i<numCircles; i++) {
            this->circlePlayStanby[i] = 1.;
        }
        this->margin = (width - 2. * radius * numCircles - padding * 2.) / (numCircles);
        this->startX = padding + margin*0.5 + radius * 1;
        this->centerY = centerY;
        this->soundTimingLineX = soundTimingLineX;
        
        // OSC
        sdSender.setup(HOST, SDPORT);
        latency = 0.1;
    }
    
    void playGagaku(float amp, float up) {
        ofxOscMessage m;
        m.setAddress("/dirt/play");
        m.addStringArg("s");
        m.addStringArg("gagaku");
        m.addStringArg("n");
        m.addFloatArg(1);
        m.addStringArg("amp");
        m.addFloatArg(amp);
        m.addStringArg("up");
        m.addFloatArg(up);
//        m.addStringArg("room");
//        m.addFloatArg(0.95);
//        m.addStringArg("size");
//        m.addFloatArg(0.95);
        m.addStringArg("theta");
        m.addFloatArg(0);
        m.addStringArg("orbit");
        m.addIntArg(1);
        m.addStringArg("latency");
        m.addFloatArg(latency);
        sdSender.sendMessage(m, false);
        m.clear();
    }
    
    void update(float speed) {
        this->speed = speed;
        
        startX = formatX(startX + speed);
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
        // 横一列に円を描画
        ofPushStyle();
        ofSetLineWidth(2.5);
        for (int i = 0; i < numCircles; i++) {
            if (circleExists[i]) {
                float x = startX + i * (2 * radius) + i*margin;
                x = formatX(x);
                ofSetColor(0, 0, 0);
                if(*soundTimingLineX>=x && *soundTimingLineX<x+radius) {
                    ofFill();
                    if (circlePlayStanby[i]) {
                        playGagaku(0.5, 0);
                        circlePlayStanby[i] = 0.;
                    }
                } else {
                    ofNoFill();
                    circlePlayStanby[i] = 1.;
                }
                ofDrawCircle(x, centerY, radius);
            }
        }
        ofPopStyle();
    }
    
};
