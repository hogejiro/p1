//
//  BattleScene.cpp
//  proto1
//
//  Created by Masato Nagai on 2013/07/02.
//
//

#include "BattleScene.h"
#include <CCAnimation.h>

using namespace cocos2d;

CCScene* BattleScene::scene()
{
    CCScene *scene = CCScene::create();
    BattleScene *layer = BattleScene::create();
    scene->addChild(layer);
    return scene;
}

bool BattleScene::init() {
    if ( !CCLayer::init() )
    {
        return false;
    }

    this->addOne();
    this->addTwo();
    return true;
}

void BattleScene::addOne()
{
    printf("init()");
    
    CCSpriteFrameCache* spriteCache = CCSpriteFrameCache::sharedSpriteFrameCache();
    spriteCache->addSpriteFramesWithFile("darknight.plist");
    
    CCArray* animFrames = CCArray::createWithCapacity(7);
    char str[100] = {0};
    for (int i = 1; i <= 7; i++) {
        sprintf(str, "%d.png", i);
        CCSpriteFrame* frame = spriteCache->spriteFrameByName(str);
        animFrames->addObject(frame);
    }
    
    CCSprite* sprite = CCSprite::createWithSpriteFrameName(str);
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    sprite->setPosition(ccp(winSize.width/2 - sprite->getContentSize().width, winSize.height/2));
    this->addChild(sprite);
    
    CCAnimation* animation = CCAnimation::createWithSpriteFrames(animFrames, 0.1f);
    sprite->runAction(CCRepeatForever::create(CCAnimate::create(animation)));
}

void BattleScene::addTwo() {
    CCSpriteFrameCache *spriteCache = CCSpriteFrameCache::sharedSpriteFrameCache();
    spriteCache->addSpriteFramesWithFile("darknight.plist");
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
 
    /// アニメーションフレームの生成
    CCAnimation* pAnimation = CCAnimation::create();
    
    /// アニメーションフレームに画像を追加
    /// [例]
    /// hoge_00.png
    /// hoge_01.png
    /// hoge_02.png
    /// hoge_03.png
    /// という画像があるとします
    for( int i=1; i<9; i++ )
    {
        char filename[128] = {0};
        sprintf(filename,"action2%04d.png",i);
        pAnimation->addSpriteFrameWithFileName(filename);
    }
    
    /// アニメーションを切り替える速度を決める
    /// ※1.0fで一秒になります
    pAnimation->setDelayPerUnit( 0.1f );
    
    /// 無限ループさせる
    /// [例]
    /// 1  ... 一回ループさせる
    /// 2  ... 二回ループさせる
    /// -1 ... 無限ループさせる
    pAnimation->setLoops(-1);
    
    /// アニメーションの生成
    CCAnimate* pAnimate = CCAnimate::create(pAnimation);
    
    /// スプライトの生成
    CCSprite* pSprite2 = CCSprite::create();
    pSprite2->setFlipX(true);
    
    /// レイヤーにスプライトを追加
    this->addChild(pSprite2);
    
    /// スプライト座標を設定する
    pSprite2->setPosition(ccp(winSize.width/2 + pSprite2->getContentSize().width, winSize.height/2));
    
    /// アニメーションを実行する
    pSprite2->runAction(pAnimate);
}