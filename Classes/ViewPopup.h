#ifndef  _VIEW_POPUP_H_
#define  _VIEW_POPUP_H_

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "UTF8.h"
#include "SGTools.h"
#include "PokerGameModel.h"
#include "DataManager.h"
USING_NS_CC;

class  ViewPopup : public Node
{
public:
	typedef enum popupKind
	{
		popupFriendInvite = 0,

	}E_PopupKind;



	~ViewPopup();
	static ViewPopup * create(DWORD dwKinds, void*  data = NULL);
	void initView();
	void updatePopup(void* data);
	void clickBtnOk(Ref*  pSender);
	void clickBtnNo(Ref*  pSender);
	void clickClose(Ref*  pSender);
	void* getModel(string name);

public:
	DWORD dwKind;
	CMD_SUB_C_INVITE_ENTER_GAME*  friendInvite;
	Node*  rootNode;
	Button*  btnOK;
	Button*  btnNo;
	Button*  btnClose;  
	ImageView*  imgCLose;  
	Text*    txtName;  

};

#endif