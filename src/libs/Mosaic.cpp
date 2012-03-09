//
//  Mosaic.cpp
//  MosaicDemo
//
//  Created by IKEDA Takehisa on 12/03/09.
//  Copyright (c) 2012 GOWAS LLC. All rights reserved.
//

#include "Mosaic.h"

//--------------------------------------------------------------
Mosaic::Mosaic(int cycleTimeMillis) {
    _pScreenForMosaic = NULL;
    
    init(cycleTimeMillis);
}

//--------------------------------------------------------------
Mosaic::~Mosaic() {
    if (_pScreenForMosaic != NULL) {
        delete _pScreenForMosaic;
    }
}

//--------------------------------------------------------------
void Mosaic::init(int cycleTimeMillis){
    _cycleTimeMillis = cycleTimeMillis;
    
    _pScreenForMosaic = new ofImage();
    
    reset();
}

//--------------------------------------------------------------
void Mosaic::update(){
    if (_stage == none) {
        if ((ofGetElapsedTimeMillis() - _startTimeMillis) > _cycleTimeMillis) {
            start();
        }
    } else {
        _counter++;
        
        switch (_stage) {
            case first:
                if (_counter == 2) {
                    _stage = separated;
                }
                break;
            case separated:
                if (_mosaicSize == 20) {
                    _stage = fadeout;
                } else {
                    if (_counter % 3 == 0) {
                        _mosaicSize++;
                    }
                }
                break;
            case fadeout:
                if (_mosaicAlpha < 25) {
                    _stage = end;
                } else {
                    _mosaicAlpha -= 5;
                }
                break;
            case end:
                reset();
                break;
            default:
                break;
        }
        
        /* std::cout << "mosaicSize  :" << _mosaicSize << std::endl; */
        /* std::cout << "mosaicAlpha :" << _mosaicAlpha << std::endl; */
    }
}

//--------------------------------------------------------------
void Mosaic::draw(){
    if (_stage != none) {
        int screenWidth = _pScreenForMosaic->width;
        int screenHeight = _pScreenForMosaic->height;
        
        ofPushStyle();
        
        ofFill();
        
        switch (_stage) {
            case first:
                _pScreenForMosaic->draw(0, 0, screenWidth, screenHeight);
                break;
            case separated:
                for (int i = 0; i < screenWidth; i += _mosaicSize) {
                    for (int j = 0; j < screenHeight; j += _mosaicSize) {
                        ofColor color = _pScreenForMosaic->getColor(i, j);
                        ofSetColor(color);
                        ofRect(i, j, (_mosaicSize - 1), (_mosaicSize - 1));
                    }
                }
                break;
            case fadeout:
                for (int i = 0; i < screenWidth; i += _mosaicSize) {
                    for (int j = 0; j < screenHeight; j += _mosaicSize) {
                        ofColor color = _pScreenForMosaic->getColor(i, j);
                        ofSetColor(color.r, color.g, color.b, _mosaicAlpha);
                        
                        ofRect(i, j, (_mosaicSize - 1), (_mosaicSize - 1));
                    }
                }
                break;
            default:
                break;
        }
        
        ofPopStyle();
    }
}

//--------------------------------------------------------------
void Mosaic::start() {
    _counter = 0;
    
    _stage = first;
    
    _mosaicSize = 2;
    _mosaicAlpha = 255;
    
    _pScreenForMosaic->grabScreen(0, 0, ofGetWidth(), ofGetHeight());
}

//--------------------------------------------------------------
bool Mosaic::isPlaying() {
    return (_stage != none);
}

//--------------------------------------------------------------
void Mosaic::reset() {
    _startTimeMillis = ofGetElapsedTimeMillis();
    
    _counter = 0;
    
    _stage = none;
    
    _mosaicSize = 0;
    _mosaicAlpha = 0;
}
