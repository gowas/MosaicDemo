//
//  testApp.h
//  MosaicDemo
//
//  Created by IKEDA Takehisa on 12/03/09.
//  Copyright (c) 2012 GOWAS LLC. All rights reserved.
//

#pragma once

#include "ofMain.h"
#include "ofxUI.h"

#include "Mosaic.h"

class testApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    void exit();
    
    void keyPressed  (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
protected:
    bool _dispGuiCanvas;
    
    ofxUICanvas *   _pGuiCanvas;
    void guiEventHandler(ofxUIEventArgs &e);
    
    ofImage * _pLogo;
    
    Mosaic * _pMosaic;
};
