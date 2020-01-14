#include "ofApp.h"





//--------------------------------------------------------------
void ofApp::setup() {
    heightMap.load("images/height2.png");
    heightMap.setImageType(OF_IMAGE_GRAYSCALE);
    colorMap.load("images/color2.png");
    gui.setup();
    gui.add(scalingFactor.setup("scaling", 50.f, 1.f, 100.f));
    gui.add(horizon.setup("Horizon", 360, -1000, 1000));
    gui.add(height.setup("Height", -10000, -15000, -1000));
    gui.add(dist.setup("Distance", 250, 10, 500));
//    gui.add(rot.setup("Rotation", 0, -90, 90));
    
    for(int i = 0; i < screenWidth; i++) {
        yBuffer[i] = 0;
    }
    
    ofBackground(100,100,200);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
        
    int posY = mouseY;
    
    
    for(int i = 0; i < screenWidth; i++) {
        yBuffer[i] = 0;
    }
    
    for(int i = 0; i < dist; i++) {
        
        int leftPos = -i + screenWidth / 2;
        int rightPos = i + screenWidth / 2;
        
        int leftPosOnImg = ofMap(leftPos, 0, screenWidth, 0, 1024);
        int rightPosOnImg = 1024 - leftPosOnImg;
                
        for(int x = 0; x < screenWidth; x++) {
                      
            int sourceX = ((int)(ofMap(x, 0, screenWidth, leftPosOnImg, rightPosOnImg) + mouseX) % 1024);
            int sourceY = ((int)ofMap(i + posY, 0, screenHeight, 0, 1024) % 1024);
            
            ofVec2f source(sourceX, sourceY);
            ofVec2f rotSource = source.getRotated(mouseX);

            ofColor heightCol = heightMap.getColor(rotSource.x, rotSource.y);
            ofColor terrainCol = colorMap.getColor(rotSource.x, rotSource.y);
       
            ofSetColor(terrainCol);
            ofFill();
            
            float calculatedHeight = (height-heightCol.r*-scalingFactor) / i  + horizon;
                        
            float segmentHeight = calculatedHeight - yBuffer[x];
            
            if(segmentHeight > 0) {

                yBuffer[x] = calculatedHeight;
                ofDrawRectangle(x, (float)screenHeight - yBuffer[x], 3, -segmentHeight);
            }
            
            

       }
   }
    
    gui.draw();



}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    mouseY = y;
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
