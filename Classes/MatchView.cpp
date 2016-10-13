#include "MatchView.h"
#include "SGTools.h"
#include "EventType.h"
#include "PokerGameModel.h"
#include "TCPSocketService.h"
#include "SendDataService.h"
#include "DataManager.h"
#include "ConnectGameServiceCommand.h"
#include "LobbyMediator.h"
#include "LobbyView.h"
#include "SetMediator.h"
#include "SetView.h"

MatchView::MatchView()
{


}
MatchView::~MatchView()
{
	delete rootNode;
	rootNode = NULL;
}

void MatchView::initView()
{
	rootNode = CSLoader::createNode("matchMain.csb");
	addChild(rootNode);
	//rootNode->setScale(0.1f, 0.1f);

	//rootNode->runAction(Sequence::create(ScaleTo::create(0.2f, 1.1f), ScaleTo::create(0.1f, 1.0f), nullptr));

	//外面的关闭
	BTN_ADD_TOUCH_EVENTLISTENER(Button, MatchView, closeBtn, 16000, "Button_close", NULL);   
	BTN_ADD_TOUCH_EVENTLISTENER(ImageView, MatchView, Image_bg, 16000, "Image_bg", NULL);

	ScrollView* scrow;
	UIGet_ScrollView("ScrollView_1", rootNode, scrow)
		ImageView*  img[3];

	UIGet_ImageView("Image_1", scrow, img[0])
		UIGet_ImageView("Image_2", scrow, img[1])
		UIGet_ImageView("Image_3", scrow, img[2])
	for (int i = 0; i < 3; i ++)
	{
		UIGet_Button("Button_join", img[i], btnGoto[i])
			btnGoto[i]->setTag(i);
		UIClick(btnGoto[i], MatchView::gotoMatch)
	}

}

void MatchView::clickCansai(Ref* psender)
{

	//报名
	unsigned long dwUserID = DATA->myBaseData.dwUserID;
	((SendDataService *)getService(SendDataService::NAME))->sendSignUp(dwUserID);

	DATA->bMatchOver = 0;
}

void MatchView::clickTuisai(Ref* psender)
{

	//退赛
	unsigned long dwUserID = DATA->myBaseData.dwUserID;
	((SendDataService *)getService(SendDataService::NAME))->sendExitSignUp(dwUserID);

}

void MatchView::clickBtnCloseFast(Ref* pSender)
{
// 	发送离开桌子消息
// 	PlayerInDeskModel *playerInDeskModel = ((PlayerInDeskModel*)getModel(PlayerInDeskModel::NAME));
// 	int myChair = 0xFFFF;
// 	int myTable = 0xFFFF;
// 	((SendDataService*)getService(SendDataService::NAME))->sendLeaveTable(myTable, myChair, true);

		logV("!!!!!match click back!!!!!!");
		matchFastNode->removeFromParentAndCleanup(true);
		((TCPSocketService *)getService(TCPSocketService::GAME))->SendData(2000, 2000, NULL, 0);  //心跳

		//关闭游戏服务器SOCKET
		((TCPSocketService*)getService(TCPSocketService::GAME))->closeMySocket();
		//停掉网络主动监测与心跳
		if (getcontainer()->isScheduled(schedule_selector(ConnectGameServiceCommand::checkNetWorks)))
		{
			getcontainer()->unschedule(schedule_selector(ConnectGameServiceCommand::checkNetWorks));
		}

		if (getcontainer()->isScheduled(schedule_selector(ConnectGameServiceCommand::heartPacket)))
		{
			getcontainer()->unschedule(schedule_selector(ConnectGameServiceCommand::heartPacket));
		}
		creatView(new LobbyView(), new LobbyMediator());
		blueSkyDispatchEvent(EventType::BACK_TO_HALL);  //cgp test


}

//12人快速赛
void MatchView::initFastView()
{
	Button*  closeBtn;
	UIGet_Button("Button_close", matchFastNode, closeBtn)
		UIClick(closeBtn, MatchView::clickBtnCloseFast)


	UIGet_Button("Button_tuisai", matchFastNode, btnTuisai)
		UIGet_Button("Button_go", matchFastNode, btnCansai)
		btnCansai->setVisible(true);
		btnTuisai->setVisible(false);
		UIClick(btnCansai, MatchView::clickCansai)
			UIClick(btnTuisai, MatchView::clickTuisai)

			//top
			Node*  topNode;
		UIGet_Node("FileNode_top", matchFastNode, topNode)
			UIGet_Text("Text_gold", topNode, txtGold)
			UIGet_Text("Text_diamond", topNode, txtDiamond)
			txtGold->setString(Tools::parseInt2String(DATA->myBaseData.lUserScore));
		txtDiamond->setString(Tools::parseInt2String(DATA->myBaseData.rmb));
		Button   *btnAddGold, *btnAddDiamond, *btnSetting;
		UIGet_Button("Button_addGold", topNode, btnAddGold)
			UIGet_Button("Button_addDiamond", topNode, btnAddDiamond)
			UIGet_Button("Button_setting", topNode, btnSetting)
			btnAddGold->addClickEventListener([&](Ref* psender)
		{
			SimpleAudioEngine::getInstance()->playEffect("sounds/game_button_click.mp3");
			creatView(new ShopView(1), new ShopMediator());
		}
		);
		btnAddDiamond->addClickEventListener([&](Ref* psender)
		{
			SimpleAudioEngine::getInstance()->playEffect("sounds/game_button_click.mp3");
			creatView(new ShopView(0), new ShopMediator());
		}
		);
		btnSetting->addClickEventListener([&](Ref* psender)
		{
			SimpleAudioEngine::getInstance()->playEffect("sounds/game_button_click.mp3");
			creatView(new SetView(), new SetMediator());
		}
		);


		Button*  btnMyRecord;
		Text*  txtConstChar;
	UIGet_Button("Button_myRecord", matchFastNode, btnMyRecord)
		UIGet_Text("Text_nowPeaple", matchFastNode, txtNowPeople)
		UIGet_Text("Text_needPeople", matchFastNode, txtNeedPeople)
		UIGet_Text("Text_14", matchFastNode, txtConstChar)

		ImageView   *imgRingBack, *imgRingUP;

		
		UIGet_ImageView("Image_ringback", matchFastNode, imgRingBack)
		UIGet_ImageView("Image_ringUp", matchFastNode, imgRingUP)


		Sprite*   spRing = Sprite::create("player-number_middle.png");
	timerPeople = ProgressTimer::create(spRing);
	timerPeople->setPercentage(80.0f);
	timerPeople->setPosition(Vec2(112, 112));
	imgRingBack->addChild(timerPeople);
	imgRingUP->setLocalZOrder(timerPeople->getLocalZOrder() + 1);
	
	txtConstChar->setLocalZOrder(imgRingUP->getLocalZOrder() + 1);
	txtNowPeople->setLocalZOrder(imgRingUP->getLocalZOrder() + 1);
	txtNeedPeople->setLocalZOrder(imgRingUP->getLocalZOrder() + 1);

}

//新手免费赛
void MatchView::initNewView()
{

}

void MatchView::initFeeView()
{

}

void MatchView::createFastMatch()
{
	matchFastNode = CSLoader::createNode("matchFast.csb");
	rootNode->addChild(matchFastNode);
	initFastView();
}

void MatchView::gotoMatch(Ref* psender)
{

	Button*  btn = static_cast<Button*>(psender);
	int tags = btn->getTag();
	if (tags == 0)
	{
		DATA->bMatchItem = 0;
		blueSkyDispatchEvent(EventType::CONNECT_GAME_SERVICE, new int(3));  // 暂时的
	}
	else if (tags == 1)
	{
// 		DATA->bMatchItem = 1;
// 		blueSkyDispatchEvent(EventType::CONNECT_GAME_SERVICE, new int(3));  // 暂时的
	}

}

void MatchView::updateFastView()
{
	PokerGameModel* pokerGameModel = ((PokerGameModel*)getModel(PokerGameModel::NAME));
	DWORD dwWaitPeople = pokerGameModel->num_info.dwWaitting;
	DWORD dwTotalPeople = pokerGameModel->num_info.dwTotal;
	txtNowPeople->setString(Tools::parseInt2String(dwWaitPeople));
	txtNeedPeople->setString(Tools::parseInt2String(dwTotalPeople));
	timerPeople->setPercentage(dwWaitPeople * 100 / dwTotalPeople);
}
