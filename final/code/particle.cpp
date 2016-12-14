//
//  particle.cpp
//  cclab_final
//
//  Created by 石亮 on 12/13/16.
//
//

#include "particle.hpp"

particle::particle(ofVec2f position) {
    mPos = position;
    oriPos = position;
    
    mFric = 0.85;
    mVel = ofVec2f(0,0);
    mAcc = ofVec2f(0,0);
    size = 2;
}

void particle::update(){
    if (mVel.length() > 0) {
        mVel *= mFric;
        mPos += mVel;
        if(mVel.length() < MIN_VEL&&(oriPos-mPos).length()>1) {
//            mVel = ofVec2f(0,0);
            mAcc = (oriPos-mPos);
            mVel+=mAcc;
        }
    }
    
    if (mPos.x < 0) {
        mPos = oriPos;
        mVel = ofVec2f(0,0);
        mAcc = ofVec2f(0,0);
    }
    if (mPos.x > ofGetWindowWidth()) {
        mPos = oriPos;
        mVel = ofVec2f(0,0);
        mAcc = ofVec2f(0,0);
    }
    
    if (mPos.y < 0) {
        mPos = oriPos;
        mVel = ofVec2f(0,0);
        mAcc = ofVec2f(0,0);
    }
    
    if (mPos.y > ofGetWindowHeight()) {
        mPos = oriPos;
        mVel = ofVec2f(0,0);
        mAcc = ofVec2f(0,0);
    }
    
    red = ofMap(mPos.x, 0, ofGetWindowWidth(), 255, 0);
    blue = ofMap(mPos.y, 0, ofGetWindowHeight(), 0, 255);
}

void particle::draw(){
//    ofSetBackgroundColor(0);
    ofSetColor(red,green,blue);
    ofSetCircleResolution(50);
    ofDrawCircle(mPos, size);
}

void particle::addForce(ofVec2f force, float fce){
    
    mAcc = mPos - force;
    
    mAcc = mAcc.getNormalized()*fce;
    
    mVel += mAcc;
}
