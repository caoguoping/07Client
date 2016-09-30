#ifndef  _VIEW_MATCHRANKING_H_
#define  _VIEW_MATCHRANKING_H_

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "UTF8.h"
#include "SGTools.h"
#include "PokerGameModel.h"
USING_NS_CC;

class  ViewMatchRanking : public Node
{
public:
	~ViewMatchRanking();
	static ViewMatchRanking * create();
	void initView();
	void updateMatchRanking(void* data);

public:
	CMD_GR_MATCH_RANKING* rankData;
	Node*  rootNode;
	ListView*   matchRankList;

	Button*  btn1;  //4ǿ
	Button*  btn2;
	Button*  btn3;  //12��8
	ImageView*  imgHeadPos;  
	LoadingBar*  barMatchPro;
	Text*    txtLeftDesk;   //ʣ��������

};

#endif