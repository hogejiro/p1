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
protected:
    static Touch* instance;
    Touch(Controller* controller) {
        this->controller = controller;
    }
//    Touch(const Touch&);
//    const Touch& operator = (const Touch&);
public:
    const int ON = 1;
    const int OFF = 0;
    
    unsigned int id;
    unsigned int status = OFF;
    cocos2d::CCPoint startPoint;
    Controller* controller;

    static TSelf* getInstance(Controller* controller) {
        if (instance == 0) {
            instance = new TSelf(controller);
        }
        return instance;
    }

    virtual void touchBegan(cocos2d::CCTouch *touch, cocos2d::CCEvent *pEvent);
    virtual void touchMoved(cocos2d::CCTouch *touch, cocos2d::CCEvent *pEvent);
    virtual void touchEnded(cocos2d::CCTouch *touch, cocos2d::CCEvent *pEvent);
    virtual void touchCanceled(cocos2d::CCTouch *touch, cocos2d::CCEvent *pEvent);
    
    void displayTouchPoint(float point_x, float point_y) {
        
    }
};

template<class TSelf>
Touch<TSelf>* Touch<TSelf>::instance = 0;


#endif /* defined(__proto1__Touch__) */
