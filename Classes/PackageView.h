#ifndef  _PackageView_
#define  _PackageView_

#include "cocos2d.h"
#include "BlueSky.h"
#include "cocostudio/CocoStudio.h"
#include "PokerGameModel.h"

class  PackageView : public BlueSkyView
{
public:
	PackageView();
	~PackageView();
	void initView();

	//显示背包中的物品
	void showItems();

	//显示某个物品的详细信息
	void showItemInfo(int index);

	//储存背包道具信息
	vector<Package_Item> packageItem;

private:
	BTN_TOUCH_HANDLE(Button, closeBtn, 12001);
	BTN_TOUCH_HANDLE(ImageView, Image_close, 12001);
	BTN_TOUCH_HANDLE(Button, useBtn, 12002);

	//滚动容器
	ScrollView* itemsView;

	//道具描述
	Text* doubleExpText;
	Text* doubleGoldText;
	Text* liBaoText;
	Text* jiPaiQiText;
	Text* enterCardText;

	//
	vector<Node*> itemsShowNode;
	vector<ImageView*> ImageArr;

	//
	void clickItem(Ref *pSender, int i);
	bool isClicked = true;

	//显示格子
	void showGeZi();

	//显示道具图片
	void showItemImage(int index);

	//
	void buyItem(float dt);

	//将被点击的物品加上外发光
	void showIsClickedImage(int index);
};

#endif