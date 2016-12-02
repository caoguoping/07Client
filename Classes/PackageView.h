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

	int iOldClicked;
	//显示列表框
	void showListItems();
	vector <Node*> vecShowNode;

	//显示某个物品的详细信息
	void showItemInfo(int index);


private:
	Button   * closeBtn   ;
	ImageView* Image_close;

	ImageView*  imgFrame;
	ListView*  lstItem;
	Node*  ndImg;
	Text  *txtName, *txtNum, *txtDescription;
	Button*   btnUse;

	void clickItem(Ref *pSender);
	bool isClicked = true;
	void buyItem(float dt);

	//将被点击的物品加上外发光
	void showIsClickedImage(int index);
};

#endif