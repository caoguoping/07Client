#include "LoginMediator.h"
#include "PlatFormControl.h"
#include "CallCppHelper.h"
#include "ViewManager.h"
#include "LoginView.h"

#include "cocos2d.h"
#include "network/HttpClient.h"
using namespace cocos2d::network;

#if(SDKWhich == SDK_YIKE && PlatWhich == PlatAdr)
#include "platform/android/jni/JniHelper.h"
#include <jni.h>
#include "org_cocos2dx_cpp_SDKPlugin.h"
#endif




#if(SDKWhich == SDK_YIKE && PlatWhich == PlatAdr)
JNIEXPORT void JNICALL Java_org_cocos2dx_cpp_SDKPlugin_LoginCallback(JNIEnv * env, jclass jc, jstring uid, jstring access_token)
{
    log("cocos2d-x jniCall LoginCallback");
    CallCppHelper*  helpers = CallCppHelper::getInstance();
    
    const char* strUid = helpers->jstringTostring(env, uid);
    const char* strToken = helpers->jstringTostring(env, access_token);
   // helpers->PostToken(strUid, strToken);
    strncpy(helpers->mUid, strUid, 32);
    char temps[128];
    sprintf(temps, "u %s , tken %s ", helpers->mUid, helpers->mTokenId);
    helpers->sendLoginData();
    
}
#endif

#if(SDKWhich == SDK_YIKE && PlatWhich == PlatIos)
#include "OcCaller.h"
#endif

void LoginMediator::callJavaLogin()
{
   
#if(SDKWhich == SDK_YIKE && PlatWhich == PlatAdr)
	JniMethodInfo info;
	bool ret = JniHelper::getStaticMethodInfo(info, "org/cocos2dx/cpp/AppActivity", "login", "()V");
	if (ret)
	{
		log("callJava init success\n");
		info.env->CallStaticVoidMethod(info.classID, info.methodID);
	}
#endif
    
#if(SDKWhich == SDK_YIKE && PlatWhich == PlatIos)
     OcCaller::getInstance()->SDKLogin();
#endif
    
#if(SDKWhich == SDK_NULL)
	CallCppHelper*  helpers = CallCppHelper::getInstance();
	helpers->sendLoginData();

#endif

#if(SDKWhich == SDK_CREATE_ROLE)
	static_cast<LoginView*>(getView())->createRoleTest();

#endif

}


LoginMediator::~LoginMediator()
{
	delete getView();
	setView(NULL);
}


/**
开始执行函数
*/
void LoginMediator::OnRegister()
{
	acountText = dynamic_cast<TextField*>(getView()->rootNode->getChildByName("acount_text"));
	passwordText = dynamic_cast<TextField*>(getView()->rootNode->getChildByName("password_text"));
	ipText = dynamic_cast<TextField*>(getView()->rootNode->getChildByName("ip_text"));

	auto  action = Sequence::create(
		DelayTime::create(0.5f),
		CallFunc::create(CC_CALLBACK_0(LoginMediator::callJavaLogin, this)), nullptr
		);
	this->getLayer()->runAction(action);
}


/**
	结束回收执行函数 
*/
void LoginMediator::onRemove()
{

}

/*
	事件响应
*/
void LoginMediator::onEvent(int i, void* data)
{
	switch (i)
	{
	case EventType::LOGIN_COMPLETE:
		removeView(this);
		break;
	case 10001:
		clickRegistBtnHander();
		break;
	case 10002:
		clickLoginBtnHander();
		break;
	case REGIST_CHARACTER:
		removeView(this);
		break;
	case 10003:
		cocostudio::Armature* action = dynamic_cast<cocostudio::Armature*>(getView()->rootNode->getChildByName("ArmatureNode_1"));
		action->getAnimation()->play("logo", -1, 0);
		break;
	}
}

void LoginMediator::clickRegistBtnHander()
{

// 	if (passwordText->getString() == "" || acountText->getString() == "")
// 		{
// 			blueSkyDispatchEvent(EventType::ALERT, new AlertVO(0, "err", "err4", -1, -1));
// 			return;
// 		}
// 		registLogin *rLogin = new registLogin();
// 		rLogin->type = 2;
// 		rLogin->cbGender = random(1, 2);
// 		rLogin->szAccounts = (this->acountText->getString()).data();
// 		rLogin->szLogonPass = (passwordText->getString()).data();
// 		//
// 		if (ipText->getString() == "")
// 			rLogin->ip = "";
// 		else
// 			rLogin->ip = (ipText->getString()).data();
// 		blueSkyDispatchEvent(EventType::REGIST_CHARACTER, rLogin);

}

void LoginMediator::clickLoginBtnHander()
{


// 	registLogin *rLogin = new registLogin();
// 		rLogin->type = 1;
// 		rLogin->szAccounts = (this->acountText->getString()).data();
// 		rLogin->szLogonPass = (passwordText->getString()).data();
// 		//
// 		if (ipText->getString() == "")
// 			rLogin->ip = "";
// 		else
// 			rLogin->ip = (ipText->getString()).data();
// 		blueSkyDispatchEvent(EventType::SOCKET_INIT, rLogin);
// 		//loginBtn->setScale(0.3);
// 

// 		
}

Layer* LoginMediator::getLayer()
{
	return VIEW->mainLayer;
}
