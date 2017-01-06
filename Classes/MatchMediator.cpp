#include "MatchMediator.h"
#include "SGTools.h"
#include "BlueSky.h"
#include "UILayerService.h"
#include "DataManager.h"
#include "ViewManager.h"

MatchMediator::MatchMediator()
{

}

MatchMediator::~MatchMediator()
{

}

/**
开始执行函数
*/
void MatchMediator::OnRegister()
{
	//
	matchView = (MatchView*)getView();
	matchView->initView();

	Size size = Director::getInstance()->getVisibleSize();
	getView()->rootNode->setPosition(size.width/2,size.height/2);



}

void MatchMediator::onRemove()
{

}

Layer* MatchMediator::getLayer()
{
	return VIEW->uiLayer;
}

void MatchMediator::onEvent(int i, void* data)
{
	;
	OnDesk onDeskResult;
	switch (i)
	{
		case 16000:
		{
			removeView(this);
			break;
		}
		case EventType::MATCH_NUM:
		{
			matchView->updateFastView();
			break;
		}

		case EventType::GAMESERVER_LOGIN_SUCSS:
		{
			if (DATA->bGameCate == DataManager::E_GameCateMatch )
			{
				logV("cocos2d-x join match");
				matchView->createFastMatch();
			}
			 break;
		}

		case EventType::BACK_TO_HALL:
			logV("match back to hall gos ");
			matchView->removeAllChildrenWithCleanup(true);
			removeView(this);
			break;

		case EventType::MATCH_STATES:
		{
			if (GAME_STATE_SIGNUP ==  *(BYTE*)data)
			{
				logV("cocos2d-x clickCansai");
				matchView->btnCansai->setVisible(false);
				matchView->btnTuisai->setVisible(true);
			} 
			else if (GAME_STATE_QUIT == *(BYTE*)data)
			{
				logV("cocos2d-x clickTuisai");
				matchView->btnCansai->setVisible(true);
				matchView->btnTuisai->setVisible(false);
			}
					
		}
		case EventType::ON_DESK:
			onDeskResult = *(OnDesk*)data;
			if (onDeskResult.dwUserID == DATA->myBaseData.dwUserID &&
				(onDeskResult.cbUserStatus == US_SIT || onDeskResult.cbUserStatus == US_READY))
			{
				removeView(this);
			}
			break;
		default:
			break;
	}
}

