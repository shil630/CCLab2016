#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
//    ofSetBackgroundColor(0, 0, 0);
    ofBackground(0, 0, 0);
    
    //allocate the particles
    for(int i = 0; i < ofGetWindowWidth(); i+=10) {
        for (int j = 0; j < ofGetWindowHeight(); j += 10) {
            particle temParticle(ofVec2f(i, j));
            mParticles.push_back(temParticle);
        }
    }
    
    //load and play the sound
    soundPlayer.loadSound("a.mp3");
    soundPlayer.setLoop(true);
//    soundPlayer.play();
    
    
    last = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    
    //get the fftval of the sound
    valFFT = ofSoundGetSpectrum(128);
    float temp;
    
    for(int i = 0; i<128; i++){
        temp+=valFFT[i];
    }
    
    //manipulate the val
    avgFFT = temp/128*20;
    cout << avgFFT << endl;
    
    //initilize bounce
    bounce(avgFFT);
    
    if (avgFFT > 1.3) {
        if(ofGetElapsedTimeMillis()-last > 10) {
            ofVec2f mousePos = ofVec2f(ofRandom(ofGetWindowWidth()),ofRandom(ofGetWindowHeight()));
            
            float pRadius = avgFFT*500;
            
            for(int i = 0; i < mParticles.size(); i++) {
                if((mousePos-mParticles[i].mPos).length()<pRadius){
                float fce = ofMap((mousePos-mParticles[i].mPos).length(), 0, pRadius, 30, 0);
                    mParticles[i].addForce(mousePos,fce);
                }
//                float fce = ofRandom(-20.f,20.f);
                
            }
            last = 0;
        }
    }
    
    for(int i = 0; i < mParticles.size(); i++) {
    mParticles[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for(int i = 0; i < mParticles.size(); i++) {
        mParticles[i].draw();
    }
}

//-------------------------------------------------------------
void ofApp::bounce(float f){
    
    for(int i = 0; i<mParticles.size();i++){
        mParticles[i].size = 1.5+f;
        mParticles[i].green = 10+ f*100;
        
    }
   
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case 'a':
            soundPlayer.play();
            break;
            
        case 'q':
            soundPlayer.setSpeed(2.0);
            break;
        case 'w':
            soundPlayer.setSpeed(1.0);
            break;
            
        default:
            break;
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    switch(key){
      case 's':
      soundPlayer.stop();
      break;
    
     default:
        break;
}

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
   
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
//    ofVec2f mousePos = ofVec2f(x,y);
//    for(int i = 0; i < mParticles.size(); i++) {
//        if((mousePos-mParticles[i].mPos).length()<100){
//           float fce = ofMap((mousePos-mParticles[i].mPos).length(), 0, 100, 30, 0);
//           mParticles[i].addForce(mousePos,fce);
//           }
////        float fce = ofRandom(-80.f,80.f);
////        mParticles[i].addForce(mousePos,fce);
//    }

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
