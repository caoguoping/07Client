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

	//��ʾ�����е���Ʒ
	void showItems();

	//��ʾĳ����Ʒ����ϸ��Ϣ
	void showItemInfo(int index);

	//���汳��������Ϣ
	vector<Package_Item> packageItem;

private:
	BTN_TOUCH_HANDLE(Button, closeBtn, 12001);
	BTN_TOUCH_HANDLE(ImageView, Image_close, 12001);
	BTN_TOUCH_HANDLE(Button, useBtn, 12002);

	//��������
	ScrollView* itemsView;

	//��������
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

	//��ʾ����
	void showGeZi();

	//��ʾ����ͼƬ
	void showItemImage(int index);

	//
	void buyItem(float dt);

	//�����������Ʒ�����ⷢ��
	void showIsClickedImage(int index);
};

#endif