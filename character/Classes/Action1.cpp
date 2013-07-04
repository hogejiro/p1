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
    
    CCSpriteBatchNode* spritebatch = CCSpriteBatchNode::create("darknight.png");
    CCSpriteFrameCache* spriteCache = CCSpriteFrameCache::sharedSpriteFrameCache();
    spriteCache->addSpriteFramesWithFile("darknight.plist");
    
    char str[100] = {0};
    CCSprite *sprite;
    for (int i = 1; i <= 7; i++) {
        sprintf(str, "%d.png", i);
        printf("add frame %s", str);
        sprite = CCSprite::createWithSpriteFrameName(str);
        spritebatch->addChild(sprite);
    }
    this->addChild(spritebatch);
    
    CCArray* animFrames = CCArray::createWithCapacity(7);
    for (int i = 1; i <= 7; i++) {
        sprintf(str, "%d.png", i);
        CCSpriteFrame* frame = spriteCache->spriteFrameByName(str);
        animFrames->addObject(frame);
    }
    
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    sprite->setPosition(ccp(sprite->getContentSize().width/2, winSize.height/2));
    
    CCAnimation* animation = CCAnimation::createWithSpriteFrames(animFrames, 0.1f);
    sprite->runAction( CCRepeatForever::create( CCAnimate::create(animation) ) );
    
    
    return true;
}
/*
 CCAnimationCache *cache = CCAnimationCache::sharedAnimationCache(); // "caches" are always singletons in cocos2d
 2cache->addAnimationsWithFile("animations/animations-2.plist");
 3CCAnimation animation = cache->animationByName("dance_1");  // I apologize for this method name, it should be getAnimationByName(..) in future versions
 4CCAnimate animate = CCAnimate::create(animation);  // Don't confused between CCAnimation and CCAnimate :)
 5sprite->runAction(animate);
 
 1CCAnimation *animation = CCAnimation::create();
 2
 3// load image file from local file system to CCSpriteFrame, then add into CCAnimation
 4for (int i = 1; i < 15; i++)
 5{
 6    char szImageFileName[128] = {0};
 7    sprintf(szImageFileName, "Images/grossini_dance_%02d.png", i);
 8    animation->addSpriteFrameWithFileName(szImageFileName);
 9}
 10
 11animation->setDelayPerUnit(2.8f / 14.0f); // This animation contains 14 frames, will continuous 2.8 seconds.
 12animation->setRestoreOriginalFrame(true); // Return to the 1st frame after the 14th frame is played.
 13
 14CCAnimate *action = CCAnimate::create(animation);
 15sprite->runAction(action);  // run action on sprite object
 */
