#ifndef  _CallCPPHelper_
#define  _CallCPPHelper_

#include "BlueSky.h"

#include "cocos2d.h"
#include "network/HttpClient.h"

#include "PlatFormControl.h"

using namespace cocos2d::network;


USING_NS_CC;

class CallCppHelper : public BlueSkyCommand
{


public:

	char  mUid[32];     //uid
	char  mOrderNum[32];   //orderNum
	char  mTokenId[32];   //
	int   randomNum;    //Ëæ»úÊý
	Node*   rootNode;

public:

	static CallCppHelper * getInstance();
	void PostToken(char* uid, char* access_token);
	void onHttpRequestCompleted(cocos2d::network::HttpClient *sender, cocos2d::network::HttpResponse *response);

#if(SDKWhich == SDK_YIKE)
	char* jstringTostring(JNIEnv* env, jstring jstr);
#endif

#if(SDKWhich == SDK_YIKE)
	void callJavaPayment(int, int, int, int);
#endif

	void sendLoginData(void);
	void sendOrderNum(void);
};



#endif

