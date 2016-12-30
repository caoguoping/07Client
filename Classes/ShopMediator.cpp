#include "ShopMediator.h"
#include "CallCppHelper.h"
#include "PlatFormControl.h"
#include "DataManager.h"
#include "ViewManager.h"

#if(SDKWhich == SDK_YIKE && PlatWhich == PlatAdr)
#include "org_cocos2dx_cpp_SDKPlugin.h"
#include "CallCppHelper.h"
#include "cocos2d.h"
#include "platform/android/jni/JniHelper.h"
#include <jni.h>

JNIEXPORT void JNICALL Java_org_cocos2dx_cpp_SDKPlugin_paySecessCallback(JNIEnv * env, jclass jc, jstring orderNum, jstring save)
{
	CallCppHelper*  helpers = CallCppHelper::getInstance();

	memset(helpers->mOrderNum, 0, 32);

	char* tempChar = helpers->jstringTostring(env, orderNum);
	strncpy(helpers->mOrderNum, tempChar, 32);
	log("cocos2d-x javaCallCpp mOrderNum %s",  helpers->mOrderNum);
	helpers->sendOrderNum();
}
#endif

ShopMediator::ShopMediator()
{

}

ShopMediator::~ShopMediator()
{
	delete getView();
	setView(NULL);
}

/**
��ʼִ�к���
*/
void ShopMediator::OnRegister()
{
	shopView = (ShopView*)getView();

	shopView->initView();

	Size size = Director::getInstance()->getVisibleSize();
	getView()->rootNode->setPosition(size.width / 2, size.height / 2);

	refreshInfo();

}

/**
��������ִ�к���
*/
void ShopMediator::onRemove()
{

}

void ShopMediator::refreshInfo()
{
	shopView->showMyGold(DATA->myBaseData.lUserScore);
	shopView->showMyZuanShi(DATA->myBaseData.rmb);
}


/*
�¼���Ӧ����
*/
void ShopMediator::onEvent(int i, void* data)
{
	switch (i)
	{
	case 10803:
		PLayEffect(EFFECT_BTN)
		clickCloseBtnHander();
		break;
	case 10804:
		getZuanShiHander(i);
		break;
	case 10805:
		getZuanShiHander(i);
		break;
	case 10806:
		getZuanShiHander(i);
		break;
	case 10807:
		getZuanShiHander(i);
		break;
	case 10808:
		getZuanShiHander(i);
		break;
	case 10809:
		getZuanShiHander(i);
		break;
	case 10810:
		getZuanShiHander(i);
		break;
	case 10811:
		getZuanShiHander(i);
		break;
	case 10812:
		getZuanShiHander(i);
		break;
	case 10813:
		getZuanShiHander(i);
		break;
	case EventType::GAME_OVER:
	case EventType::BACK_TO_HALL:
		removeView(this);
		break;
	default:
		break;
	}
}

Layer* ShopMediator::getLayer()
{
	return VIEW->uiLayer;
}

void ShopMediator::clickCloseBtnHander()
{
	PLayEffect(EFFECT_BTN);
	removeView(this);
}

//����zuanshi
void ShopMediator::getZuanShiHander(int index)
{
	PLayEffect(EFFECT_BTN)
	

	/*
	8403       �ؼ���ʯ 12
	8404       100��ʯ 10
	8405       300��ʯ 30
	8406       500��ʯ 50,
	8407       1000��ʯ 100
	8408       �ؼ۽�� 6
	8409       10���� 10
	8410       30���� 30
	8411       50���� 50
	8412       100���� 100
	*/

#if(SDKWhich == SDK_YIKE && PlatWhich == PlatAdr)
	CallCppHelper*  helper = CallCppHelper::getInstance();
	helper->callJavaPayment(8403 + index - 10804, 1, 2, 3);  
#endif
    
#if(SDKWhich == SDK_YIKE && PlatWhich == PlatIos)
    CallCppHelper*  helper = CallCppHelper::getInstance();
    helper->callJavaPayment(8403 + index - 10804);
#endif
    
}

