#include "Action2.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

CCScene* Action2::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    Action2 *layer = Action2::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Action2::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(Action2::menuCloseCallback) );
    pCloseItem->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20) );

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition( CCPointZero );
    this->addChild(pMenu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    CCLabelTTF* pLabel = CCLabelTTF::create("Hello World", "Thonburi", 34);

    // ask director the window size
    CCSize size = CCDirector::sharedDirector()->getWinSize();

    // position the label on the center of the screen
    pLabel->setPosition( ccp(size.width / 2, size.height - 20) );

    // add the label as a child to this layer
    this->addChild(pLabel, 1);

    // add "HelloWorld" splash screen"
    CCSprite* pSprite = CCSprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    pSprite->setPosition( ccp(size.width/2, size.height/2) );

    // add the sprite as a child to this layer
    this->addChild(pSprite, 0);
    
    
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
    
    /// レイヤーにスプライトを追加
    this->addChild(pSprite2);
    
    /// スプライト座標を設定する
    pSprite2->setPosition(ccp(winSize.width/2, winSize.height/2));
    
    /// アニメーションを実行する
    pSprite2->runAction(pAnimate);
    
    return true;
}

void Action2::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
