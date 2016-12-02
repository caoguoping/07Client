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
	Button* character1Btn;
	Button* character2Btn;
	Button* character3Btn;
	Button* character4Btn;
	Button* autoBtn      ;
	Button* createBtn    ;

	cocostudio::Armature* Action1;
	cocostudio::Armature* Action2;
	cocostudio::Armature* Action3;
	cocostudio::Armature* Action4;
};

#endif