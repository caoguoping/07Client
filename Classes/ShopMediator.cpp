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
��ʼִ�к���
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

