//
//  particle.cpp
//  of_example_2
//
//  Created by 石亮 on 11/1/16.
//
//

#include "particle.h"

//initialzing constructor , and initializing the variables inside of it
particle:: particle(ofVec2f position) : mPosition(position), mSpeed(ofRandom(-2.f, 2.f), ofRandom(-2.f, 2.f)), mDirection(ofVec2f(0)), mLifeSpan(255.f) {};

// update function
void particle::update(float multiplier) {
    // apply acceleration to velocity
    mSpeed += mDirection;
    mPosition += mSpeed * multiplier;
    
    // decrease particle life span
    if (mLifeSpan > 0) {
        mLifeSpan -= 2.f;
    }
}

// draw function
void particle::draw() {
    if (mLifeSpan > 100) {
        ofSetColor(mLifeSpan);
        
    } else if (mLifeSpan <= 100) {
        ofSetColor(ofRandom(0,255));
    }
    
    //if particle is closer it's smaller
    ofDrawCircle(mPosition, 3.f * ofMap(mLifeSpan, 0, 255.f, 0, 1.f));
    
                 
}

//applyForce function
void particle::applyForce(ofVec2f force) {
    mDirection += force;
    
}

//resetForce function
void particle::resetForces() {
    mDirection *= 0;
}

