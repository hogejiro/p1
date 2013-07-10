//
//  DarkKnight.cpp
//  proto1
//
//  Created by Masato Nagai on 2013/07/02.
//
//

#include "DarkKnight.h"
#include <CCAnimation.h>

using namespace cocos2d;

CCScene* DarkKnight::scene()
{
    CCScene *scene = CCScene::create();
    DarkKnight *layer = DarkKnight::create();
    scene->addChild(layer);
    return scene;
}

bool DarkKnight::init() {
    if ( !CCLayer::init() )
    {
        return false;
    }

    spriteCache = CCSpriteFrameCache::sharedSpriteFrameCache();
    spriteCache->addSpriteFramesWithFile("darknight.plist");
    
    int spriteWidth = 48;
    int spriteHeight = 48;
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    runSwordAttackAnimation(ccp(spriteWidth * 1.5, winSize.height/2));
    runJumpAttackAnimation(ccp(spriteWidth * 2.5, winSize.height/2));
    
    return true;
}

void DarkKnight::runSwordAttackAnimation(CCPoint where)
{
    CCArray* animFrames = CCArray::createWithCapacity(7);
    char str[100] = {0};
    for (int i = 1; i <= 7; i++) {
        sprintf(str, "%d.png", i);
        CCSpriteFrame* frame = spriteCache->spriteFrameByName(str);
        animFrames->addObject(frame);
    }
    
    CCSprite* sprite = CCSprite::createWithSpriteFrameName(str);
    sprite->setPosition(where);
    this->addChild(sprite);
    
    CCAnimation* animation = CCAnimation::createWithSpriteFrames(animFrames, 0.1f);
    sprite->runAction(CCRepeatForever::create(CCAnimate::create(animation)));
}

void DarkKnight::runJumpAttackAnimation(CCPoint where) {
    CCArray* animFrames = CCArray::createWithCapacity(7);
    char str[100] = {0};
    for (int i = 1; i <= 9; i++) {
        sprintf(str, "2%d.png", i);
        CCSpriteFrame* frame = spriteCache->spriteFrameByName(str);
        animFrames->addObject(frame);
    }
    
    CCSprite* sprite = CCSprite::createWithSpriteFrameName(str);
    sprite->setPosition(where);
    this->addChild(sprite);
    
    CCAnimation* animation = CCAnimation::createWithSpriteFrames(animFrames, 0.1f);
    sprite->runAction(CCRepeatForever::create(CCAnimate::create(animation)));
}