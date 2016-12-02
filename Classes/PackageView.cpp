#include "PackageView.h"
#include "DataManager.h"
#include "UTF8.h"

PackageView::PackageView()
{
	iOldClicked = 0;
	rootNode = CSLoader::createNode("package.csb");
	rootNode->setPosition(WScreen * 0.5, HScreen * 0.5);
	addChild(rootNode);

	cocostudio::timeline::ActionTimeline*  timeLine = CSLoader::createTimeline("package.csb");
	timeLine->gotoFrameAndPlay(0, false);
	rootNode->runAction(timeLine);


}

PackageView::~PackageView()
{
	rootNode->stopAllActions();
	delete rootNode;
	rootNode = NULL;

}

void PackageView::initView()
{
	UIGet_ImageView("Image_frame", rootNode, imgFrame)
		UIGet_ListView("ListView_1", imgFrame, lstItem)
		UIGet_Node("FileNode_img", imgFrame, ndImg)
		UIGet_Text("Text_name", imgFrame, txtName)
		UIGet_Text("Text_num", imgFrame, txtNum)
		UIGet_Text("Text_description", imgFrame, txtDescription)
		UIGet_Button("Button_use", imgFrame, btnUse)

		UIGet_Button("Button_close", imgFrame, closeBtn)
		UIGet_ImageView("Image_38", rootNode, Image_close)
		BTN_EVENT(closeBtn, 12001)
		BTN_EVENT(Image_close, 12001)

		showListItems();
	showItemInfo(iOldClicked);
}

//显示背包中的物品
void PackageView::showListItems()
{
	lstItem->removeAllChildrenWithCleanup(true);
	vecShowNode.clear();

	int itemHeigth = 100;
	int halfItemWidth = 84 * 0.5;
	int itemSize = DATAPokerGame->packageItem.size();
	char tempName[64];
	lstItem->setItemsMargin(100 + 16);
	for (int i = 0; i < itemSize / 4; i++) //行
	{
		Node*   oneNode[4];
		Layout*  oneLayout = Layout::create();
		for (int iList = 0; iList < 4; iList++) //列
		{
			oneNode[iList] = CSLoader::createNode("packageShow.csb");
			oneLayout->addChild(oneNode[iList]);
			oneNode[iList]->setPosition(Vec2
				(halfItemWidth * (iList * 2 + 1) + 6 * (iList + 1), -itemHeigth * 0.5));

			Text   *txtItemNum;
			ImageView  *imgBg, *imgClick, *imgItem;
			UIGet_Text("Text_num", oneNode[iList], txtItemNum)
				UIGet_ImageView("Image_bg", oneNode[iList], imgBg)
				UIGet_ImageView("Image_click", oneNode[iList], imgClick)
				UIGet_ImageView("Image_item", oneNode[iList], imgItem)
				imgBg->setTag(i * 4 + iList);
			UIClick(imgBg, PackageView::clickItem)
				txtItemNum->setString(Tools::parseInt2String(DATAPokerGame->packageItem.at(i * 4 + iList).wPropCount));
			imgClick->setVisible(false);
			int index = DATAPokerGame->packageItem.at(i * 4 + iList).wKindID;
			sprintf(tempName, "item1_%d.png", index);
			imgItem->loadTexture(tempName);
			vecShowNode.push_back(oneNode[iList]);
		}
		lstItem->pushBackCustomItem(oneLayout);
	}
	Node*  oneNode[3];
	Layout* oneLayout = Layout::create();
	for (int iList = 0; iList < itemSize % 4; iList++)
	{
		oneNode[iList] = CSLoader::createNode("packageShow.csb");
		oneLayout->addChild(oneNode[iList]);
		oneNode[iList]->setPosition(Vec2
			(halfItemWidth * (iList * 2 + 1) + 6 * (iList + 1), -itemHeigth * 0.5));
		Text   *txtItemNum;
		ImageView  *imgBg, *imgClick, *imgItem;
		UIGet_Text("Text_num", oneNode[iList], txtItemNum)
			UIGet_ImageView("Image_bg", oneNode[iList], imgBg)
			UIGet_ImageView("Image_click", oneNode[iList], imgClick)
			UIGet_ImageView("Image_item", oneNode[iList], imgItem)
			imgBg->setTag((itemSize / 4) * 4 + iList);
		UIClick(imgBg, PackageView::clickItem)
			txtItemNum->setString(Tools::parseInt2String(DATAPokerGame->packageItem.at((itemSize / 4) * 4 + iList).wPropCount));
		imgClick->setVisible(false);
		int index = DATAPokerGame->packageItem.at((itemSize / 4) * 4 + iList).wKindID;
		sprintf(tempName, "item1_%d.png", index);
		imgItem->loadTexture(tempName);
		vecShowNode.push_back(oneNode[iList]);

	}
	lstItem->pushBackCustomItem(oneLayout);
	//cocos bug  , add this ok
	Layout*   layoutFate = Layout::create();
	lstItem->pushBackCustomItem(layoutFate);

	vecShowNode.at(0)->getChildByName("Image_click")->setVisible(true);

}


void PackageView::showItemInfo(int index)
{
	ndImg->getChildByName("numText_0")->setVisible(false);
	ndImg->getChildByName("Text_num")->setVisible(false);
	
	int kindId = DATAPokerGame->packageItem.at(index).wKindID;
	int num = DATAPokerGame->packageItem.at(index).wPropCount;
	txtName->setString(UTF8String("prop", Tools::parseInt2String(kindId)));
	txtNum->setString(Tools::parseInt2String(num));
	txtDescription->setString(UTF8String("propDescription", Tools::parseInt2String(kindId)));
	char tempName[64];
	sprintf(tempName, "item1_%d.png", kindId);
	static_cast<ImageView*>(ndImg->getChildByName("Image_item"))->loadTexture(tempName);
	imgFrame->getChildByName("Button_use")->setVisible(false);

}

//点击某个物品
void PackageView::clickItem(Ref *pSender)
{
	PLayEffect(EFFECT_BTN);
	ImageView*  img = static_cast<ImageView*>(pSender);
	int tags = img->getTag();
	showItemInfo(tags);
	vecShowNode.at(iOldClicked)->getChildByName("Image_click")->setVisible(false);
	vecShowNode.at(tags)->getChildByName("Image_click")->setVisible(true);
	iOldClicked = tags;
}


//
void PackageView::buyItem(float dt)
{
	isClicked = true;
}


/*
	将被点击的物品加上外发光
*/
void PackageView::showIsClickedImage(int index)
{
// 	for (int i = 0; i < itemsShowNode.size(); i++)
// 	{
// 		ImageView* isClickedImage = dynamic_cast<ImageView*>(itemsShowNode.at(i)->getChildByName("isClickedImage"));
// 		if (i == index)
// 		{
// 			isClickedImage->setVisible(true);
// 		}
// 		else
// 		{
// 			isClickedImage->setVisible(false);
// 		}
// 	}
	
}