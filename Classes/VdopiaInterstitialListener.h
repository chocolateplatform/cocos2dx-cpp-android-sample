#ifndef VDOPIA_INTERSTITIAL_H_DEFINE
#define VDOPIA_INTERSTITIAL_H_DEFINE

class VdopiaInterstitialListener {
public:
	VdopiaInterstitialListener();

	virtual void adLoadedInterstitial() = 0;
	virtual void adFailedInterstitial() = 0;
	virtual void adDismissedInterstitial() = 0;
	virtual void adClickedInterstitial() = 0;
	virtual void adShownInterstitial() = 0;

};

#endif
