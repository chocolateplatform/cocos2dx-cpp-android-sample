Listeners can be set by implementing the VdopiaInterstitialListener or VdopiaRewardedListener interface.

All you have to do is call the setInterstitialListener() for Interstitial ad listeners, and
setRewardedListener() for Rewarded ad listeners.

There is no need to implement anything if you don't want ad listeners.

Example Code:

// This is YourScene.h

#include "VdopiaInterstitialListener.h"

class  YourScene : public VdopiaInterstitialListener {
	// implement all the pure virutal functions from VdopiaInterstitialListener

};

=============================================================================================================

// Now let's take a look in your YourSceene.cpp
#include "VdopiaAdNative.h"

YourScene::YourScene() {
	// initialize first
	chocolateInit("your_api_key");

	// call this to hook up your interstitial ad listener
	setInterstitialListener(this); 		// This function is declared in VdopiaAdNative 

	// Note: It doesn't have to be set in your constructor 
}

// Make sure to define all functions that your class implements from the VdopiaInterstitialListener interface.
