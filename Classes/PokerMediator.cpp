#include "PokerMediator.h"
#include "SGTools.h"
#include "ViewManager.h"
PokerMediator::PokerMediator(int id, bool isOutPoker, int desk, int DuiNum, int ZhangNum, int DuiAllNum, int ZhangAllNum, int isChangePos,bool isGongP)
{
	isPlayerOutPoker = isOutPoker;
	deskPos = desk;
	Dui = DuiNum;
	Zhang = ZhangNum;
	DuiAll = DuiAllNum;
	ZhangAll = ZhangAllNum;

	poker.pokerNum = PokerLogic::getPokerNum(id);
	poker.pokerNum2 = PokerLogic::getPokerNum2(id);
	poker.pokerHuaSe = PokerLogic::getPokerHuaSe(id);
	poker.pokerID = id;
	poker.pokerID2 = ZhangNum;
	poker.isChangePosition = isChangePos;
	poker.isRemoveView = false;
	poker.isGongPai = isGongP;
	GameDataModel *gameDataModel = (GameDataModel*)getModel(GameDataModel::NAME);



	//
	if (!isPlayerOutPoker)
	{
		poker.isSelected = false;
		poker.canSelect = true;
		poker.deskID = -1;



		//设置牌的位置
		Size size = Director::getInstance()->getVisibleSize();
		if (pkWidth * DuiAll > 600 * size.width / 960)
		{
			pkJianJu = pkWidth - (pkWidth * DuiAll - 600 * size.width / 960) / (DuiAll - 1);
		}
		else  //Dui = 6开始 6.89
		{
			pkJianJu = pkWidth;
		}
		posx = (size.width - 360 * size.width / 960 - (DuiAll - 1) * pkJianJu - pkWidth) / 2 + 360 * size.width / 960 + (Dui - 1)*pkJianJu;
		posy = 100 + 30 * (ZhangAll - Zhang - 1);
		

		if (Zhang != ZhangAll - 1) //非最下边一张，被遮挡了
		{
			if (Dui != DuiAll - 1)//非最后一堆被挡住了  (posx, posy + pkHeight - 30, pkJianju, 30)
			{
				poker.rect.origin.x = posx - pkWidth * 0.5;
				poker.rect.origin.y = posy - pkWidth * 0.5 + pkHeight - 30;
				poker.rect.size.width = pkJianJu;
				poker.rect.size.height = 30;
			} 
			else  //最后一堆， 未被遮挡 //(posx, posy + pkHeight - 30, pkWidth, 30)
			{
				poker.rect.origin.x = posx - pkWidth * 0.5;
				poker.rect.origin.y = posy - pkWidth * 0.5 + pkHeight - 30;
				poker.rect.size.width = pkWidth;
				poker.rect.size.height = 30;
			}
		} 
		else //最下边一张，未被遮挡
		{
			if (Dui != DuiAll - 1)// 非最后一堆  		//(posx, posy, pkJianju, pkHeight)
			{
				poker.rect.origin.x = posx - pkWidth * 0.5;
				poker.rect.origin.y = posy - pkWidth * 0.5 ;
				poker.rect.size.width = pkJianJu;
				poker.rect.size.height = pkHeight;
			} 
			else   //最后一堆， 未被遮挡 //(posx, posy, pkwidth, pkHeight)
			{
				poker.rect.origin.x = posx - pkWidth * 0.5;
				poker.rect.origin.y = posy - pkWidth * 0.5;
				poker.rect.size.width = pkWidth;
				poker.rect.size.height = pkHeight;
			}
		}

		//添加到我的手牌
		gameDataModel->player[0].pokerArr.push_back(&poker);
	}
	else
	{
		poker.isSelected = false;
		poker.canSelect = false;
		poker.deskID = deskPos;
		//添加到对应玩家本轮出的牌
		gameDataModel->player[deskPos].outPokerArr.push_back(&poker);
		//添加到对应玩家本局出的牌
		gameDataModel->player[deskPos].allOutPokerArrID.push_back(&(poker.pokerID));
	}
}


void test()
{
	float posx, posy;   //正张牌的左下角，未被遮挡时
	vector<vector<int>> pokerIDDui;

	//
	int duiSize = pokerIDDui.size();
	int zhangSize;
	for (DWORD i = 0; i < duiSize - 1; i++)   //非最右边一堆
	{
		zhangSize = pokerIDDui.at(i).size();
		for (DWORD j = 0; j < zhangSize - 1; j++)
		{
			pokerIDDui.at(i).at(j);    //非最下边一张
			//(posx, posy + pkHeight - 30, pkJianju, 30)
		}
		pokerIDDui.at(i).at(zhangSize - 1);   //最下边一张(未被遮挡的那一排)
		//(posx, posy, pkJianju, pkHeight)
	}

	//最右边一堆
	zhangSize = pokerIDDui.at(duiSize - 1).size();
	for (DWORD j = 0; j < zhangSize - 1; j++)  //非最下边一张（位置）
	{
		pokerIDDui.at(duiSize - 1).at(j);
		//(posx, posy + pkHeight - 30, pkWidth, 30)
	}
	pokerIDDui.at(duiSize - 1).at(zhangSize - 1); //最下边一张
	//(posx, posy, pkwidth, pkHeight)


}
PokerMediator::~PokerMediator()
{

}

/*
开始执行函数
*/
void PokerMediator::OnRegister()
{
	pokerView = (PokerView*)getView();
	pokerView->initView(poker.isGongPai, Dui);
	//玩家手牌
	if (!isPlayerOutPoker)
	{
 		pokerView->rootNode->setPosition(Vec2(posx, posy));
	}

	//玩家出的牌
	else
	{

		Size size = Director::getInstance()->getVisibleSize();
		int num = 0;
		GameDataModel *gameDataModel  = ((GameDataModel*)getModel(GameDataModel::NAME));
		PlayerVO  playerV1;
		switch (deskPos)
		{
			//本玩家
			case 0:
				num = gameDataModel->player[0].outPokerArr.size();
				getView()->rootNode->setPosition(Vec2(size.width / 2 - (4 / 2 * pkJianJu2) + (num - 1)*pkJianJu2, 200));
				getView()->rootNode->setScale(0.5);
				break;

				//左边的玩家
			case 1:
				//logP
				playerV1 = gameDataModel->player[1];
				//logP
				num = playerV1.outPokerArr.size();
				//logP
				getView()->rootNode->setPosition(Vec2(size.width / 4 - (4 / 2 * pkJianJu2) + (num - 1)*pkJianJu2, size.height * 2 / 5));
				getView()->rootNode->setScale(0.5);
				break;

				//对面的玩家
			case 2:
					num = gameDataModel->player[2].outPokerArr.size();
					getView()->rootNode->setPosition(Vec2(size.width / 2 - (4 / 2 * pkJianJu2) + (num - 1)*pkJianJu2, 280));
				getView()->rootNode->setScale(0.5);
				break;
			//右边的玩家
			case 3:
				num = gameDataModel->player[3].outPokerArr.size();
				getView()->rootNode->setPosition(Vec2(size.width * 3 / 4 - (4 / 2 * pkJianJu2) + (num - 1)*pkJianJu2, size.height * 2 / 5));
				getView()->rootNode->setScale(0.5);
				break;


		}
	}
}

/*
结束执行函数
*/
void PokerMediator::onRemove()
{
	//移除触摸响应
	Director::getInstance()->getEventDispatcher()->removeEventListenersForTarget(getView()->rootNode);
}

/*
事件响应函数
*/
void PokerMediator::onEvent(int i, void* data)
{
	pokeridData Data;
	int opacity;
	//
	switch (i)
	{
		//
		case EventType::POKER_GONG_PAI_STATE:
			Data = *(pokeridData*)(data);
			if (Data.pokerID == this->poker.pokerID && Data.pokerID2 == this->poker.pokerID2 && !isPlayerOutPoker && !poker.isRemoveView)
			{
				poker.isGongPai = true;
				pokerView = (PokerView*)getView();
				pokerView->changeToGongPai();
			}
			break;

		//需要改变手牌的选中状态
		case EventType::CHANGE_POKER_STATE:

			Data = *(pokeridData*)(data);
			if (Data.pokerID == this->poker.pokerID && Data.pokerID2 == this->poker.pokerID2 && !isPlayerOutPoker && !poker.isRemoveView)
			{
				if (this->poker.isSelected)
					SelectPkSuoTou();
				else
					SelectPkLuTou();
			}
			break;

		//滑动选牌
		case EventType::SELECT_POKER_MOVE:
			Data = *(pokeridData*)(data);
			if (Data.pokerID == this->poker.pokerID && Data.pokerID2 == this->poker.pokerID2 && !isPlayerOutPoker && !poker.isRemoveView)
			{
				if (this->poker.isSelected)
				{
					break;
				}
				else
				{
					SelectPkLuTou();
				}
				
			}
			break;

		//在手牌中移除这张牌
		case EventType::REMOVE_POKER:
			Data = *(pokeridData*)(data);
			if (Data.pokerID == this->poker.pokerID && Data.pokerID2 == this->poker.pokerID2 && !isPlayerOutPoker && !poker.isRemoveView)
			{
				removeView(this);
			}
			break;

		//移除牌的显示
		case EventType::REMOVE_POKER_VIEW:
			Data = *(pokeridData*)(data);
			if (Data.pokerID == this->poker.pokerID && Data.pokerID2 == this->poker.pokerID2 && !isPlayerOutPoker && !poker.isRemoveView)
			{
				getLayer()->removeChild(getView());
				poker.isRemoveView = true;
			}
			break;
		//改变手牌的位置
		case EventType::CHANGE_POKER_POSITION:
			Data = *(pokeridData*)(data);
			if (Data.pokerID == this->poker.pokerID && Data.pokerID2 == this->poker.pokerID2 && !isPlayerOutPoker && !poker.isRemoveView)
			{
				changePokerPosition();
			}
			break;
		//清除出的牌的显示
		case EventType::REMOVE_OUT_POKER:
			Data = *(pokeridData*)(data);
			if (Data.pokerID == this->poker.pokerID && this->poker.deskID == Data.deskID && isPlayerOutPoker && !poker.isRemoveView)
			{
				//removeView(this);
				getLayer()->removeChild(getView());
				poker.isRemoveView = true;
			}
			break;
		case EventType::SET_POKER_OPACITY:
			opacity = *(int*)(data);
			if (!isPlayerOutPoker && !poker.isRemoveView)
			{
				getView()->rootNode->setOpacity(opacity);
			}
			break;
		case EventType::GAME_OVER:
		case EventType::BACK_TO_HALL:
			removeView(this);
			break;
		default:
			break;
	}
}

/*
	设置牌的显示层
*/
Layer* PokerMediator::getLayer()
{
	if (isPlayerOutPoker)
		return VIEW->outPokerLayer;
	else
		return VIEW->myPokerLayer;
}


//
void PokerMediator::SelectPkLuTou(){
	this->poker.isSelected = true;
	//getView()->rootNode->setPosition(Vec2(getView()->rootNode->getPositionX(), getView()->rootNode->getPositionY() + 10));
	//蒙上阴影
	getView()->rootNode->setColor(Color3B(128, 128, 128));

	//添加到选的要出的牌中
	GameDataModel* gameDataModel = ((GameDataModel*)getModel(GameDataModel::NAME));
	gameDataModel->player[0].selectedPokerArr.push_back(&(this->poker));

	//
	blueSkyDispatchEvent(10624);
}

//
void PokerMediator::SelectPkSuoTou(){
	this->poker.isSelected = false;
	getView()->rootNode->setColor(Color3B(255, 255, 255));

	//在选的要出的牌中移除之
	GameDataModel* gameDataModel = ((GameDataModel*)getModel(GameDataModel::NAME));
	gameDataModel->removeMySelectedPokerArr(&(this->poker));

	//
	if (gameDataModel->player[0].selectedPokerArr.size() == 0)
	{
		blueSkyDispatchEvent(10623);
	}
}

//调整牌的位置
void PokerMediator::changePokerPosition()
{

	vector<vector<PokerVO*>> pokerDui = PokerLogic::reFenPokerArr(((GameDataModel*)getModel(GameDataModel::NAME))->player[0].pokerArr);

	DuiAll = pokerDui.size();
	for (int i = 0; i < DuiAll; i++)
	{
		for (DWORD j = 0; j < pokerDui.at(i).size(); j++)
		{
			if (this->poker.pokerID == pokerDui.at(i).at(j)->pokerID && this->poker.pokerID2 == pokerDui.at(i).at(j)->pokerID2)
			{
				Dui = i;
				Zhang = j;
				ZhangAll = pokerDui.at(i).size();

				break;
			}
		}
	}
	Size size = Director::getInstance()->getVisibleSize();
	if (pkWidth * DuiAll > 600 * size.width / 960)
	{
		pkJianJu = pkWidth - (pkWidth * DuiAll - 600 * size.width / 960) / (DuiAll - 1);
	}
	else
	{
		pkJianJu = pkWidth;
	}
// 	float posX = (size.width - 360 * size.width / 960 - (DuiAll - 1) * pkJianJu - pkWidth) / 2 + 360 * size.width / 960 + (Dui - 1)*pkJianJu;
// 	float posY = 100 + 30 * (ZhangAll - Zhang - 1);
	posx = (size.width - 360 * size.width / 960 - (DuiAll - 1) * pkJianJu - pkWidth) / 2 + 360 * size.width / 960 + (Dui - 1)*pkJianJu;
	posy = 100 + 30 * (ZhangAll - Zhang - 1);
	getView()->rootNode->setPosition(Vec2(posx, posy));


	//改变触摸区
	if (Zhang != ZhangAll - 1) //非最下边一张，被遮挡了
	{
		if (Dui != DuiAll - 1)//非最后一堆被挡住了  (posx, posy + pkHeight - 30, pkJianju, 30)
		{
			pokerDui.at(Dui).at(Zhang)->rect.origin.x = posx - pkWidth * 0.5;
			pokerDui.at(Dui).at(Zhang)->rect.origin.y = posy - pkWidth * 0.5 + pkHeight - 30;
			pokerDui.at(Dui).at(Zhang)->rect.size.width = pkJianJu;
			pokerDui.at(Dui).at(Zhang)->rect.size.height = 30;
		}
		else  //最后一堆， 未被遮挡 //(posx, posy + pkHeight - 30, pkWidth, 30)
		{
			pokerDui.at(Dui).at(Zhang)->rect.origin.x = posx - pkWidth * 0.5;
			pokerDui.at(Dui).at(Zhang)->rect.origin.y = posy - pkWidth * 0.5 + pkHeight - 30;
			pokerDui.at(Dui).at(Zhang)->rect.size.width = pkWidth;
			pokerDui.at(Dui).at(Zhang)->rect.size.height = 30;
		}
	}
	else //最下边一张，未被遮挡
	{
		if (Dui != DuiAll - 1)// 非最后一堆  		//(posx, posy, pkJianju, pkHeight)
		{
			pokerDui.at(Dui).at(Zhang)->rect.origin.x = posx - pkWidth * 0.5;
			pokerDui.at(Dui).at(Zhang)->rect.origin.y = posy - pkWidth * 0.5;
			pokerDui.at(Dui).at(Zhang)->rect.size.width = pkJianJu;
			pokerDui.at(Dui).at(Zhang)->rect.size.height = pkHeight;
		}
		else   //最后一堆， 未被遮挡 //(posx, posy, pkwidth, pkHeight)
		{
			pokerDui.at(Dui).at(Zhang)->rect.origin.x = posx - pkWidth * 0.5;
			pokerDui.at(Dui).at(Zhang)->rect.origin.y = posy - pkWidth * 0.5;
			pokerDui.at(Dui).at(Zhang)->rect.size.width = pkWidth;
			pokerDui.at(Dui).at(Zhang)->rect.size.height = pkHeight;
		}
	}

}
