//
//  Mosaic.h
//  MosaicDemo
//
//  Created by IKEDA Takehisa on 12/03/09.
//  Copyright (c) 2012 GOWAS_LLC. All rights reserved.
//

#ifndef MosaicDemo_Mosaic_h
#define MosaicDemo_Mosaic_h

#include "ofMain.h"

enum mosaicStage {
    none = 0,
    first = 1,
    separated = 2,
    fadeout = 3,
    end = 4
};

class Mosaic {
    
public:
    Mosaic(int cycleTimeMillis = 5000);
    ~Mosaic();
    
    void init(int cycleTimeMillis);
    
    void update();
    void draw();
    
    void start();
    bool isPlaying();
    
protected:
    int _cycleTimeMillis;
    int _startTimeMillis;
    
    int _counter;
    
    ofImage * _pScreenForMosaic;
    
    ofColor _mosaicColor;
    
    mosaicStage _stage;
    
    int _mosaicSize;
    int _mosaicAlpha;
    
    void reset();
};

#endif
