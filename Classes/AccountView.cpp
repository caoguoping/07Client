#include "AccountView.h"
#include "DataManager.h"
#include "SGTools.h"
AccountView::AccountView()
{
	if (DATA->bGameCate == DataManager::E_GameCateNormal ||
		DATA->bGameCate == DataManager::E_GameRandZhupai
		) 
	{
		rootNode = CSLoader::createNode("jieShuan.csb");
		addChild(rootNode);
		BTN_ADD_TOUCH_EVENTLISTENER(Button, AccountView, continueBtn, 10502, "continueBtn", NULL);
	}

	else if (DATA->bGameCate == DataManager::E_GameCateMatch)  //±ÈÈü
	{
		rootNode = CSLoader::createNode("jieShuan_match.csb");
		addChild(rootNode);
		BTN_ADD_TOUCH_EVENTLISTENER(Button, AccountView, nextMatchBtn, 10503, "nextMatchBtn", NULL);

		UIGet_Layout("Panel_win", rootNode, winLayout)
			UIGet_Layout("Panel_fail", rootNode, loseLayout)
			UIGet_Text("Text_matchNum", rootNode, txtPeoples)
			UIGet_Text("Text_matchRank", rootNode, txtRanks)
			UIGet_Text("Text_matchRankBest", rootNode, txtBestRanks)
			UIGet_Text("Text_reward", winLayout,txtRewards)


	}

	BTN_ADD_TOUCH_EVENTLISTENER(Button, AccountView, fanHuiBtn, 10501, "fanHuiBtn", NULL);



}
AccountView::~AccountView()
{
	BTN_REMOVE_TOUCH_EVENTLISTENER(AccountView, fanHuiBtn, 10501);

	//BTN_REMOVE_TOUCH_EVENTLISTENER(AccountView, Image_1, 10501);

	if (DATA->bGameCate == DataManager::E_GameCateNormal)
	{
		BTN_REMOVE_TOUCH_EVENTLISTENER(AccountView, continueBtn, 10502);
	}
	else if (DATA->bGameCate == DataManager::E_GameCateMatch)
	{
		BTN_REMOVE_TOUCH_EVENTLISTENER(AccountView, nextMatchBtn, 10503);
	}

	delete rootNode;
	rootNode = NULL;
}

void AccountView::initView()
{
	failActionNode = rootNode->getChildByName("failActionNode");
	failActionNode->setVisible(false);

	failAction = CSLoader::createTimeline("failAction.csb");
	rootNode->runAction(failAction);

	winParticle = dynamic_cast<ParticleSystemQuad*>(rootNode->getChildByName("winParticle"));
	winParticle->setVisible(false);
	
	glodParticle = dynamic_cast<ParticleSystemQuad*>(rootNode->getChildByName("glodParticle"));
	glodParticle->setVisible(false);
}

void AccountView::playAccountAction(bool isSuccess)
{
	if (!isSuccess)
	{
		failActionNode->setVisible(true);
		failAction->gotoFrameAndPlay(0, 110, false);
	}
	else
	{
		winParticle->setVisible(true);
		glodParticle->setVisible(true);
	}
}


void AccountView::showSuccessAction(float dt)
{
	glodParticle->setVisible(true);
}
