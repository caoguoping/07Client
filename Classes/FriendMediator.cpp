#include "FriendMediator.h"

#include "UILayerService.h"
#include "EventType.h"
#include "head.h"
#include "ViewManager.h"

FriendMediator::FriendMediator()
{

}

FriendMediator::~FriendMediator()
{
	delete getView();
	setView(NULL);
}


void FriendMediator::OnRegister()
{
	pFriendView =(FriendView*)getView();
	Size size = Director::getInstance()->getVisibleSize();
	getView()->rootNode->setPosition(size.width / 2, size.height / 2);
}


void FriendMediator::onRemove()
{

}

void FriendMediator::onEvent(int i, void* data)
{
	CMD_GP_S_SEARCH_USER*  pSearch = (CMD_GP_S_SEARCH_USER*)data;
	switch (i)
	{
	case EventType::BACK_TO_HALL:
	case 10701:
		removeView(this);
		break;

	case FRIEND_LIST:
		pFriendView->showFriends();
		break;

	case FRIEND_SHUREN:


		if (VIEW->nowViewTag == ViewManager::eViewFriend 
			&& pFriendView->currentTitle == FriendView::E_familiar )
		{
			pFriendView->showShuRen();
		}
		break;

	case FRIEND_OPT_ME:
		pFriendView->handleFriendOptMe(data);

		break;

	case FRIEND_OPT_HIM:
		pFriendView->handleFriendOptHim(data);

		break;

	case FRIEND_SEARCH:

		pFriendView->dwSearchUserId = pSearch->dwUserID;

		pFriendView->showSearchResult(pSearch->wFaceID, pSearch->szNickName);

		break;
	}
}

Layer* FriendMediator::getLayer()
{
	return ((UILayerService*)getService(UILayerService::NAME))->uiLayer;
}

