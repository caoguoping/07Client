#include "ViewMatchRanking.h"
#include "DataManager.h"

ViewMatchRanking::~ViewMatchRanking()
{
	//rootNode->removeFromParentAndCleanup(true);
}
ViewMatchRanking* ViewMatchRanking::create()
{
	ViewMatchRanking * pViewMatchRanking = new ViewMatchRanking();
	if (pViewMatchRanking)
	{
		pViewMatchRanking->initView();
		pViewMatchRanking->autorelease();
	}
	else
		CC_SAFE_DELETE(pViewMatchRanking);
	return pViewMatchRanking;
}

void ViewMatchRanking::initView()
{
	rootNode = CSLoader::createNode("matchProcess.csb");
	rootNode->setPosition(WScreen * 0.5, HScreen * 0.5);
	this->addChild(rootNode);
	UIGet_ListView("ListView_rank", rootNode, matchRankList)

		UIGet_Button("Button_1", rootNode, btn1)
		UIGet_Button("Button_2", rootNode, btn2)
		UIGet_Button("Button_3", rootNode, btn3)
		UIGet_ImageView("Image_frameHead", rootNode, imgHeadPos)
		UIGet_LoadingBar("LoadingBar_1", rootNode, barMatchPro)

}

void ViewMatchRanking::updateMatchRanking(void* data)
{
	matchRankList->removeAllChildrenWithCleanup(true);
#define MATCH_RANK_ITEM_HEIGHT 56
	matchRankList->setItemsMargin(MATCH_RANK_ITEM_HEIGHT + 10);
	rankData = (CMD_GR_MATCH_RANKING*)data;

	for (int i = 0; i < DATA->wMatchPlayer; i++)
	{
		Node* rankNode = CSLoader::createNode("matchProRank.csb");
		Layout*  oneRank = Layout::create();
		oneRank->addChild(rankNode);
		rankNode->setPosition(Vec2(200, -MATCH_RANK_ITEM_HEIGHT * 0.5));
		Text  *rank, *name, *txtScore;

		UIGet_Text("Text_rank", rankNode, rank)
			UIGet_Text("Text_name", rankNode, name)
			UIGet_Text("Text_score", rankNode, txtScore)

			rank->setString(Tools::parseInt2String(i + 1));
		name->setString(rankData->rankingInfo[i].szSendNickName);
		txtScore->setString(Tools::parseInt2String(rankData->rankingInfo[i].wMatchScore));
		matchRankList->pushBackCustomItem(oneRank);

	}
	Layout*   layoutFate = Layout::create();
	matchRankList->pushBackCustomItem(layoutFate);

	if (DATA->wMatchNowLuanci == 1)
	{
		btn3->setEnabled(false);   //¸ßÁÁ
		btn2->setEnabled(true);
		barMatchPro->setPercent(25.0f);
		imgHeadPos->setPositionY(btn3->getPositionY());
	}
	else if (DATA->wMatchNowLuanci == 2)
	{
		btn3->setEnabled(true);   //¸ßÁÁ
		btn2->setEnabled(false);
		barMatchPro->setPercent(50.0f);
		imgHeadPos->setPositionY(btn2->getPositionY());
	}


}