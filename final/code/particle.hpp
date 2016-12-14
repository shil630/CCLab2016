//
//  particle.hpp
//  cclab_final
//
//  Created by 石亮 on 12/13/16.
//
//

#pragma once
#include "ofMain.h"

class particle {
public:
    particle(ofVec2f position);
    
    void update();
    void draw();
    
    void addForce(ofVec2f force, float fce);
    
    ofVec2f mPos;
    ofVec2f oriPos;
    ofVec2f mVel;
    ofVec2f mAcc;
    
    float mFric;
    
    const float MIN_VEL = 0.01;
    
    int red, green, blue;
    float size;
    
};
