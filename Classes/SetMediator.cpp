#include "SetMediator.h"

SetMediator::SetMediator()
{

}

SetMediator::~SetMediator()
{
	delete getView();
	setView(NULL);
}

/**
��ʼִ�к���
*/
void SetMediator::OnRegister()
{
	setView1 = (SetView*)getView();
	setView1->initView();
	Size size = Director::getInstance()->getVisibleSize();
	getView()->rootNode->setPosition(size.width / 2, size.height / 2);
}

/**
��������ִ�к���
*/
void SetMediator::onRemove()
{

}

/*
�¼���Ӧ����
*/
void SetMediator::onEvent(int i, void* data)
{
	switch (i)
	{
	case 14001:
		clickCloseBtnHander();
		break;
	case 14005:
		clickReLoginBtnHander();
		break;
	case 14006:
		clickHelpBtnHander();
		break;
	}
}

Layer* SetMediator::getLayer()
{
	return ((UILayerService*)getService(UILayerService::NAME))->uiLayer;
}

void SetMediator::clickCloseBtnHander()
{
	removeView(this);
}

void SetMediator::clickReLoginBtnHander()
{
	//���������Ϣ����
	PokerGameModel* pokerGameModel = ((PokerGameModel*)getModel(PokerGameModel::NAME));
	pokerGameModel->dailyMisInfo.clear();
	pokerGameModel->mallGoodsInfo.clear();
	pokerGameModel->packageItem.clear();

	creatView(new LoginView(),new LoginMediator());
	blueSkyDispatchEvent(EventType::RE_LOGIN);
	removeView(this);
}

void SetMediator::clickHelpBtnHander()
{
	creatView(new HelpView(),new HelpMediator());
	removeView(this);
}