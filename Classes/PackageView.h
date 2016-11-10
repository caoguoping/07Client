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
	//��ʾ�б��
	void showListItems();
	vector <Node*> vecShowNode;

	//��ʾĳ����Ʒ����ϸ��Ϣ
	void showItemInfo(int index);


private:
	BTN_TOUCH_HANDLE(Button, closeBtn, 12001);
	BTN_TOUCH_HANDLE(ImageView, Image_close, 12001);

	ImageView*  imgFrame;
	ListView*  lstItem;
	Node*  ndImg;
	Text  *txtName, *txtNum, *txtDescription;
	Button*   btnUse;

	void clickItem(Ref *pSender);
	bool isClicked = true;
	void buyItem(float dt);

	//�����������Ʒ�����ⷢ��
	void showIsClickedImage(int index);
};

#endif