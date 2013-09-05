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

bool DarkKnight::init() {
    if ( !CCNode::init() )
    {
        return false;
    }

    spriteCache = CCSpriteFrameCache::sharedSpriteFrameCache();
    spriteCache->addSpriteFramesWithFile("darknight.plist");
    this->sprite = CCSprite::createWithSpriteFrameName("1.png");
    this->addChild(sprite);
    
    /*
    int spriteWidth = 48;
    int spriteHeight = 48;
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    sprite->setPosition(ccp(spriteWidth * 1.5, winSize.height/2));
    
    runSwordAttackAnimation(ccp(spriteWidth * 1.5, winSize.height/2));
    runJumpAttackAnimation(ccp(spriteWidth * 2.5, winSize.height/2));
    runDashAnimation(ccp(spriteWidth * 3.5, winSize.height/2));
    runGuardAnimation(ccp(spriteWidth * 1.5, winSize.height/2 + spriteHeight));
     */
    return true;
}

void DarkKnight::setPosition(const cocos2d::CCPoint &position) {
    this->sprite->setPosition(position);
}

void DarkKnight::move(CCAction* act) {
    this->sprite->stopAllActions();
    
    CCArray* animFrames = CCArray::createWithCapacity(5);
    char str[100] = {0};
    for (int i = 1; i <= 5; i++) {
        sprintf(str, "basic30%d.png", i);
        CCSpriteFrame* frame = spriteCache->spriteFrameByName(str);
        animFrames->addObject(frame);
    }
    
    CCAnimation* animation = CCAnimation::createWithSpriteFrames(animFrames, 0.1f);
    
    CCArray *actions = CCArray::create();
    actions->addObject(act);
    
    this->sprite->runAction(CCRepeatForever::create(CCAnimate::create(animation)));
    this->sprite->runAction(CCSequence::create(actions));
    
}

void DarkKnight::run(CCPoint t)
{
    CCFiniteTimeAction* forward = CCMoveBy::create(1.0, t);
    this->move(forward);
}

void DarkKnight::jump(CCPoint t) {
    CCFiniteTimeAction* jump = CCJumpBy::create(0.5, t, 30, 1);
    this->move(jump);
}

void DarkKnight::turnLeft() {
    CCFiniteTimeAction* turnLeft = CCFlipX::create(true);
    this->move(turnLeft);
}

void DarkKnight::turnRight() {
    CCFiniteTimeAction* turnRight = CCFlipX::create(false);
    this->move(turnRight);
}

void DarkKnight::swordAttack(CCPoint where)
{
    this->sprite->stopAllActions();
    
    CCArray* animFrames = CCArray::createWithCapacity(7);
    char str[100] = {0};
    for (int i = 1; i <= 7; i++) {
        sprintf(str, "%d.png", i);
        CCSpriteFrame* frame = spriteCache->spriteFrameByName(str);
        animFrames->addObject(frame);
    }
    
    CCAnimation* animation = CCAnimation::createWithSpriteFrames(animFrames, 0.1f);
    sprite->runAction(CCRepeatForever::create(CCAnimate::create(animation)));
}

void DarkKnight::jumpSwordAttack(CCPoint where) {
    this->sprite->stopAllActions();
    
    CCArray* animFrames = CCArray::createWithCapacity(7);
    char str[100] = {0};
    for (int i = 1; i <= 9; i++) {
        sprintf(str, "2%d.png", i);
        CCSpriteFrame* frame = spriteCache->spriteFrameByName(str);
        animFrames->addObject(frame);
    }
    
    CCAnimation* animation = CCAnimation::createWithSpriteFrames(animFrames, 0.1f);
    sprite->runAction(CCRepeatForever::create(CCAnimate::create(animation)));
}

void DarkKnight::guard(CCPoint where)
{
    this->sprite->stopAllActions();
    
    CCArray* animFrames = CCArray::createWithCapacity(7);
    char str[100] = {0};
    for (int i = 1; i <= 3; i++) {
        sprintf(str, "basic90%d.png", i);
        CCSpriteFrame* frame = spriteCache->spriteFrameByName(str);
        animFrames->addObject(frame);
    }
    
    CCAnimation* animation = CCAnimation::createWithSpriteFrames(animFrames, 0.1f);
    this->sprite->runAction(CCRepeatForever::create(CCAnimate::create(animation)));
}
