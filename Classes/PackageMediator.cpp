#include "PackageMediator.h"
#include "ViewManager.h"
PackageMediator::PackageMediator()
{

}

PackageMediator::~PackageMediator()
{
	delete getView();
	setView(NULL);
}

/**
开始执行函数
*/
void PackageMediator::OnRegister()
{
	packageView = (PackageView*)getView();

	DATAPokerGame->packageItem;

	packageView->initView();
}

/**
结束回收执行函数
*/
void PackageMediator::onRemove()
{

}

/*
事件响应函数
*/
void PackageMediator::onEvent(int i, void* data)
{
	int index = -1;
	switch (i)
	{
	case 12001:
		PLayEffect(EFFECT_BTN)
		removeView(this);
		break;
// 	case 12002:
// 		clickUseBtnHander();
// 		break;
	case 12003:
		index = *(int*)data;
		nowIndex = index;
		packageView->showItemInfo(index);
		break;
	}
}

Layer* PackageMediator::getLayer()
{
	return VIEW->uiLayer;
}

void PackageMediator::clickUseBtnHander()
{
	//;
	//unsigned long dwUserID = DATA->myBaseData.dwUserID;

	////使用的是第nowIndex个物品
	//((SendDataService*)getService(SendDataService::NAME))->sendUseItem(dwUserID, packageView->packageItem.at(nowIndex).dwPropID, 1, dwUserID, 1);
}
