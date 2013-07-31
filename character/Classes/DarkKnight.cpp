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
    runDashAnimation(ccp(spriteWidth * 3.5, winSize.height/2));
    runGuardAnimation(ccp(spriteWidth * 1.5, winSize.height/2 + spriteHeight));
    return true;
}

void DarkKnight::runDashAnimation(CCPoint where)
{
    CCArray* animFrames = CCArray::createWithCapacity(5);
    char str[100] = {0};
    for (int i = 1; i <= 5; i++) {
        sprintf(str, "basic30%d.png", i);
        CCSpriteFrame* frame = spriteCache->spriteFrameByName(str);
        animFrames->addObject(frame);
    }
    
    CCSprite* sprite = CCSprite::createWithSpriteFrameName(str);
    sprite->setPosition(where);
    this->addChild(sprite);
    
    CCAnimation* animation = CCAnimation::createWithSpriteFrames(animFrames, 0.1f);
    
    CCFiniteTimeAction* forward = CCMoveBy::create(1.0, ccp(100, 0));
    CCFiniteTimeAction* back = CCMoveBy::create(1.0, ccp(-100, 0));
    CCFiniteTimeAction* turnLeft = CCFlipX::create(true);
    CCFiniteTimeAction* turnRight = CCFlipX::create(false);
    
    CCArray *actions = CCArray::create();
    actions->addObject(forward);
    actions->addObject(turnLeft);
    actions->addObject(back);
    actions->addObject(turnRight);
    
    sprite->runAction(CCRepeatForever::create(CCAnimate::create(animation)));
    sprite->runAction(CCRepeatForever::create(CCSequence::create(actions)));
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

void DarkKnight::runGuardAnimation(CCPoint where)
{
    CCArray* animFrames = CCArray::createWithCapacity(7);
    char str[100] = {0};
    for (int i = 1; i <= 3; i++) {
        sprintf(str, "basic90%d.png", i);
        CCSpriteFrame* frame = spriteCache->spriteFrameByName(str);
        animFrames->addObject(frame);
    }
    
    CCSprite* sprite = CCSprite::createWithSpriteFrameName(str);
    sprite->setPosition(where);
    this->addChild(sprite);
    
    CCAnimation* animation = CCAnimation::createWithSpriteFrames(animFrames, 0.1f);
    sprite->runAction(CCRepeatForever::create(CCAnimate::create(animation)));
}
