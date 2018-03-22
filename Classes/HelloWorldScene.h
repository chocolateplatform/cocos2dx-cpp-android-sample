#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include <ui/UIWidget.h>
#include <ui/UIButton.h>
#include "cocos2d.h"
#include "VdopiaAdNativeAPI.h"

class HelloWorld : public cocos2d::Scene {
public:
    static cocos2d::Scene *createScene();

    virtual bool init();

    // a selector callback
    void menuCloseCallback(cocos2d::Ref *pSender);

    // Interstitial Ad Methods & Callbacks

    void interstitialAdLoaded();

    void interstitialAdFailed();

    void interstitialAdDismissed();

    void interstitialAdClicked();

    void interstitialAdShown();


    // Rewarded Ad Methods & Callbacks

    void rewardAdLoaded();

    void rewardAdFailed();

    void rewardAdDismissed();

    void rewardAdShownError();

    void rewardAdCompleted();

    void rewardAdShown();

    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

    void setButtonVisible(bool value, int tag);
};

#endif // __HELLOWORLD_SCENE_H__
