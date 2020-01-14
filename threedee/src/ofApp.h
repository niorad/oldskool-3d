#pragma once

#include "ofMain.h"
#include <iostream>
#include "ofxGui.h"

extern int screenWidth;
extern int screenHeight;

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    ofImage colorMap;
    ofImage heightMap;
    int mouseY;
    ofxFloatSlider scalingFactor;
    ofxIntSlider horizon;
    ofxIntSlider dist;
    ofxIntSlider height;
    ofxIntSlider rot;
    ofxPanel gui;
    int screenWidth = 640;
    int screenHeight = 480;
    float yBuffer[640];

		
};
