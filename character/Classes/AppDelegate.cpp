//
//  proto1AppDelegate.cpp
//  proto1
//
//  Created by Masato Nagai on 2013/07/01.
//  Copyright __MyCompanyName__ 2013年. All rights reserved.
//

#include "AppDelegate.h"

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "DarkKnight.h"

USING_NS_CC;
using namespace CocosDenshion;

AppDelegate::AppDelegate()
{

}

AppDelegate::~AppDelegate()
{
}

bool AppDelegate::applicationDidFinishLaunching()
{
    // initialize director
    CCDirector *pDirector = CCDirector::sharedDirector();
    pDirector->setOpenGLView(CCEGLView::sharedOpenGLView());

    // turn on display FPS
    pDirector->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);
    
    DarkKnight *dk1, *dk2, *dk3, *dk4;
    dk1 = DarkKnight::create();
    
    CCLayer *objLayer = CCLayer::create();
    objLayer->addChild(dk1);
    
    CCScene *scene = CCScene::create();
    scene->addChild(objLayer);

    // run
    pDirector->runWithScene(scene);
    
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    dk1->setPosition(ccp(50, winSize.height/2));
    dk1->run(ccp(100, 0));
    /*
    dk1->jump(ccp(60, 0));
    dk1->turnLeft();
    dk1->run(ccp(-100, 0));
    dk1->jump(ccp(-60, 0));
    dk1->turnRight();
     */
    
    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground()
{
    CCDirector::sharedDirector()->stopAnimation();
    SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->pauseAllEffects();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
    CCDirector::sharedDirector()->startAnimation();
    SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->resumeAllEffects();
}
