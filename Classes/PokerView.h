#ifndef  _PokerView_
#define  _PokerView_

#include "cocos2d.h"
#include "BlueSky.h"
#include "UILayerService.h"

using namespace std;

class  PokerView : public BlueSkyView
{
public:
	PokerView(int pokerID = -1);
	~PokerView();

	void changeToGongPai();
	void initView(bool isGongPai,int Dui);

public:
	ImageView* image1;
	Rect touchArea;

	//
	void showNode(float dt);
};



#endif