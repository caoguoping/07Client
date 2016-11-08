#include "PackageView.h"

PackageView::PackageView()
{
	rootNode = CSLoader::createNode("package.csb");
	addChild(rootNode);
	rootNode->setScale(0.8f, 0.8f);
	rootNode->runAction(Sequence::create(
		ScaleTo::create(0.2f, 1.03f),
		ScaleTo::create(0.15f, 1.0f),
		nullptr));

	BTN_ADD_TOUCH_EVENTLISTENER(Button, PackageView, closeBtn, 12001, "closeBtn", NULL)
	BTN_ADD_TOUCH_EVENTLISTENER(Button, PackageView, useBtn, 12002, "useBtn", NULL)
	BTN_ADD_TOUCH_EVENTLISTENER(ImageView, PackageView, Image_close, 12001, "Image_38", NULL)
}

PackageView::~PackageView()
{
	BTN_REMOVE_TOUCH_EVENTLISTENER(PackageView, closeBtn, 12001);
	BTN_REMOVE_TOUCH_EVENTLISTENER(PackageView, Image_close, 12001);
	BTN_REMOVE_TOUCH_EVENTLISTENER(PackageView, useBtn, 12002);
}

void PackageView::initView()
{
	//
	doubleExpText = dynamic_cast<Text*>(rootNode->getChildByName("doubleExpText"));
	doubleGoldText = dynamic_cast<Text*>(rootNode->getChildByName("doubleGoldText"));
	liBaoText = dynamic_cast<Text*>(rootNode->getChildByName("liBaoText"));
	jiPaiQiText = dynamic_cast<Text*>(rootNode->getChildByName("jiPaiQiText"));
	enterCardText = dynamic_cast<Text*>(rootNode->getChildByName("enterCardText"));

	//
	itemsView = dynamic_cast<ScrollView*>(rootNode->getChildByName("ScrollView_1"));
	itemsView->setScrollBarEnabled(false);

	Size size = Director::sharedDirector()->getVisibleSize();
	rootNode->setPosition(Vec2(size.width / 2, size.height / 2));

	//
	showItems();
}

//��ʾ�����е���Ʒ
void PackageView::showItems()
{
	for (int i = 0; i < ImageArr.size(); i++)
	{
		Director::getInstance()->getEventDispatcher()->removeEventListenersForTarget(ImageArr.at(i));
	}
	ImageArr.clear();
	itemsShowNode.clear();
	itemsView->removeAllChildren();

	//����ʾ����
	showGeZi();

	//���洦����Ʒ�ľ�����ʾ���¼�����
	for (int i = 0; i < itemsShowNode.size(); i++)
	{
		ImageArr.push_back(dynamic_cast<ImageView*>(itemsShowNode.at(i)->getChildByName("Image_1")));
	}
	//
	for (int i = 0; i < ImageArr.size(); i++)
	{
		ImageArr.at(i)->addTouchEventListener(CC_CALLBACK_1(PackageView::clickItem, this, i));
	}
	//
	for (int i = 0; i < itemsShowNode.size(); i++)
	{
		//��ʾ��Ʒ��ͼƬ�͸���
		Text* numText = dynamic_cast<Text*>(itemsShowNode.at(i)->getChildByName("numText"));
		ImageView* Image_2 = dynamic_cast<ImageView*>(itemsShowNode.at(i)->getChildByName("Image_2"));

		//û����Ʒ�ĸ�����ʾ��
		if ((i + 1) > packageItem.size())
		{
			numText->setVisible(false);
			showItemImage(i);
		}
		else
		{
			//����ID��ʾͼƬ
			showItemImage(i);

			//��ʾ����
			int num = packageItem.at(i).wPropCount;
			char t[256];
			sprintf(t, "%d", num);
			if (num > 1)
			{
				numText->setString(t);
			}
			else
			{
				numText->setVisible(false);
				Image_2->setVisible(false);
			}
		}

	}
	//Ĭ����ѡ�е�һ����Ʒ
	clickItem(nullptr, 0);
}

//��ʾ����
void PackageView::showGeZi()
{
	//��Ʒ����С��10����ʾ9������
	if (packageItem.size() < 10)
	{
		for (int i = 0; i < 9; i++)
		{
			itemsShowNode.push_back(CSLoader::createNode("packageShow.csb"));
			itemsView->addChild(itemsShowNode.at(i));
		}
	}
	//������ʾ3�ı���������
	else
	{
		if (packageItem.size() % 3 > 0)
		{
			for (int i = 0; i < packageItem.size() / 3 + 3; i++)
			{
				itemsShowNode.push_back(CSLoader::createNode("packageShow.csb"));
				itemsView->addChild(itemsShowNode.at(i));
			}
		}
		else
		{
			for (int i = 0; i < packageItem.size(); i++)
			{
				itemsShowNode.push_back(CSLoader::createNode("packageShow.csb"));
				itemsView->addChild(itemsShowNode.at(i));
			}
		}
	}

	int num = itemsShowNode.size() / 3;
	if (itemsShowNode.size() > num * 3)
		num++;
	itemsView->setInnerContainerSize(Size(350, 116 * num));
	itemsView->scrollToTop(1.0f, true);

	int XPos = 60;
	int YPos = 180;
	if (num == 1)
		YPos =180;
	else
		YPos = 180 + 116 * (num - 2);

	for (int i = 0; i < itemsShowNode.size(); i++)
	{
		int j = (i + 1) / 3;
		int k = (i + 1) % 3;
		if (k == 0)
		{
			k = 3;
			j--;
		}
		itemsShowNode.at(i)->setPosition(Vec2(XPos + (k - 1) * 114, YPos - j * 114));
	}
}

//��ʾ����ͼƬ
void PackageView::showItemImage(int index)
{
	ImageView* doubleExpImage = dynamic_cast<ImageView*>(itemsShowNode.at(index)->getChildByName("doubleExpImage"));
	ImageView* doubleGoldImage = dynamic_cast<ImageView*>(itemsShowNode.at(index)->getChildByName("doubleGoldImage"));
	ImageView* enterCardImage = dynamic_cast<ImageView*>(itemsShowNode.at(index)->getChildByName("enterCardImage"));
	ImageView* jiPaiQiImage = dynamic_cast<ImageView*>(itemsShowNode.at(index)->getChildByName("jiPaiQiImage"));
	ImageView* liBaoImage = dynamic_cast<ImageView*>(itemsShowNode.at(index)->getChildByName("liBaoImage"));
	ImageView* Image_2 = dynamic_cast<ImageView*>(itemsShowNode.at(index)->getChildByName("Image_2"));
	ImageView* isClickedImage = dynamic_cast<ImageView*>(itemsShowNode.at(index)->getChildByName("isClickedImage"));

	if ((index + 1) > packageItem.size())
	{
		doubleExpImage->setVisible(false);
		doubleGoldImage->setVisible(false);
		enterCardImage->setVisible(false);
		jiPaiQiImage->setVisible(false);
		liBaoImage->setVisible(false);
		Image_2->setVisible(false);
		isClickedImage->setVisible(false);
	}
	else
	{
		doubleExpImage->setVisible(false);
		doubleGoldImage->setVisible(false);
		enterCardImage->setVisible(false);
		jiPaiQiImage->setVisible(false);
		liBaoImage->setVisible(false);
		isClickedImage->setVisible(false);
		switch (packageItem.at(index).wKindID)
		{
				//˫����ҿ�
			case 6:
				doubleGoldImage->setVisible(true);
				break;
				//˫�����ֿ�
			case 7:
				doubleExpImage->setVisible(true);
				break;
				
				
				//������
			case 8:
				jiPaiQiImage->setVisible(true);
				break;
				//С����
			case 9:
				break;
				//������
			case 10:
				break;
				//�볡ȯ
			case 11:
				enterCardImage->setVisible(true);
				break;
				//����
			case 12:
				break;
				//����
			case 13:
				break;
				//����
			case 14:
				break;
		}
	}
}

//���ĳ����Ʒ
void PackageView::clickItem(Ref *pSender, int i)
{
	//isClicked = !isClicked;
	if (isClicked)
	{
		isClicked = false;
		this->scheduleOnce(schedule_selector(PackageView::buyItem), 0.5f);

		blueSkyDispatchEvent(12003, new int(i));
		//
		if (!((i+1) > packageItem.size()))
		{
			//
			blueSkyDispatchEvent(20050);

			//�����������Ʒ�����ⷢ��
			showIsClickedImage(i);
		}
	}
}


//
void PackageView::buyItem(float dt)
{
	isClicked = true;
}

/*
	��ʾĳ����Ʒ����ϸ��Ϣ
	������index:�ڼ�����Ʒ
*/
void PackageView::showItemInfo(int index)
{
	Text* doubleExpText = dynamic_cast<Text*>(rootNode->getChildByName("doubleExpText"));
	Text* doubleGoldText = dynamic_cast<Text*>(rootNode->getChildByName("doubleGoldText"));
	Text* liBaoText = dynamic_cast<Text*>(rootNode->getChildByName("liBaoText"));
	Text* jiPaiQiText = dynamic_cast<Text*>(rootNode->getChildByName("jiPaiQiText"));
	Text* enterCardText = dynamic_cast<Text*>(rootNode->getChildByName("enterCardText"));

	ImageView* doubleExpImage = dynamic_cast<ImageView*>(rootNode->getChildByName("doubleExpImage"));
	ImageView* doubleGoldImage = dynamic_cast<ImageView*>(rootNode->getChildByName("doubleGoldImage"));
	ImageView* zuanShiLiBaoImage = dynamic_cast<ImageView*>(rootNode->getChildByName("zuanShiLiBaoImage"));
	ImageView* goldLiBaoImage = dynamic_cast<ImageView*>(rootNode->getChildByName("goldLiBaoImage"));
	ImageView* jiPaiQiImage = dynamic_cast<ImageView*>(rootNode->getChildByName("jiPaiQiImage"));
	ImageView* enterCardImage = dynamic_cast<ImageView*>(rootNode->getChildByName("enterCardImage"));

	//����ID��ʾ��ϸ��Ϣ
	doubleExpText->setVisible(false);
	doubleGoldText->setVisible(false);
	liBaoText->setVisible(false);
	jiPaiQiText->setVisible(false);
	enterCardText->setVisible(false);
	doubleExpImage->setVisible(false);
	doubleGoldImage->setVisible(false);
	zuanShiLiBaoImage->setVisible(false);
	goldLiBaoImage->setVisible(false);
	jiPaiQiImage->setVisible(false);
	enterCardImage->setVisible(false);
	if (!((index + 1) > packageItem.size()))
	{
		switch (packageItem.at(index).wKindID)
		{
			//˫����ҿ�
		case 6:
			doubleGoldText->setVisible(true);
			doubleGoldImage->setVisible(true);
			break;
			//˫�����ֿ�
		case 7:
			doubleExpText->setVisible(true);
			doubleExpImage->setVisible(true);
			break;
			//������
		case 8:
			jiPaiQiText->setVisible(true);
			jiPaiQiImage->setVisible(true);
			break;
			//С����
		case 9:
			break;
			//������
		case 10:
			break;
			//�볡ȯ
		case 11:
			enterCardText->setVisible(true);
			enterCardImage->setVisible(true);
			break;
			//����
		case 12:
			break;
			//����
		case 13:
			break;
			//����
		case 14:
			break;
		}
	}
}

/*
	�����������Ʒ�����ⷢ��
*/
void PackageView::showIsClickedImage(int index)
{
	for (int i = 0; i < itemsShowNode.size(); i++)
	{
		ImageView* isClickedImage = dynamic_cast<ImageView*>(itemsShowNode.at(i)->getChildByName("isClickedImage"));
		if (i == index)
		{
			isClickedImage->setVisible(true);
		}
		else
		{
			isClickedImage->setVisible(false);
		}
	}
	
}