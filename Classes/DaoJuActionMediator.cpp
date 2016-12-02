#include "DaoJuActionMediator.h"
#include "ViewManager.h"
DaoJuActionMediator::DaoJuActionMediator(DAO_JU_ACTION data)
{
	index = data.index;
	fromDesk = data.fromDesk;
	toDeskID = data.toDesk;
	id = data.id;
}

DaoJuActionMediator::~DaoJuActionMediator()
{
	delete getView();
	setView(NULL);
}

/**
开始执行函数
*/
void DaoJuActionMediator::OnRegister()
{
	daoJuActionView = (DaoJuActionView*)getView();

	daoJuActionView->initView(index, fromDesk, toDeskID, id);
}

/**
结束回收执行函数
*/
void DaoJuActionMediator::onRemove()
{

}

/*
事件响应函数
*/
void DaoJuActionMediator::onEvent(int i, void* data)
{
	int actionID = -1;
	switch (i)
	{
	case EventType::BACK_TO_HALL:
		removeView(this);
		break;
	case 11801:
		actionID = *(int*)data;
		if (actionID == id)
		{
			removeView(this);
			break;
		}

	}
}

Layer* DaoJuActionMediator::getLayer()
{
	return VIEW->uiLayer;
}
