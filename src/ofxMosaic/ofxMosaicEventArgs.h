//
//  ofxMosaicEventArgs.h
//
//  Created by IKEDA Takehisa on 12/03/10.
//  Copyright (c) 2012 GOWAS LLC. All rights reserved.
//

#ifndef OFX_MOSAIC_EVENT_ARGS_H
#define OFX_MOSAIC_EVENT_ARGS_H

#include "ofMain.h"

class ofxMosaicEventArgs : public ofEventArgs
{   
public:
	ofxMosaicEventArgs() {
        cycleTimeMillis = 0;
        mosaicMaxSize = 0;
    }

    ~ofxMosaicEventArgs() {
    }
    
    int mosaicMaxSize;
    int cycleTimeMillis;
    bool loop;
}; 

#endif
