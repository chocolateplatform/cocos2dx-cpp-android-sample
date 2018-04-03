
If you ONLY want to show Interstitial ads, then use VdopiaJNI_Interstitial.cpp 
instead of VdopiaJNI_Interstitial_Reward.cpp:

To only use VdopiaJNI_Interstitial.cpp
EDIT cocos2dx-cpp-android-sample/proj.android-studio/app/jni/Android.mk

LOCAL_SRC_FILES := hellocpp/main.cpp \
                   hellocpp/VdopiaJNI_Interstitial.cpp\
                   ../../../Classes/AppDelegate.cpp \
                   ../../../Classes/HelloWorldScene.cpp

And in cocos2dx-cpp-android-sample/Classes/HelloWorldScene.h/.cpp, there is no need to declare or implement any of the rewarded callback methods:

    void rewardAdLoaded();    //don't declare / implement
    void rewardAdFailed();    //don't declare / implement
    void rewardAdDismissed(); //don't declare / implement
    void rewardAdShownError();//don't declare / implement
    void rewardAdCompleted(); //don't declare / implement
    void rewardAdShown();     //don't declare / implement

--------------------------------------------------------------------------------------------------

Similarly, if you ONLY want to utilize Rewarded, then use VdopiaJNI_Rewarded.cpp
instead of VdopiaJNI_Interstitial_Reward.cpp:

To only use VdopiaJNI_Rewarded.cpp
EDIT proj.android-studio/app/jni/Android.mk

LOCAL_SRC_FILES := hellocpp/main.cpp \
                   hellocpp/VdopiaJNI_Rewarded.cpp\
                   ../../../Classes/AppDelegate.cpp \
                   ../../../Classes/HelloWorldScene.cpp

And in cocos2dx-cpp-android-sample/Classes/HelloWorldScene.h/.cpp, there is no need to declare or implement any of the interstitial callback methods:
    void interstitialAdLoaded();   //don't declare / implement
    void interstitialAdFailed();   //don't declare / implement
    void interstitialAdDismissed();//don't declare / implement
    void interstitialAdClicked();  //don't declare / implement
    void interstitialAdShown();    //don't declare / implement
    

