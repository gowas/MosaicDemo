//
//  main.cpp
//  MosaicDemo
//
//  Created by IKEDA Takehisa on 12/03/09.
//  Copyright (c) 2012 GOWAS LLC. All rights reserved.
//

#include "ofMain.h"

#include "testApp.h"
#include "ofAppGlutWindow.h"

//========================================================================
int main( ){

    ofAppGlutWindow window;
    
	ofSetupOpenGL(&window, 1024, 768, OF_WINDOW);

	ofRunApp( new testApp());
}
