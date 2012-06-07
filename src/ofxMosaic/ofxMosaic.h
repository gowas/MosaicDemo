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

class ofxMosaic {
    
public:
    ofxMosaic(int mosaicMaxSize);
    ~ofxMosaic();

    void init(int mosaicMaxSize);

    void update();
    void draw();

    void start();
    bool isPlaying();
    
    void startLoop(int cycleTimeMillis);
    void stopLoop();
    
    bool isLoop();

    ofEvent<ofxMosaicEventArgs> mosaicStartEvent;
    ofEvent<ofxMosaicEventArgs> mosaicEndEvent;

protected:
    int _cycleTimeMillis;
    int _lastRunTimeMillis;
    
    bool _loop;
    
    int _mosaicMaxSize;

    int _counter;

    ofImage * _pScreenForMosaic;

    enum {
        none = 0,
        ready = 1,
        first = 2,
        separated = 3,
        fadeout = 4,
        end = 5
    } _stage;

    int _mosaicSize;
    int _mosaicAlpha;

    void reset();

    ofxMosaicEventArgs * _pMosaicEvent;
};

#endif
