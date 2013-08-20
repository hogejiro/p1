//
//  Touch.h
//  proto1
//
//  Created by hideyuki.utsunomiya on 8/20/13.
//
//

#ifndef __proto1__Touch__
#define __proto1__Touch__

#include "cocos2d.h"
#include "Controller.h"
#include <iostream>

template<class TSelf>
class Touch {
private:
    static TSelf* instance;
    Touch() {
        
    }
public:
    const int ON = 1;
    const int OFF = 0;
    
    unsigned int id;
    unsigned int status = OFF;
    cocos2d::CCPoint startPoint;
    Controller* controller;

    ~Touch() {
        
    }

    virtual void touchBegan(cocos2d::CCTouch *touch, cocos2d::CCEvent *pEvent);
    virtual void touchMoved(cocos2d::CCTouch *touch, cocos2d::CCEvent *pEvent);
    virtual void touchEnded(cocos2d::CCTouch *touch, cocos2d::CCEvent *pEvent);
    virtual void touchCanceled(cocos2d::CCTouch *touch, cocos2d::CCEvent *pEvent);
    
    static TSelf getInstance();
    void displayTouchPoint(float point_x, float point_y);
};

#endif /* defined(__proto1__Touch__) */
