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
    this->setTouchMode(kCCTouchesAllAtOnce);
    /*
    CCSprite* pSprite = CCSprite::create("HelloWorld.png");
    this->mSprite = pSprite;

    CCSize size = CCDirector::sharedDirector()->getWinSize();
    pSprite->setPosition( ccp(size.width/2, size.height/2) );
    this->addChild(pSprite, 0);
     */

    return true;
}

void Controller::onEnter() {
    //デリゲートの設定
    CCDirector::sharedDirector()->getTouchDispatcher()->addStandardDelegate(this, 0);
}

void Controller::onExit() {
    //デリゲートの解除
    CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
}

/*
bool Controller::ccTouchBegan(cocos2d::CCTouch *ptouch, cocos2d::CCEvent *pEvent) {
    //タッチ開始
    this->mSprite->initWithFile("Icon-72.png");

    CCPoint point = ptouch->getLocationInView();
    this->displayTouchPoint(0, 0);
    this->startPoint = point;
    return true;
}

void Controller::ccTouchMoved(cocos2d::CCTouch *ptouch, cocos2d::CCEvent *pEvent) {
    //タッチ中
    CCPoint point = ptouch->getLocationInView();

    this->displayTouchPoint(point.x - this->startPoint.x, point.y - this->startPoint.y);

}

void Controller::ccTouchEnded(cocos2d::CCTouch *ptouch, cocos2d::CCEvent *pEvent) {
        //タッチ終了
        removeChild(this->pointLabel);
    }

void Controller::ccTouchCancelled(cocos2d::CCTouch *ptouch, cocos2d::CCEvent *pEvent) {
        puts("touch cancel");
        //タッチキャンセル
    }
*/
// /*
void Controller::ccTouchesBegan(cocos2d::CCSet *touches, cocos2d::CCEvent *pEvent) {
    CCTouch* touch;
    for (CCSetIterator it = touches->begin(); it != touches->end(); it++)
    {
        touch = (CCTouch*)(*it);
        if (!touch)
            break;
        unsigned int controllerID = touch->m_uID;
        controller controller = this->getController(touch);
        this->controllerList.push_back(controller);
        if (controller.type == Controller::TYPE_NONE) {
            return;
        }

        this->displayTouchPoint(0, 0);
        CCPoint point = touch->getLocation();
        this->startPoint = point;
        CCSprite* pSprite = CCSprite::create("Controller.png");
        CCSize winsize = CCDirector::sharedDirector()->getWinSize();
        pSprite->setPosition( ccp(point.x, point.y));
        pSprite->setScale(0.25);
        pSprite->setOpacity(100);
        this->ccTouchesMoved(touches, pEvent);
        this->addChild(pSprite, 1, 2 + controllerID);

    }
}

void Controller::ccTouchesMoved(cocos2d::CCSet *touches, cocos2d::CCEvent *pEvent) {
    CCTouch* touch;
    for (CCSetIterator it = touches->begin(); it != touches->end(); it++)
    {
        touch = (CCTouch*)(*it);
        if (!touch)
            break;
        unsigned int controllerID = touch->m_uID;
        removeChildByTag(4 + controllerID);
        controller controller = this->getControllerById((controllerID));
        if (controller.type == Controller::TYPE_LEFT) {
            this->leftControllerMoved(touch, pEvent);
        } else if (controller.type == Controller::TYPE_RIGHT) {
            this->rightControllerMoved(touch, pEvent);
        } else {
            return;
        }
    }
}

void Controller::leftControllerMoved(cocos2d::CCTouch *touch, cocos2d::CCEvent *pEvent) {
    unsigned int controllerID = touch->m_uID;
    controller controller = this->getControllerById((controllerID));
    CCPoint point = touch->getLocation();
    CCSprite* pSprite = CCSprite::create("Controller.png");
    cocos2d::CCPoint startPoint = controller.startPoint;
    float dx = point.x - startPoint.x;
    float dy = point.y - startPoint.y;
    float drad = sqrt(dx * dx + dy * dy);
    int mag = 64;
    this->displayTouchPoint(dx, dy);
    dx = abs(mag * dx / drad) < abs(dx) ? mag * dx / drad : dx;
    dy = abs(mag * dy / drad) < abs(dy) ? mag * dy / drad : dy;
    pSprite->setPosition( ccp(startPoint.x + dx, startPoint.y + dy));
    pSprite->setScale(0.5);
    pSprite->setOpacity(100);
    this->addChild(pSprite, 1, 4 + controllerID);
}

void Controller::rightControllerMoved(cocos2d::CCTouch *touch, cocos2d::CCEvent *pEvent) {
}

void Controller::ccTouchesEnded(cocos2d::CCSet *touches, cocos2d::CCEvent *pEvent) {
    removeChild(this->pointLabel);
    CCTouch* touch;
    for (CCSetIterator it = touches->begin(); it != touches->end(); it++) {
        touch = (CCTouch*)(*it);
        if (!touch)
            break;
        unsigned int controllerID = touch->m_uID;
        this->removeControllerById(controllerID);
        removeChildByTag(2 + controllerID);
        removeChildByTag(4 + controllerID);
    }
}

void Controller::ccTouchesCancelled(cocos2d::CCSet *ptouches, cocos2d::CCEvent *pEvent) {
}

void Controller::displayTouchPoint(float point_x, float point_y) {
    // 座標を取得して文字列に格納
    char str[100];
    sprintf(str, "(%3.0f, %3.0f)", point_x, point_y);

    removeChild(this->pointLabel);
    this->pointLabel = CCLabelTTF::create(str, "Thonburi", 34);
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    this->pointLabel->setPosition( ccp(size.width / 2, size.height - 20) );

    this->addChild(this->pointLabel, 1);
}

Controller::controller Controller::getController(cocos2d::CCTouch *touch) {
    unsigned int id = touch->m_uID;
    CCPoint point = touch->getLocation();
    int type = this->getControllerTypeByPosition(point.x, point.y);
    controller controller = {id, point, type};
    return controller;
}

Controller::controller Controller::getControllerById(int id) {
    controller c;
    std::vector<controller>::iterator it = this->controllerList.begin();
    while (it != controllerList.end()) {
        if (it->id == id) {
            c = *it;
            break;
        }
        ++it;
    }
    return c;
}

void Controller::removeControllerById(int id) {
    controller c;
    std::vector<controller>::iterator it = this->controllerList.begin();
    while (it != controllerList.end()) {
        if (it->id == id) {
            this->controllerList.erase(it);
            break;
        }
        ++it;
    }
}

int Controller::getControllerTypeByPosition(float point_x, float point_y) {
    int sprite_radius = 15;
    // get frame size
    CCEGLView* view = CCDirector::sharedDirector()->getOpenGLView();
    CCSize frame = view->getFrameSize();
    int centerPosition_x = frame.width / 2;
    if (sprite_radius <= point_x
            && point_x < centerPosition_x - sprite_radius
            && sprite_radius <= point_y
            && point_y < frame.height - sprite_radius) {
        return Controller::TYPE_LEFT;
    } else if (centerPosition_x + sprite_radius < point_x
            && point_x < frame.width - sprite_radius
            && sprite_radius <= point_y
            && point_y < frame.height - sprite_radius) {
        return Controller::TYPE_RIGHT;
    } else {
        return Controller::TYPE_NONE;
    }
}
