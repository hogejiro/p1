//
//  Action1.h
//  proto1
//
//  Created by Masato Nagai on 2013/07/02.
//
//

#ifndef proto1_Action1_h
#define proto1_Action1_h

#include "cocos2d.h"

class Action1 : public cocos2d::CCLayer
{
public:
    // Method 'init' in cocos2d-x returns bool, instead of 'id' in cocos2d-iphone (an object pointer)
    virtual bool init();
    
    // there's no 'id' in cpp, so we recommend to return the class instance pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);
    
    // preprocessor macro for "static create()" constructor ( node() deprecated )
    CREATE_FUNC(Action1);
};

#endif