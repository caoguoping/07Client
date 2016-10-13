#include "PokerView.h"
PokerView::PokerView(int pokerID)
{
	//����ID�ж��Ƶ�ͼ��
	char t[256];
	sprintf(t, "%d", pokerID);
	string s = t; 

	rootNode = CSLoader::createNode(s + ".csb");
	addChild(rootNode);
}
PokerView::~PokerView()
{
	delete rootNode;
	rootNode = NULL;
}

void PokerView::changeToGongPai()
{
	//��ʾ���Ʊ��
	image1->setVisible(true);
}

void PokerView::initView(bool isGongPai, int Dui)
{
	//
	image1 = dynamic_cast<ImageView*>(rootNode->getChildByName("Image_1"));
	image1->setVisible(isGongPai);

	//
	rootNode->setVisible(false); 

	//
	this->scheduleOnce(schedule_selector(PokerView::showNode), Dui/20.0f);
}

void PokerView::showNode(float dt)
{
	rootNode->setVisible(true);
}



