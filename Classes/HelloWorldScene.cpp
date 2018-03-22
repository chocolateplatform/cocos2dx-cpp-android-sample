#include "HelloWorldScene.h"

#define buttonTextFontSize 12
#define buttonHeight 25
#define buttonWidth 120
#define selecedColor Color3B(140,140,140)
#define normalTextColor Color3B(31,41,58)
#define ShowInterestialAdButtonTag 02
#define ShowRewardAdButtonTag 04
#define LoadInterestialAdButtonTag 01
#define LoadRewardAdButtonTag 03

USING_NS_CC;

Scene *HelloWorld::createScene() {
    return HelloWorld::create();
}

// on "init" you need to initialize your instance
bool HelloWorld::init() {
    //////////////////////////////
    // 1. super init first
    if (!Scene::init()) {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto bg = cocos2d::LayerColor::create(Color4B(41, 55, 75, 255));
    this->addChild(bg);

    // android back press event
    auto touchListener = EventListenerKeyboard::create();
    touchListener->onKeyReleased = [](cocos2d::EventKeyboard::KeyCode keyCode,
                                      cocos2d::Event *event) {
        if (keyCode == EventKeyboard::KeyCode::KEY_BACK) {
            Director::getInstance()->end();
        }
    };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

    // create header image from png
    auto headerImage = Sprite::create("chocolate.png");
    // position the sprite on the center of the screen
    headerImage->setPosition(
            Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height - 50));
    headerImage->setContentSize(Size(100, 100));
    this->addChild(headerImage);

    float xPosition = 180;
    float buttonYPosition =
            origin.y + visibleSize.height - headerImage->getContentSize().height - 50;


    // setColor
    auto loadInterstitialAdButtonBg = cocos2d::LayerColor::create(Color4B(234, 233, 231, 255));
    loadInterstitialAdButtonBg->setPosition(Vec2(xPosition, buttonYPosition));
    loadInterstitialAdButtonBg->setContentSize(cocos2d::Size(buttonWidth, buttonHeight));
    this->addChild(loadInterstitialAdButtonBg, 1, LoadInterestialAdButtonTag);


    auto loadInterstitialAdButton = cocos2d::ui::Button::create();
    loadInterstitialAdButton->setPosition(Vec2(60, 13));
    loadInterstitialAdButton->setScale9Enabled(true);
    loadInterstitialAdButton->setContentSize(cocos2d::Size(buttonWidth, buttonHeight));
    loadInterstitialAdButton->setTitleFontSize(buttonTextFontSize);
    loadInterstitialAdButton->setTitleText("Load Interstitial ad");
    loadInterstitialAdButton->setTitleColor(normalTextColor);
    loadInterstitialAdButton->setPressedActionEnabled(true);
    loadInterstitialAdButton->addTouchEventListener(
            [](Ref *pSender, cocos2d::ui::Widget::TouchEventType type) {
                if (type == cocos2d::ui::Widget::TouchEventType::ENDED) {
                    // do something

                    // String age, String birthDate, String gender, String maritalStatus,
                    //String ethnicity, String dmaCode, String postal, String curPostal,
                    //           String latitude, String longitude
                    setAdRequestUserParams("23", "23/11/1990", "m", "single", "Asian", "999",
                                           "123123", "321321", "qwe", "wrt"),

                    setAdRequestAppParams("Vdopia", "Vdopia", "Vdopia-demo.com",
                                                  "vdopia.com", "",
                                                  "Movie");
                    CCLOG("loadInterstitialAdFunction");
                    const char *apiKey = "r7BmFo";
                    CCLOG("loadInterstitialAdFunction");
                    const char *apiKey = "r7BmFo";
                    loadInterstitialAd(apiKey);loadInterstitialAd(apiKey);
                }
            });

    loadInterstitialAdButtonBg->addChild(loadInterstitialAdButton, 1, LoadInterestialAdButtonTag);

    //setColor
    auto loadRewardAdButtonBg = cocos2d::LayerColor::create(Color4B(234, 233, 231, 255));
    loadRewardAdButtonBg->setPosition(Vec2(xPosition, buttonYPosition - 70));
    loadRewardAdButtonBg->setContentSize(cocos2d::Size(buttonWidth, buttonHeight));
    this->addChild(loadRewardAdButtonBg, 1, LoadRewardAdButtonTag);

    auto loadRewardAdButton = cocos2d::ui::Button::create();
    loadRewardAdButton->setScale9Enabled(true);
    loadRewardAdButton->setContentSize(cocos2d::Size(buttonWidth, buttonHeight));
    loadRewardAdButton->setTitleFontSize(buttonTextFontSize);
    loadRewardAdButton->setTitleText("Load Reward ad");
    loadRewardAdButton->setTitleColor(normalTextColor);
    loadRewardAdButton->setPressedActionEnabled(true);
    loadRewardAdButton->setPosition(Vec2(60, 13));
    loadRewardAdButton->addTouchEventListener(
            [](Ref *pSender, cocos2d::ui::Widget::TouchEventType type) {
                if (type == cocos2d::ui::Widget::TouchEventType::ENDED) {

                    setAdRequestUserParams("23", "23/11/1990", "m", "single", "Asian", "999",
                                           "123123", "421340", "321321", "12313");
                    setAdRequestAppParams("Vdopia", "Vdopia", "Vdopia-demo.com", "vdopia.com", "",
                                          "Movie");
                    CCLOG("loadRewardAdFunction");
                    const char *apiKey = "r7BmFo";
                    loadRewardedAd(apiKey);
                }

            });

    loadRewardAdButtonBg->addChild(loadRewardAdButton, 1, LoadRewardAdButtonTag);

    //setColor
    auto showInterstitialAdButtonBg = cocos2d::LayerColor::create(Color4B(234, 233, 231, 255));
    showInterstitialAdButtonBg->setPosition(Vec2(xPosition, buttonYPosition - 35));
    showInterstitialAdButtonBg->setContentSize(cocos2d::Size(buttonWidth, buttonHeight));
    this->addChild(showInterstitialAdButtonBg, 1, ShowInterestialAdButtonTag);

    auto showInterstitialAdButton = cocos2d::ui::Button::create();
    showInterstitialAdButton->setPosition(Vec2(60, 13));
    showInterstitialAdButton->setScale9Enabled(true);
    showInterstitialAdButton->setContentSize(cocos2d::Size(buttonWidth, buttonHeight));
    showInterstitialAdButton->setTitleFontSize(buttonTextFontSize);
    showInterstitialAdButton->setTitleText("Show Interstitial ad");
    showInterstitialAdButton->setPressedActionEnabled(true);
    showInterstitialAdButton->addTouchEventListener(
            [](Ref *pSender, cocos2d::ui::Widget::TouchEventType type) {
                if (type == cocos2d::ui::Widget::TouchEventType::ENDED) {
                    CCLOG("showInterstitialAd");
                    showInterstitialAd();
                }
            });
    showInterstitialAdButton->setEnabled(false);
    showInterstitialAdButton->setTitleColor(Color3B(156, 156, 156));
    showInterstitialAdButtonBg->addChild(showInterstitialAdButton, 1, ShowInterestialAdButtonTag);


    //setColor
    auto showRewardButtonBg = cocos2d::LayerColor::create(Color4B(234, 233, 231, 255));
    showRewardButtonBg->setPosition(Vec2(xPosition, buttonYPosition - 105));
    showRewardButtonBg->setContentSize(cocos2d::Size(buttonWidth, buttonHeight));
    this->addChild(showRewardButtonBg, 1, ShowRewardAdButtonTag);


    auto showRewardButton = cocos2d::ui::Button::create();
    showRewardButton->setScale9Enabled(true);
    showRewardButton->setContentSize(cocos2d::Size(buttonWidth, buttonHeight));
    showRewardButton->setTitleFontSize(buttonTextFontSize);
    showRewardButton->setTitleText("Show Reward ad");
    showRewardButton->setTitleColor(normalTextColor);
    showRewardButton->setPressedActionEnabled(true);
    showRewardButton->setPosition(Vec2(60, 13));
    showRewardButton->addTouchEventListener(
            [](Ref *pSender, cocos2d::ui::Widget::TouchEventType type) {
                if (type == cocos2d::ui::Widget::TouchEventType::ENDED) {
                    CCLOG("showRewardAdFunction");
                    showRewardedAd("qj5ebyZ0F0vzW6yg", "Chocolate1", "coin", "30");
                }
            });
    showRewardButton->setEnabled(false);
    showRewardButton->setTitleColor(Color3B(156, 156, 156));
    showRewardButtonBg->addChild(showRewardButton, 1, ShowRewardAdButtonTag);
    return true;
}


void HelloWorld::interstitialAdLoaded() {
    CCLOG("interstitialAdLoaded");
    this->setButtonVisible(true, ShowInterestialAdButtonTag);
    this->setButtonVisible(false, LoadInterestialAdButtonTag);
}

void HelloWorld::interstitialAdShown() {
    CCLOG("interstitialAdShown");
}

void HelloWorld::interstitialAdFailed() {
    CCLOG("interstitialAdFailed");
    this->setButtonVisible(false, ShowInterestialAdButtonTag);
    this->setButtonVisible(true, LoadInterestialAdButtonTag);
}

void HelloWorld::interstitialAdDismissed() {
    CCLOG("interstitialAdDismissed");
    this->setButtonVisible(false, ShowInterestialAdButtonTag);
    this->setButtonVisible(true, LoadInterestialAdButtonTag);
}

void HelloWorld::interstitialAdClicked() {
    CCLOG("interstitialAdClicked");
}

void HelloWorld::rewardAdLoaded() {
    CCLOG("rewardAdLoaded");

    this->setButtonVisible(true, ShowRewardAdButtonTag);
    this->setButtonVisible(false, LoadRewardAdButtonTag);
}

void HelloWorld::rewardAdFailed() {
    CCLOG("rewardAdFailed");
    this->setButtonVisible(false, ShowRewardAdButtonTag);
    this->setButtonVisible(true, LoadRewardAdButtonTag);

}

void HelloWorld::rewardAdCompleted() {
    CCLOG("rewardAdCompleted");
    this->setButtonVisible(false, ShowRewardAdButtonTag);
    this->setButtonVisible(true, LoadRewardAdButtonTag);
}

void HelloWorld::rewardAdShown() {
    CCLOG("rewardAdShown");
}

void HelloWorld::rewardAdShownError() {
    CCLOG("rewardAdShownError");
    this->setButtonVisible(false, ShowRewardAdButtonTag);
    this->setButtonVisible(true, LoadRewardAdButtonTag);
}

void HelloWorld::rewardAdDismissed() {
    CCLOG("rewardAdDismissed");

    this->setButtonVisible(false, ShowRewardAdButtonTag);
    this->setButtonVisible(true, LoadRewardAdButtonTag);

}

void HelloWorld::setButtonVisible(bool value, int tag) {
    auto button = dynamic_cast<ui::Button *>(this->getChildByTag(tag)->getChildByTag(tag));
    button->setEnabled(value);
    if (value) {
        button->setTitleColor(normalTextColor);
    } else {
        button->setTitleColor(selecedColor);
    }
}

void HelloWorld::menuCloseCallback(Ref *pSender) {

    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/
    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);

}

