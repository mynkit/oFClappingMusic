#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    padding = ofGetWidth() / 10;
    soundTimingLine = new SoundTimingLine(padding);
    circleSound1 = new CircleSound(20, padding, {1,1,0,1,1,0,1,0,1,1,0,1});
}

//--------------------------------------------------------------
void ofApp::update(){
    circleSound1->update(0.);
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255);
    
    soundTimingLine->draw();
    
    circleSound1->draw();
    
    ofSetColor(250);
    ofDrawRectangle(0, 0, padding, ofGetHeight());
    ofDrawRectangle(ofGetWidth()-padding, 0, padding, ofGetHeight());

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}