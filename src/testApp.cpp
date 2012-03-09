//
//  testApp.cpp
//  MosaicDemo
//
//  Created by IKEDA Takehisa on 12/03/09.
//  Copyright (c) 2012 GOWAS_LLC. All rights reserved.
//

#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofEnableSmoothing();
    
    ofBackground(190);
    ofSetFrameRate(60);
    
    _pGuiCanvas = new ofxUICanvas(0, 0, 380, 180);
    _pGuiCanvas->setColorBack(ofColor(0, 80));
    
    _pGuiCanvas->addWidgetDown(new ofxUILabel("GOWAS / Press 'h' to Hide GUIs", OFX_UI_FONT_LARGE));
    _pGuiCanvas->addWidgetDown(new ofxUISpacer(365, 1));
    _pGuiCanvas->addWidgetDown(new ofxUIFPS(OFX_UI_FONT_MEDIUM));
    _pGuiCanvas->addWidgetDown(new ofxUISpacer(365, 1));
    _pGuiCanvas->addWidgetDown(new ofxUIToggle(32, 32, false, "FULLSCREEN"));
    _pGuiCanvas->addWidgetDown(new ofxUIButton(32, 32, false, "RESET"));
    
    ofAddListener(_pGuiCanvas->newGUIEvent, this, &testApp::guiEventHandler); 
    
    //
    _pLogo = new ofImage();
    _pLogo->loadImage("gowas_logo_w.png");
    
    _pMosaic = new Mosaic(3000);
}

//--------------------------------------------------------------
void testApp::update(){
    _pMosaic->update(); 
}

//--------------------------------------------------------------
void testApp::draw(){
    ofPushStyle();
    
    ofSetColor(255, 127);
    _pLogo->draw((ofGetWidth() - _pLogo->getWidth()) / 2,
                 (ofGetHeight() - _pLogo->getHeight()) / 2);
    
    ofPopStyle();
    
    if (_pMosaic->isPlaying()) {
        _pMosaic->draw();
    }
}

//--------------------------------------------------------------
void testApp::exit() {
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    switch (key) {
        case 'h':
        case 'H':
            _pGuiCanvas->toggleVisible();
            break;
        default:
            break;
    }
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 
    
}

//--------------------------------------------------------------
//--------------------------------------------------------------
void testApp::guiEventHandler(ofxUIEventArgs &e) {
    if(e.widget->getName() == "FULLSCREEN") {
        ofxUIToggle * toggle = (ofxUIToggle *) e.widget;
        ofSetFullscreen(toggle->getValue());   
    } else if(e.widget->getName() == "RESET") {
        _pMosaic->start();
    }
}
