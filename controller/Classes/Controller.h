//
//  Controller.h
//  proto1
//
//  Created by yy on 13/07/02.
//
//

#ifndef __proto1__Controller__
#define __proto1__Controller__

#include "cocos2d.h"
#include <vector>
#include <string.h>

class Controller : public cocos2d::CCLayer {
private:
    cocos2d::CCSprite *mSprite;
    cocos2d::CCLabelTTF *pointLabel;
    cocos2d::CCPoint startPoint;
    cocos2d::CCParticleSystemQuad* particle;
public:
    virtual bool init();
    static cocos2d::CCScene *scene();
    CREATE_FUNC(Controller);

    void onEnter();
    void onExit();
    /*
    bool ccTouchBegan(cocos2d::CCTouch *ptouch, cocos2d::CCEvent *pEvent);
    void ccTouchMoved(cocos2d::CCTouch *ptouch, cocos2d::CCEvent *pEvent);
    void ccTouchEnded(cocos2d::CCTouch *ptouch, cocos2d::CCEvent *pEvent);
    void ccTouchCancelled(cocos2d::CCTouch *ptouch, cocos2d::CCEvent *pEvent);
     */
    void ccTouchesBegan(cocos2d::CCSet *ptouches, cocos2d::CCEvent *pEvent);
    void ccTouchesMoved(cocos2d::CCSet *ptouches, cocos2d::CCEvent *pEvent);
    void ccTouchesEnded(cocos2d::CCSet *ptouches, cocos2d::CCEvent *pEvent);
    void ccTouchesCancelled(cocos2d::CCSet *ptouches, cocos2d::CCEvent *pEvent);

    void leftControllerMoved(cocos2d::CCTouch *ptouch, cocos2d::CCEvent *pEvent);
    void rightControllerMoved(cocos2d::CCTouch *ptouch, cocos2d::CCEvent *pEvent);

    void displayTouchPoint(float point_x, float point_y);
    struct controller {
        unsigned int id;
        cocos2d::CCPoint startPoint;
        int type;
    };
    const int TYPE_NONE = -1;
    const int TYPE_LEFT = 0;
    const int TYPE_RIGHT = 1;
    std::vector<controller> controllerList;
    controller getController(cocos2d::CCTouch *touch);
    controller getControllerById(int id);
    void removeControllerById(int id);
    int getControllerTypeByPosition(float point_x, float point_y);
};

#endif /* defined(__proto1__Controller__) */
