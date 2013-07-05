//
//  Action1.cpp
//  proto1
//
//  Created by Masato Nagai on 2013/07/02.
//
//

#include "Action1.h"

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
    CCSpriteFrameCache *spriteCache = CCSpriteFrameCache::sharedSpriteFrameCache();
    spriteCache->addSpriteFramesWithFile("darknight.plist");
    CCSprite *sprite = CCSprite::createWithSpriteFrameName("1.png");
    this->addChild(sprite);
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    sprite->setPosition(ccp(sprite->getContentSize().width/2, winSize.height/2));
    return true;
}

