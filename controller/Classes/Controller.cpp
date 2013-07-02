//
//  Controller.cpp
//  proto1
//
//  Created by yy on 13/07/02.
//
//

#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"

using namespace cocos2d;

CCScene *Controller::scene() {
    CCScene *scene = CCScene::create();
    Controller *layer = Controller::create();
    scene->addChild(layer);
    
    return scene;
}

bool Controller::init() {
    if (!CCLayer::init()) {
        return false;
    }
    
    CCSprite* pSprite = CCSprite::create("HelloWorld.png");
    this->mSprite = pSprite;
    
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    pSprite->setPosition( ccp(size.width/2, size.height/2) );
    this->addChild(pSprite, 0);
    
    return true;
}

void Controller::onEnter() {
    //デリゲートの設定
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}

void Controller::onExit() {
    //デリゲートの解除
    CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
}

bool Controller::ccTouchBegan(cocos2d::CCTouch *ptouch, cocos2d::CCEvent *pEvent) {
    //タッチ開始
    this->mSprite->initWithFile("Icon-72.png");
    CCPoint point = ptouch->getLocationInView();
    char str[100];
    sprintf(str, "%f", point.x);
    CCLabelTTF* pLabel = CCLabelTTF::create(str, "Thonburi", 34);
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    pLabel->setPosition( ccp(size.width / 2, size.height - 20) );
    
    this->addChild(pLabel, 1);
    return true;
}

void Controller::ccTouchMoved(cocos2d::CCTouch *ptouch, cocos2d::CCEvent *pEvent) {
    //タッチ中
}

void Controller::ccTouchEnded(cocos2d::CCTouch *ptouch, cocos2d::CCEvent *pEvent) {
    //タッチ終了
}

void Controller::ccTouchCancelled(cocos2d::CCTouch *ptouch, cocos2d::CCEvent *pEvent) {
    //タッチキャンセル
}