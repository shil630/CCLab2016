//
//  particleSystem.hpp
//  of_example_2
//
//  Created by 石亮 on 11/1/16.
//
//

#pragma once
#include "ofmain.h"
#include "particle.h"

class particleSystem {
public:
    particleSystem (ofVec2f position);
    
    void update (ofVec2f force);
    void draw ();
    
    vector<particle> mParticleList;//nameofVector, vectors are like a fancy, high-end array
    ofVec2f mPosition;
    int mEmitRate;
    bool mIsAddingParticles;

};
