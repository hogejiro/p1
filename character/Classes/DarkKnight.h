//
//  DarkKnight.h
//  proto1
//
//  Created by Masato Nagai on 2013/07/02.
//
//

#ifndef proto1_DarkKnight_h
#define proto1_DarkKnight_h

#include "cocos2d.h"

class DarkKnight : public cocos2d::CCLayer
{
private:
    cocos2d::CCSpriteFrameCache* spriteCache;
    
public:
    // Method 'init' in cocos2d-x returns bool, instead of 'id' in cocos2d-iphone (an object pointer)
    virtual bool init();
    virtual void runSwordAttackAnimation(cocos2d::CCPoint);
    virtual void runJumpAttackAnimation(cocos2d::CCPoint);
    
    // there's no 'id' in cpp, so we recommend to return the class instance pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);
    
    // preprocessor macro for "static create()" constructor ( node() deprecated )
    CREATE_FUNC(DarkKnight);
};


#endif