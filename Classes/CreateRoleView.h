#ifndef  _CreateRoleView_
#define  _CreateRoleView_

#include "cocos2d.h"
#include "BlueSky.h"
#include "cocostudio/CocoStudio.h"

class  CreateRoleView : public BlueSkyView
{
public:
	CreateRoleView();
	~CreateRoleView();

	void initView();
	void setCharacterState(int index);
	void showCharacterFace(Node* node,bool isSelected,int index);
	void showDaiJiFace(Node* node, int index);

private:
	BTN_TOUCH_HANDLE(Button, character1Btn, 10022);
	BTN_TOUCH_HANDLE(Button, character2Btn, 10023);
	BTN_TOUCH_HANDLE(Button, character3Btn, 10024);
	BTN_TOUCH_HANDLE(Button, character4Btn, 10025);
	BTN_TOUCH_HANDLE(Button, autoBtn, 10026);
	BTN_TOUCH_HANDLE(Button, createBtn, 10027);

	cocostudio::Armature* Action1;
	cocostudio::Armature* Action2;
	cocostudio::Armature* Action3;
	cocostudio::Armature* Action4;
};

#endif