#include "ShopMediator.h"
#include "CallCppHelper.h"
#include "PlatFormControl.h"
#include "DataManager.h"

#if(SDKWhich == SDK_YIKE)
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
	//helpers->PostToken(strUid, strToken);
	log("cocos2d-x payment jnicall success\n");
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
开始执行函数
*/
void ShopMediator::OnRegister()
{
	shopView = (ShopView*)getView();

	PokerGameModel* pokerGameModel = ((PokerGameModel*)getModel(PokerGameModel::NAME));
	shopView->initView();

	Size size = Director::getInstance()->getVisibleSize();
	getView()->rootNode->setPosition(size.width / 2, size.height / 2);

	refreshInfo();

}

/**
结束回收执行函数
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
事件响应函数
*/
void ShopMediator::onEvent(int i, void* data)
{
	int index = -1;
	switch (i)
	{
	case 10801:
		clickZhuanShiBtnHander();
		break;
	case 10802:
		clickGoldBtnHander();
		break;
	case 10803:
		clickCloseBtnHander();
		break;

		//zuanshi 5,  jinbi 5
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
		getGoldHander(i);
		break;
	case 10810:
		getGoldHander(i);
		break;
	case 10811:
		getGoldHander(i);
		break;
	case 10812:
		getGoldHander(i);
		break;
	case 10813:
		getGoldHander(i);
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
	return ((UILayerService*)getService(UILayerService::NAME))->uiLayer;
}

void ShopMediator::clickZhuanShiBtnHander()
{
	PLayEffect(EFFECT_BTN);
	shopView->showZuanShiView();
}

void ShopMediator::clickGoldBtnHander()
{
	PLayEffect(EFFECT_BTN);
	shopView->showGoldView();
}

void ShopMediator::clickCloseBtnHander()
{
	PLayEffect(EFFECT_BTN);
	removeView(this);
}

//购买zuanshi
void ShopMediator::getZuanShiHander(int index)
{
	PLayEffect(EFFECT_BTN)
	

	/*
	8403       特价钻石 12
	8404       100钻石 10
	8405       300钻石 30
	8406       500钻石 50,
	8407       1000钻石 100
	8408       特价金币 6
	8409       10万金币 10
	8410       30万金币 30
	8411       50万金币 50
	8412       100万金币 100
	*/

#if(SDKWhich == SDK_YIKE)
	CallCppHelper*  helper = CallCppHelper::getInstance();
	//test
	helper->callJavaPayment(8403 + index - 10804, 1, 2, 3);   //(int goodsId, int orderNum, int gold, int pay_amount)

	//release
	//	helper->callJavaPayment(8403 + index - 10804, 1, 2, 3);   //(int goodsId, int orderNum, int gold, int pay_amount)
#else
	log("clicked %d", 8403 + index - 10804);

#endif

}
void ShopMediator::getGoldHander(int index)
{
	PLayEffect(EFFECT_BTN)
#if(SDKWhich == SDK_YIKE)
	CallCppHelper*  helper = CallCppHelper::getInstance();
	helper->callJavaPayment(8408 + index - 10809, 1, 2, 3);   //(int goodsId, int orderNum, int gold, int pay_amount)
#else
	log("clicked %d", 8408 + index - 10809);
#endif
}

