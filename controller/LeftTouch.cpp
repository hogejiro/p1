//
//  LeftTouch.cpp
//  proto1
//
//  Created by hideyuki.utsunomiya on 8/20/13.
//
//

#include "LeftTouch.h"


void LeftTouch::touchBegan(cocos2d::CCTouch *touch, cocos2d::CCEvent *pEvent) {
    
}

void LeftTouch::touchMoved(cocos2d::CCTouch *touch, cocos2d::CCEvent *pEvent) {
    unsigned int touch_id = touch->m_uID;
    if (this->id != touch_id) {
        return;
    }
    
    cocos2d::CCPoint point = touch->getLocation();
    cocos2d::CCSprite* pSprite = cocos2d::CCSprite::create("Controller.png");
    pSprite = cocos2d::CCSprite::create("Controller.png");
    cocos2d::CCPoint startPoint = this->startPoint;
    float dx = point.x - this->startPoint.x;
    float dy = point.y - this->startPoint.y;
    float drad = sqrt(dx * dx + dy * dy);
    int mag = 64;
    this->displayTouchPoint(dx, dy);
    dx = abs(mag * dx / drad) < abs(dx) ? mag * dx / drad : dx;
    dy = abs(mag * dy / drad) < abs(dy) ? mag * dy / drad : dy;
    pSprite->setPosition( ccp(this->startPoint.x + dx, this->startPoint.y + dy));
    pSprite->setScale(0.5);
    pSprite->setOpacity(100);
    this->controller->addChild(pSprite, 1, 4 + this->id);
}

void LeftTouch::touchEnded(cocos2d::CCTouch *touch, cocos2d::CCEvent *pEvent) {
    
}

void LeftTouch::touchCanceled(cocos2d::CCTouch *touch, cocos2d::CCEvent *pEvent) {
    
}
