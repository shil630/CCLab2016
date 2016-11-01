#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(20,200,200);
    for(int i = 0; i<10; i++){
        size[i] = 0;
        alpha[i] = 200;
    }
    pos = ofVec2f(ofGetWindowHeight()*0.5,ofGetWindowWidth()*0.5);
    volocity = ofVec2f(0);
    friction = 0.99;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    count++;
    cout<<count<<endl;
//    if (volocity.length() > 0) {
//        volocity  *= ofVec2f(friction);
//        
//        if (volocity.length() < 0.01) {
//            volocity = ofVec2f(0);
//        }
//    
//    }
//    
//    if (volocity.length() > 0) {
//        pos += volocity;
//    
//    }
    for(int i = 0; i<10; i++){
        if(count/25>=i){
            size[i]++;
            alpha[i]-=0.6;
        }
    }
    
//    if (pos.x < 0) {
//        pos.x = ofGetWindowWidth();
//        
//    }
//    if (pos.x > ofGetWindowWidth()) {
//        pos.x = 0;
//    }
//    
//    if (pos.y < 0) {
//        pos.y = ofGetWindowHeight();
//    }
//    
//    if (pos.y > ofGetWindowHeight()) {
//        pos.y = 0;
//    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i = 0; i<10; i++){
        ofSetCircleResolution(100);
        ofSetColor(255, alpha[i]);
        ofDrawCircle(pos, size[i]);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){


}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    ofVec2f mousePos = ofVec2f(x,y);
    pos = mousePos;
    
    //    acceleration = pos - mousePos;
    //
    //    acceleration = acceleration.getNormalized();
    //
    //    volocity += acceleration;
    
    count = 0;
    
    for(int i = 0; i<10; i++){
        size[i] = 0;
        alpha[i] = 200;
    }
  
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
