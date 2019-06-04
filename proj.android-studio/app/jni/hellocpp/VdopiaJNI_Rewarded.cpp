#include <platform/android/jni/JniHelper.h>
#include "VdopiaAdNativeAPI.h"
#include "VdopiaRewardedListener.h"

#define LOG_TAG    "VdopiaAdsJNI"
#define LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)
#define CLASS_NAME  "com/vdopia/cocos2dx/plugin/VdopiaPlugin"


using namespace cocos2d;

#ifdef __cplusplus
extern "C" {
#endif

VdopiaRewardedListener* rewarded_listener = nullptr;

void setRewardedListener(VdopiaRewardedListener* listener) {
	rewarded_listener = listener;
}

void chocolateInit(const char *appKey) {
    Java_SetPluginType();
    JniMethodInfo methodInfo;
    if (!JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "Init",
                                        "(Ljava/lang/String;)V")) {
        LOGD("Failed to find static method Init");
        return;
    }

    jstring gameId = methodInfo.env->NewStringUTF(appKey);

    methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, gameId);
}

//// Interstitial Ad methods
void prefetchInterstitialAd(const char *parameter) {
    //not implemented
}

void loadInterstitialAd(const char *parameter) {
    //not implemented
}


void showInterstitialAd() {
    //not implemented
}

JNIEXPORT void JNICALL
Java_com_vdopia_cocos2dx_plugin_VdopiaSDKNativeEventHandler_adLoadedInterstitial(JNIEnv *env,
                                                                                 jobject jobj) {
    ////not implemented
}
JNIEXPORT void JNICALL
Java_com_vdopia_cocos2dx_plugin_VdopiaSDKNativeEventHandler_adFailedInterstitial(JNIEnv *env,
                                                                                 jobject jobj) {
    //not implemented
}
JNIEXPORT void JNICALL
Java_com_vdopia_cocos2dx_plugin_VdopiaSDKNativeEventHandler_adDismissedInterstitial(JNIEnv *env,
                                                                                    jobject jobj) {
    ////not implemented
}
JNIEXPORT void JNICALL
Java_com_vdopia_cocos2dx_plugin_VdopiaSDKNativeEventHandler_adClickedInterstitial(JNIEnv *env,
                                                                                  jobject jobj) {
    //not implemented
}
JNIEXPORT void JNICALL
Java_com_vdopia_cocos2dx_plugin_VdopiaSDKNativeEventHandler_adShownInterstitial(JNIEnv *env,
                                                                                jobject jobj) {
    //not implemented
}


// Reward Ad methods
void prefetchRewardedAd(const char *param) {
    Java_SetPluginType();
    JniMethodInfo methodInfo;

    if (!JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "PrefetchRewardAd",
                                        "(Ljava/lang/String;)V")) {
        LOGD("Failed to find static method PrefetchRewardAd");
        return;
    }

    jstring jgameId = methodInfo.env->NewStringUTF(param);

    methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jgameId);
}

void loadRewardedAd(const char *param) {
    Java_SetPluginType();
    JniMethodInfo methodInfo;

    if (!JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "LoadRewardAd",
                                        "(Ljava/lang/String;)V")) {
        LOGD("Failed to find static method LoadRewardAd");
        return;
    }

    jstring jgameId = methodInfo.env->NewStringUTF(param);

    methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jgameId);
}

void showRewardedAd(const char *secretKey, const char *userId, const char *rewardname,
                    const char *amount) {
    JniMethodInfo methodInfo;
    if (!JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "ShowRewardAd",
                                        "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V")) {
        LOGD("Failed to find static method of reward ad show");
        return;
    }

    jstring jsecretKey = methodInfo.env->NewStringUTF(secretKey);

    jstring juserId = methodInfo.env->NewStringUTF(userId);

    jstring jrewardName = methodInfo.env->NewStringUTF(rewardname);

    jstring jamount = methodInfo.env->NewStringUTF(amount);
    methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jsecretKey,
                                         juserId, jrewardName, jamount);
}

// Now recieve Java function calls and pass them to C++
JNIEXPORT void JNICALL
Java_com_vdopia_cocos2dx_plugin_VdopiaSDKNativeEventHandler_adLoadedRewarded(JNIEnv *env,
                                                                             jobject jobj) {

	if(rewarded_listener == nullptr) return;
       
	rewarded_listener->adLoadedRewarded();

}

JNIEXPORT void JNICALL
Java_com_vdopia_cocos2dx_plugin_VdopiaSDKNativeEventHandler_adFailedRewarded(JNIEnv *env,
                                                                             jobject jobj) {

   	if(rewarded_listener == nullptr) return;
       
	rewarded_listener->adFailedRewarded();
}

JNIEXPORT void JNICALL
Java_com_vdopia_cocos2dx_plugin_VdopiaSDKNativeEventHandler_adDismissedRewarded(JNIEnv *env,
                                                                                jobject jobj) {
	if(rewarded_listener == nullptr) return;

	rewarded_listener->adDismissedRewarded();
}
JNIEXPORT void JNICALL
Java_com_vdopia_cocos2dx_plugin_VdopiaSDKNativeEventHandler_adCompletedRewarded(JNIEnv *env,
                                                                                jobject jobj) {
	if(rewarded_listener == nullptr) return;

	rewarded_listener->adCompletedRewarded();

}
JNIEXPORT void JNICALL
Java_com_vdopia_cocos2dx_plugin_VdopiaSDKNativeEventHandler_adShownErrorRewarded(JNIEnv *env,
                                                                                 jobject jobj) {
	if(rewarded_listener == nullptr) return;

	rewarded_listener->adShownErrorRewarded();
}

JNIEXPORT void JNICALL
Java_com_vdopia_cocos2dx_plugin_VdopiaSDKNativeEventHandler_adShownRewarded(JNIEnv *env,
                                                                            jobject jobj) {

	if(rewarded_listener == nullptr) return;

    rewarded_listener->adShownRewarded();
}
// End of Java to C++



void setAdRequestUserParams(const char *age, const char *birthdate, const char *gender,
                            const char *mstatus, const char *ethinicty, const char *dmaCode,
                            const char *postal, const char *currpostal, const char *latitude,
                            const char *longitude) {
    JniMethodInfo methodInfo;

    if (!JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "SetAdRequestUserParams",
                                        "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V")) {
        LOGD("Failed to find static method SetAdRequestUserParams ");
        return;
    }

    jstring jage = methodInfo.env->NewStringUTF(age);
    jstring jbirthDate = methodInfo.env->NewStringUTF(birthdate);
    jstring jgender = methodInfo.env->NewStringUTF(gender);
    jstring jstatus = methodInfo.env->NewStringUTF(mstatus);
    jstring jethinicty = methodInfo.env->NewStringUTF(ethinicty);
    jstring jdmaCode = methodInfo.env->NewStringUTF(dmaCode);
    jstring jpostal = methodInfo.env->NewStringUTF(postal);
    jstring jcurrpostal = methodInfo.env->NewStringUTF(currpostal);
    jstring jlatitude = methodInfo.env->NewStringUTF(latitude);
    jstring jlongitude = methodInfo.env->NewStringUTF(longitude);


    methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jage, jbirthDate,
                                         jgender, jstatus, jethinicty, jdmaCode, jpostal,
                                         jcurrpostal,
                                         jlatitude, jlongitude);
}

void setAdRequestAppParams(const char *appBundle, const char *appDomain, const char *appName,
                           const char *appStoreUrl, const char *appCategory,
                           const char *publisherDomain) {
    JniMethodInfo methodInfo;

    if (!JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "SetAdRequestAppParams",
                                        "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V")) {
        LOGD("Failed to find static method SetAdRequestAppParams");
        return;
    }

    jstring jappBundle = methodInfo.env->NewStringUTF(appBundle);
    jstring jappDomain = methodInfo.env->NewStringUTF(appDomain);
    jstring jappName = methodInfo.env->NewStringUTF(appName);
    jstring jappStoreUrl = methodInfo.env->NewStringUTF(appStoreUrl);
    jstring jappCategory = methodInfo.env->NewStringUTF(appCategory);
    jstring jpublisherDomain = methodInfo.env->NewStringUTF(publisherDomain);

    methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jappName,
                                         jappBundle, jappDomain, jpublisherDomain,
                                         jappStoreUrl, jappCategory);
}

void Java_SetPluginType() {
    const char *plugin = "cpp";
    JniMethodInfo methodInfo;
    if (!JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "SelectPluginType",
                                        "(Ljava/lang/String;)V")) {
        LOGD("Failed to find static method SelectPluginType");
        return;
    }
    jstring pluginType = methodInfo.env->NewStringUTF(plugin);
    methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, pluginType);

}


#ifdef __cplusplus
}
#endif
