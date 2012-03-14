//
//  ofxMosaic.h
//
//  Created by IKEDA Takehisa on 12/03/10.
//  Copyright (c) 2012 GOWAS LLC. All rights reserved.
//

#ifndef OFX_MOSAIC_H
#define OFX_MOSAIC_H

#include "ofMain.h"
#include "ofxMosaicEventArgs.h"

enum MosaicStage {
    none = 0,
    first = 1,
    separated = 2,
    fadeout = 3,
    end = 4
};

class ofxMosaic {
    
public:
    ofxMosaic(int cycleTimeMillis = 5000, int mosaicMaxSize = 20);
    ~ofxMosaic();

    void init(int cycleTimeMillis, int mosaicMaxSize);

    void update();
    void draw();

    void start();
    bool isPlaying();

    ofEvent<ofxMosaicEventArgs> mosaicStartEvent;
    ofEvent<ofxMosaicEventArgs> mosaicEndEvent;

protected:
    int _cycleTimeMillis;
    int _startTimeMillis;
    
    int _mosaicMaxSize;

    int _counter;

    ofImage * _pScreenForMosaic;

    MosaicStage _stage;

    int _mosaicSize;
    int _mosaicAlpha;

    void reset();

    ofxMosaicEventArgs * _pMosaicEvent;
};

#endif
