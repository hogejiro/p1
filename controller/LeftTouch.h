//
//  LeftTouch.h
//  proto1
//
//  Created by hideyuki.utsunomiya on 8/20/13.
//
//

#ifndef __proto1__LeftTouch__
#define __proto1__LeftTouch__

#include "Touch.h"
#include <iostream>

class LeftTouch : public Touch {
private:
public:
    unsigned int id;
    cocos2d::CCPoint startPoint;
    cocos2d::CCSprite* beganSprite;
    cocos2d::CCSprite* movedSprite;
    
    void touchBegan(cocos2d::CCTouch *touch, cocos2d::CCEvent *pEvent);
    void touchMoved(cocos2d::CCTouch *touch, cocos2d::CCEvent *pEvent);
    void touchEnded(cocos2d::CCTouch *touch, cocos2d::CCEvent *pEvent);
    void touchCanceled(cocos2d::CCTouch *touch, cocos2d::CCEvent *pEvent);
};


#endif /* defined(__proto1__LeftTouch__) */
