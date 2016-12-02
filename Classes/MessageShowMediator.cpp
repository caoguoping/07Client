#include "MessageShowMediator.h"
#include "ViewManager.h"
MessageShowMediator::MessageShowMediator()
{

}

MessageShowMediator::~MessageShowMediator()
{
	delete getView();
	setView(NULL);
}

/**
��ʼִ�к���
*/
void MessageShowMediator::OnRegister()
{
	messageShowView = (MessageShowView*)getView();

	//
	messageShowView->initView();

	Size size = Director::getInstance()->getVisibleSize();
	getView()->rootNode->setPosition(size.width / 2, size.height / 2);
}

/**
��������ִ�к���
*/
void MessageShowMediator::onRemove()
{

}

/*
�¼���Ӧ����
*/
void MessageShowMediator::onEvent(int i, void* data)
{
	MessageVO megData;
	switch (i)
	{
	case 11901:
		if (canShowMessage)
		{
			megData = *(MessageVO*)data;
			messageShowView->showMessage(megData.type, megData.name);
		}
		break;
	case 11902:
		messageShowView->hideMessage();
		break;
	case 11903:
		messageShowView->hideMessage();
		break;
	case 11904:
		messageShowView->hideMessage();
		break;
	case 11905:
		canShowMessage = !canShowMessage;
		break;
	}
}

Layer* MessageShowMediator::getLayer()
{
	return VIEW->TopLayer;
}
