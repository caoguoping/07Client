#include "GongPaiActionView.h"

GongPaiActionView::GongPaiActionView(int pokerID)
{
	//����ID�ж��Ƶ�ͼ��
	char t[256];
	sprintf(t, "%d", pokerID);
	string s = t;

	rootNode = CSLoader::createNode(s + ".csb");
	addChild(rootNode);
	rootNode->setScale(0.5);
}

GongPaiActionView::~GongPaiActionView()
{

}

void GongPaiActionView::initView(int fromUserID,int toUserID)
{
	int fromX = 0;
	int fromY = 0;
	int toX = 0;
	int toY = 0;
	Size size = Director::sharedDirector()->getVisibleSize();
	switch (fromUserID)
	{
	//�Լ�
	case 0:
		fromX = size.width / 2;
		fromY = 200;
		break;
	//��ߵ����
	case 1:
		fromX = size.width / 4;
		fromY = size.height * 2 / 5;
		break;
    //��������
	case 2:
		fromX = size.width / 2;
		fromY = 280;
		break;
	//�ұߵ����
	case 3:
		fromX = size.width * 3 / 4;
		fromY = size.height * 2 / 5;
		break;
	}
	rootNode->setPosition(Vec2(fromX,fromY));

	//
	auto call1 = CallFunc::create(
		bind(&GongPaiActionView::remove, this)
		);

	switch (toUserID)
	{
		//�Լ�
	case 0:
		toX = size.width / 2;
		toY = 200;
		break;
		//��ߵ����
	case 1:
		toX = size.width / 4;
		toY = size.height * 2 / 5;
		break;
		//��������
	case 2:
		toX = size.width / 2;
		toY = 280;
		break;
		//�ұߵ����
	case 3:
		toX = size.width * 3 / 4;
		toY = size.height * 2 / 5;
		break;
	default:
		toX = size.width / 2;
		toY = 200;
		break;
	}	

	this->runAction(Sequence::create(MoveTo::create(1.0f, Vec2(toX-fromX, toY-fromY)), call1, nullptr));
}

void GongPaiActionView::remove()
{
	blueSkyDispatchEvent(11601);
}