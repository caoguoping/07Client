#ifndef  _HelpView_
#define  _HelpView_

#include "cocos2d.h"
#include "BlueSky.h"
#include "cocostudio/CocoStudio.h"

class  HelpView : public BlueSkyView
{
public:
	HelpView();
	~HelpView();

	void initView();

public:
	Button   *closeBtn ;
	ImageView* Image_38;

	//
	//��������
	ScrollView* mScrollView[5];  //���ͣ� ���ʹ�С����Ϸ���֣����ƹ�����Ϸ�ȼ�
	CheckBox*    mCheckBox[5];

	void clickCheckBox(Ref*  pSender);
	void handleWhich(int iwhich);
};

#endif