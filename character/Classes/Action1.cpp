//
//  Action1.cpp
//  proto1
//
//  Created by Masato Nagai on 2013/07/02.
//
//

#include "Action1.h"
#include <CCAnimation.h>

using namespace cocos2d;

CCScene* Action1::scene()
{
    CCScene *scene = CCScene::create();
    Action1 *layer = Action1::create();
    scene->addChild(layer);
    return scene;
}

bool Action1::init()
{
    printf("init()");
    
    CCSpriteFrameCache* spriteCache = CCSpriteFrameCache::sharedSpriteFrameCache();
    spriteCache->addSpriteFramesWithFile("darknight.plist");
    
    CCArray* animFrames = CCArray::createWithCapacity(7);
    char str[100] = {0};
    for (int i = 1; i <= 7; i++) {
        sprintf(str, "%d.png", i);
        CCSpriteFrame* frame = spriteCache->spriteFrameByName(str);
        animFrames->addObject(frame);
    }
    
    CCSprite* sprite = CCSprite::createWithSpriteFrameName(str);
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    sprite->setPosition(ccp(100, 100));
    this->addChild(sprite);
    
    CCAnimation* animation = CCAnimation::createWithSpriteFrames(animFrames, 0.1f);
    sprite->runAction(CCRepeatForever::create(CCAnimate::create(animation)));
    
    return true;
}
