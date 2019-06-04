#ifndef VDOPIA_REWARDED_H_DEFINE
#define VDOPIA_REWARDED_H_DEFINE

class VdopiaRewardedListener {
public:
	virtual void adLoadedRewarded() = 0;
	virtual void adFailedRewarded() = 0;
	virtual void adDismissedRewarded() = 0;
	virtual void adCompletedRewarded() = 0;
	virtual void adShownErrorRewarded() = 0;
	virtual void adShownRewarded() = 0;

};

#endif
