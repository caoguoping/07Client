#include "LobbyMediator.h"
#include "DataManager.h"
#include "CallCppHelper.h"
#include "ViewManager.h"

LobbyMediator::LobbyMediator()
{

}

LobbyMediator::~LobbyMediator()
{

}

/**
��ʼִ�к���
*/
void LobbyMediator::OnRegister()
{
    logV("LobbyMediator!");
	lobbyView = (LobbyView*)getView();
	lobbyView->initView();

	//��ʾ�û����
	lobbyView->showGold(DATA->myBaseData.lUserScore);
	//
	lobbyView->txtDiamond->setString(Tools::parseInt2String(DATA->myBaseData.rmb));

	//��ʾͷ��
	lobbyView->showHeadImage(DATA->myBaseData.wFaceID);

	//��ʾ����
	lobbyView->txtPlayerName->setString(DATA->myBaseData.szNickName);

	lobbyView->txtId->setString(CallCppHelper::getInstance()->mUid);


	//�������Ƴ�
	PlayPokerMediator*   pMediator = new PlayPokerMediator();
	PlayPokerView*    pView = new PlayPokerView();
	DATA->playPokerMediator = pMediator;
	DATA->playPokerView = pView;
	creatView(pView, pMediator);
	//removeView(pMediator, true);
	pView->hideLayer();
	pMediator->hideLayer();

}

/**
��������ִ�к���
*/
void LobbyMediator::onRemove()
{

}

/*
�¼���Ӧ����
*/
void LobbyMediator::onEvent(int i, void* data)
{
	int index = -1;
//	CMD_GP_User_Gambling gamblingData;
	;
	OnDesk onDeskResult;
	switch (i)
	{
		case EventType::RE_LOGIN:
			removeView(this);
			break;
		case EventType::INSURESUCCESS:
			//if (canShowMessage)
			{
				lobbyView->showGold(DATA->myBaseData.lUserScore);
			}
			break;
		case EventType::TASK_REWORD:
		{
			DATA->myBaseData.lUserScore += 3000;
			lobbyView->showGold(DATA->myBaseData.lUserScore);
		}
			break;

		case 11905:
			canShowMessage = !canShowMessage;
			break;

		case EventType::ON_DESK:
			onDeskResult = *(OnDesk*)data;
			if (onDeskResult.dwUserID == DATA->myBaseData.dwUserID && 
				(onDeskResult.cbUserStatus == US_SIT || onDeskResult.cbUserStatus == US_READY))
			{
				removeView(this, true);
			}
			break;
		case EventType::BACK_TO_HALL:
			lobbyView->refreshView();
			PLayMUSIC(BG_MUSIC)
			break;
		default:
			break;

	}
}

Layer* LobbyMediator::getLayer()
{
	return VIEW->mainLayer;
}

