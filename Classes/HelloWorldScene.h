#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include <ui/UIWidget.h>
#include <ui/UIButton.h>
#include "cocos2d.h"
#include "VdopiaAdNativeAPI.h"
#include "VdopiaInterstitialListener.h"
#include "VdopiaRewardedListener.h"

class HelloWorld : public cocos2d::Scene,
		           public VdopiaInterstitialListener,
		           public VdopiaRewardedListener {
public:
    static cocos2d::Scene *createScene();

    bool init() override;

    // a selector callback
    void menuCloseCallback(cocos2d::Ref *pSender);

    // Interstitial Ad Methods & Callbacks
    void adLoadedInterstitial() override;
    void adFailedInterstitial() override; 
    void adDismissedInterstitial() override; 
    void adClickedInterstitial() override; 
    void adShownInterstitial() override; 

    // Rewarded Ad Methods & Callbacks
    void adLoadedRewarded() override;
    void adFailedRewarded() override;
    void adDismissedRewarded()  override;
    void adCompletedRewarded() override;
    void adShownErrorRewarded() override;
    void adShownRewarded() override;

    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

    void setButtonVisible(bool value, int tag);
};

#endif // __HELLOWORLD_SCENE_H__
