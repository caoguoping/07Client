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
��ʼִ�к���
*/
void PackageMediator::OnRegister()
{
	packageView = (PackageView*)getView();

	DATAPokerGame->packageItem;

	packageView->initView();
}

/**
��������ִ�к���
*/
void PackageMediator::onRemove()
{

}

/*
�¼���Ӧ����
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

	////ʹ�õ��ǵ�nowIndex����Ʒ
	//((SendDataService*)getService(SendDataService::NAME))->sendUseItem(dwUserID, packageView->packageItem.at(nowIndex).dwPropID, 1, dwUserID, 1);
}
